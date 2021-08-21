#include "PersonalCabinetForm.h"

System::Void Prog::PersonalCabinetForm::setupData() { 
	std::string path = "";
	ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.txt", path);
	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		MessageBox::Show("Ошибка открытия файла для чтения данных о пользователе!", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		toForm = true;
		this->Close(); // Закрытие текущей формы.
		this->mainMenu->Show(); // Открытие созданной формы.
	}
	else {
		Users user;
		if (currentFile >> &user) { // Если пользователь читается, то выводим все данные о пользователе
			currentFile.close();
			String^ str = ConvertSTDStringToString(user.surnameNP);
			this->labelInfoSurnameNP->Text = str;
			this->labelSurnameNP->Text += str;
			str = ConvertSTDStringToString(user.surname);
			this->labelSurname->Text += str;
			str = ConvertSTDStringToString(user.name);
			this->labelName->Text += str;
			str = ConvertSTDStringToString(user.prozv);
			this->labelProzv->Text += str;
			this->labelBirthday->Text += user.birthday.day + "." + user.birthday.month + "." + user.birthday.year;
			str = ConvertSTDStringToString(user.password);
			this->labelPassword->Text += str;
		}
		else { // Иначе закрываем форму и выдаем ошибку
			MessageBox::Show("Ошибка чтения данных о пользователе!", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			toForm = true;
			this->Close(); // Закрытие текущей формы.
			this->mainMenu->Show(); // Открытие созданной формы.
			currentFile.close();
		}
	}
}

System::Void Prog::PersonalCabinetForm::выйтиВГлавноеМенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toForm = true;
	this->Close(); // Закрытие текущей формы.
	this->mainMenu->Show(); // Открытие созданной формы.
}

System::Void Prog::PersonalCabinetForm::выходИзПрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		Application::Exit();
}

System::Void Prog::PersonalCabinetForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Данная программа создана для поддержания порядка очереди.\n\nАвтор программы:\t(c) Бриль А.Э., Т-893", "О программе", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::PersonalCabinetForm::buttonGetAllRecords_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string path;
	ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);

	array<String^>^ fileNames = System::IO::Directory::GetFiles(Application::StartupPath + "\\queues");
	System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
	strings->Append("Ваши записи к врачам:");
	strings->AppendLine();
	for (size_t i = 0; i < fileNames->Length; i++) { // Идем по всем файлам

		ConvertStringToSTDString(fileNames[i], path);

		if (fileNames[i] == Application::StartupPath + "\\queues\\currentQueue.txt") // Если файл является текущей очередью, то пропускаем (дабы не было двойных отображений)
			continue;

		std::ifstream currentFile(path, std::ios::in);
		if (!currentFile) {
			continue;
		}
		else {
			MyQueue<queueData> que;
			if (currentFile >> que) { // Если очередь читается
				currentFile.close();

				Node<queueData>* toSet{ que.beg() };
				size_t nempty = 0;
				while (toSet) { // Ищем пользователя и добавляем информацию о записи
					std::string SurnameNP;
					ConvertStringToSTDString(this->labelInfoSurnameNP->Text, SurnameNP);
					if (toSet->data.surnameNP == SurnameNP) {
						strings->Append("---------------------");
						strings->AppendLine();
						String^ title = ConvertSTDStringToString(que.GetTitle());
						strings->AppendFormat("Врач: {0}\nДата приема: {1}.{2}.{3}\nНомер в очереди: {4}\nВремя записи: {5}:{6}\nФайл очереди: {7}", title, que.Day(), que.Month(), que.Year(), toSet->data.ownNumber, toSet->data.time.hours, toSet->data.time.minutes, System::IO::Path::GetFileName(fileNames[i]));
						strings->AppendLine();
					}
					toSet = toSet->next;
				}

			}
			else {
				currentFile.close();
				continue;
			}
		}

	}
	MessageBox::Show(strings->ToString(), "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information); // Выводим всю информацию
	return;
}

System::Void Prog::PersonalCabinetForm::buttonGetRecord_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;

	openFileDialog->InitialDirectory = Application::StartupPath;
	openFileDialog->Filter = "txt files (*.txt)|*.txt";
	openFileDialog->FilterIndex = 1;
	openFileDialog->RestoreDirectory = true;

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) // Открываем диалоговое окно выбора и проверяем нажата ли ОК 
	{
		std::string path;
		ConvertStringToSTDString(openFileDialog->FileName, path);

		System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
		strings->Append("Ваши записи к врачам:");
		strings->AppendLine();


		std::ifstream currentFile(path, std::ios::in);
		if (!currentFile) {
			MessageBox::Show("Невозможно открыть выбранный вами файл!", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		else {
			MyQueue<queueData> que;
			if (currentFile >> que) { // Читаем очередь из выбранного файла
				currentFile.close();

				Node<queueData>* toSet{ que.beg() };
				size_t nempty = 0;
				while (toSet) { // Ищем все записи нужного пользователя и добавляем о них информацию
					std::string SurnameNP;
					ConvertStringToSTDString(this->labelInfoSurnameNP->Text, SurnameNP);
					if (toSet->data.surnameNP == SurnameNP) {
						strings->Append("---------------------");
						strings->AppendLine();
						String^ title = ConvertSTDStringToString(que.GetTitle());
						strings->AppendFormat("Врач: {0}\nДата приема: {1}.{2}.{3}\nНомер в очереди: {4}\nВремя записи: {5}:{6}\nФайл очереди: {7}", title, que.Day(), que.Month(), que.Year(), toSet->data.ownNumber, toSet->data.time.hours, toSet->data.time.minutes, openFileDialog->FileName);
						strings->AppendLine();
					}
					toSet = toSet->next;
				}

			}
			else {
				MessageBox::Show("Невозможно прочитать очередь из выбранного файла!", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
		}

		MessageBox::Show(strings->ToString(), "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information); // Выводим информацию
		return;

	}
}

System::Void Prog::PersonalCabinetForm::PersonalCabinetForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
			Application::Exit();
		else
			e->Cancel = true;
}

System::Void Prog::PersonalCabinetForm::PersonalCabinetForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(7); // Создаем форму и передаем номер формы.
	form->Show();
}
