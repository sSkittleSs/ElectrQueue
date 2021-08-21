#include "MainMenuForm.h" // Подключаем форму главного меню

using namespace Prog;

[STAThreadAttribute] //Атрибут однопоточного контейнера (STA), для возможности вызова OLE

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// Статические методы (ниже), поскольку вызывается напрямую из класса, а не объекта класса. 
	Application::EnableVisualStyles(); // Устанавливает доуступность визуальных стилей и не позволяет отображать консоль.
	Application::SetCompatibleTextRenderingDefault(false); // Устанавливает единообразное отображение шрифтов текста, если примет аргумент false
	Application::Run(gcnew MainMenuForm); // Вызываем метод Run и передаем указатель на создаваемый тут же конструктором экземпляр класса MyForm (либо название формы)
	return 0;
}

System::Void Prog::MainMenuForm::выходToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) { // Запрашиваем подтверждение и выходим из программы, в случае "ОК".
	if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		Application::Exit();
}

System::Void Prog::MainMenuForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // Вывод данных о программе
	MessageBox::Show("Данная программа создана для записи в очередь в поликлинику.\n\nАвтор программы:\t(c) Бриль А.Э., Т-893", "О программе", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::MainMenuForm::buttonExit_Click(System::Object^ sender, System::EventArgs^ e) { // Запрашиваем подтверждение и выходим из программы, в случае "ОК".
	if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		Application::Exit();
}

System::Void Prog::MainMenuForm::buttonOpenQueueFile_Click(System::Object^ sender, System::EventArgs^ e) { // Переходим в форму открытия файлов.
	OpenQueueFileForm^ form = gcnew OpenQueueFileForm(this); // Создание формы.
	this->Hide(); // Закрытие текущей формы.
	form->Show(); // Открытие созданной формы.
}

System::Void Prog::MainMenuForm::buttonContinue_Click(System::Object^ sender, System::EventArgs^ e) { // Переходим в главную форму работы с очередью
	MainForm^ form = gcnew MainForm(this); // Создание формы.
	this->Hide(); // Закрытие текущей формы.
	form->Show(); // Открытие созданной формы.
}

System::Void Prog::MainMenuForm::buttonCreateNewQueue_Click(System::Object^ sender, System::EventArgs^ e){
	CreateNewQueueForm^ form = gcnew CreateNewQueueForm(this); // Создание формы.
	this->Hide(); // Закрытие текущей формы.
	form->Show(); // Открытие созданной формы.
}

System::Void Prog::MainMenuForm::preset(System::Object^ sender, System::EventArgs^ e) { // Проверка файла с текущей (последней, с которой работали) очередью
	std::string path; // на пустоту и предустановка кнопки "Продолжить работу" во вкл/выкл в зависимости от данных в currentFile.
	ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path); // Конвертируем System::String в std::string и помещаем в path.

	std::ifstream currentFile(path, std::ios::in); // Открываем поток для чтения.
	if (!currentFile) {
		this->buttonContinue->Enabled = false; // Если файл не смогли открыть (возможно его нет), то выключаем кнопку "Продолжить работу" 
		return; // и выходим из данной функции.
	}
	else {
		MyQueue<queueData> que;
		if (currentFile.peek() != EOF && currentFile >> que) // Иначе проверяем пуст ли данный файл
			this->buttonContinue->Enabled = true; // если файл не пуст и данные читаются успешно, включаем.
		else 
			this->buttonContinue->Enabled = false; // иначе - выключаем.
		currentFile.close(); // Закрываем поток.
		return; // Выходим из функции.
	}
}

System::Void Prog::MainMenuForm::MainMenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing)
		if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
			Application::Exit();
		else
			e->Cancel = true;
}

System::Void Prog::MainMenuForm::timerCheck_Tick(System::Object^ sender, System::EventArgs^ e) {
	preset(sender, e); // Предустанавливаем кнопку "Продолжить работу"
	bool flag = this->buttonContinue->Enabled; // Данный флаг будет отображать возможность открытия очереди из файла, а следовательно доступность кнопки "Продолжить работу".
	std::string path = "";
	ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.txt", path); // Преобразуем System::String в std::string
	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) { // Если поток не открылся, то предустанавливаем кнопки следующим образом
		this->авторизацияToolStripMenuItem->Text = "Авторизация";
		this->регистрацияToolStripMenuItem->Visible = true;
		this->входToolStripMenuItem->Visible = true;
		this->выйтиToolStripMenuItem->Visible = false;
		this->личныйКабинетToolStripMenuItem->Visible = false;
		currUser = "NONE";
		this->buttonContinue->Enabled = false;
		this->buttonOpenQueueFile->Enabled = false;
	}
	else { // Иначе
		Users user;
		if (currentFile >> &user) { // Если пользователь читается из файла
			currentFile.close(); // Закрываем поток

			currUser = gcnew System::String(user.surnameNP.c_str()); // переводим std::string в System::String

			// Далее предустанавливаем интерфейс
			if (flag)
				this->buttonContinue->Enabled = true;
			this->buttonOpenQueueFile->Enabled = true;

			this->авторизацияToolStripMenuItem->Text = "Аккаунт";
			this->входToolStripMenuItem->Visible = false;
			this->регистрацияToolStripMenuItem->Visible = false;
			this->выйтиToolStripMenuItem->Visible = true;
			this->личныйКабинетToolStripMenuItem->Visible = true;

		}
		else { // Иначе предустанавливаем интерфейс и закрываем поток.
			this->авторизацияToolStripMenuItem->Text = "Авторизация";
			this->регистрацияToolStripMenuItem->Visible = true;
			this->входToolStripMenuItem->Visible = true;
			this->выйтиToolStripMenuItem->Visible = false;
			this->личныйКабинетToolStripMenuItem->Visible = false;
			currUser = "NONE";
			this->buttonContinue->Enabled = false;
			this->buttonOpenQueueFile->Enabled = false;
			currentFile.close();
		}
	}

	this->labelCurrentUser->Text = "Текущий пользователь: " + currUser; // Выводим текущего пользователя.
	if (currUser == "NONE") // Устанавливаем цвет в зависимости от того, есть ли пользователь или его нет.
		this->labelCurrentUser->ForeColor = Color::Red;
	else 
		this->labelCurrentUser->ForeColor = Color::Green;

	if (admin) { // Настраиваем отображение и доступность кнопок в зависимости от флага прав.
		this->buttonCreateNewQueue->Enabled = true;
		this->входToolStripMenuItem2->Visible = false;
		this->выходToolStripMenuItem->Visible = true;
	}
	else {
		this->buttonCreateNewQueue->Enabled = false;
		this->входToolStripMenuItem2->Visible = true;
		this->выходToolStripMenuItem->Visible = false;
	}

}

System::Void Prog::MainMenuForm::MainMenuForm_Activated(System::Object^ sender, System::EventArgs^ e) {
	this->timerCheck->Start(); // Запускаем таймер с проверками.
}

System::Void Prog::MainMenuForm::MainMenuForm_Deactivate(System::Object^ sender, System::EventArgs^ e) {
	this->timerCheck->Stop(); // Останавливаем таймер с проверками.
}

System::Void Prog::MainMenuForm::входToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	LogInForm^ form = gcnew LogInForm(this); // Создание формы.
	this->Hide(); // Закрытие текущей формы.
	form->Show(); // Открытие созданной формы.
}

System::Void Prog::MainMenuForm::регистрацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	RegistrationForm^ form = gcnew RegistrationForm(this); // Создание формы.
	this->Hide(); // Закрытие текущей формы.
	form->Show(); // Открытие созданной формы.
}

System::Void Prog::MainMenuForm::выйтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите выйти из аккаунта?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.txt"));
}

System::Void Prog::MainMenuForm::личныйКабинетToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	PersonalCabinetForm^ form = gcnew PersonalCabinetForm(this); // Создание формы.
	this->Hide(); // Закрытие текущей формы.
	form->Show(); // Открытие созданной формы.
}

System::Void Prog::MainMenuForm::checkQueues() { // Функция проверки очередей по дате и переноса их в архив.

	array<String^>^ fileNames = System::IO::Directory::GetFiles(Application::StartupPath + "\\queues");
	System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
	for (size_t i = 0; i < fileNames->Length; i++) {

		std::string path;
		ConvertStringToSTDString(fileNames[i], path);
		std::ifstream currentFile(path, std::ios::in); // Открываем поток
		if (!currentFile) { // Если не открылся, то не проверяем и смотрим следующую
			continue;
		}
		else { // Иначе
			MyQueue<queueData> queue;
			if (currentFile >> queue) { // Если читается очередь
				currentFile.close();

				DateTime queTime, time = DateTime::Today; // Устанавливаем время очереди и текущее (даты)
				queTime = queTime.AddDays(queue.Day() - 1);
				queTime = queTime.AddMonths(queue.Month() - 1);
				queTime = queTime.AddYears(queue.Year() - 1);

				if (time > queTime) { // Если текущая дата больше, чем дата приема очереди, то переносим (копируем) данный файл в папку архив и удаляем его из этой папки.
					String^ cmd = "md " + Application::StartupPath + "\\archive";
					system(ConvertStringToChar(cmd));
					cmd = "copy /v /a \"" + fileNames[i] + "\" \"" + Application::StartupPath + "\\archive\" /a";
					system(ConvertStringToChar(cmd));
					remove(ConvertStringToChar(fileNames[i]));
				}

			}
			else { // Иначе закрываем поток и берем следующую очередь.
				currentFile.close();
				continue;
			}
		}


	}

}

System::Void Prog::MainMenuForm::входToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	bool passwordIsCorrect = false; // Данный флаг является несовершенством структуры формы проверки пароля.
	Users user1;
	DateTime date = DateTime::Today;
	user1.surnameNP = "Администратор";
	std::string pass;
	ConvertStringToSTDString(date.Day.ToString() + "queueAdmin" + date.Year.ToString(), pass);
	user1.password = pass;
	CheckPassForm^ form = gcnew CheckPassForm(this, &passwordIsCorrect, &user1); // Создаем форму для проверки пароля.

	switch (form->ShowDialog()) { // Открываем диалог проверки пароля
	case System::Windows::Forms::DialogResult::OK: {

		MessageBox::Show("Авторизация прошла успешно!\nТеперь вы можете создавать очереди.", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);

		admin = true; // Если проверка пароля прошла успешно, тогда выставляем флаг admin в положение true

		break;
	} // Иначе - в false.
	case System::Windows::Forms::DialogResult::Abort: {
		MessageBox::Show("Авторизация не была завершена, поскольку пароль был введен не верно.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		admin = false;
		break;
	}
	case System::Windows::Forms::DialogResult::Cancel: {
		form->Close();
		MessageBox::Show("Авторизация не была завершена, поскольку форма была закрыта.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		admin = false;
		break;
	}
	}
}

System::Void Prog::MainMenuForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы точно уверены, что хотите выйти из режима администратора?\nСоздание очередей станет недоступно.","Подтверждение", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
		admin = false;
}

System::Void Prog::MainMenuForm::MainMenuForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(1); // Создаем форму справки и передаем номер формы (1), дабы отобразить нужную справку в форме.
	form->Show();
}
