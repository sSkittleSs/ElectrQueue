#include "AdminMainForm.h"

System::Void Prog::AdminMainForm::pictureBoxAdd_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\addEnter.png");
	++this->pictureBoxAdd->Width;
	++this->pictureBoxAdd->Height;
}

System::Void Prog::AdminMainForm::pictureBoxAdd_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\add.png");
	--this->pictureBoxAdd->Width;
	--this->pictureBoxAdd->Height;
}

System::Void Prog::AdminMainForm::pictureBoxSub_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\subEnter.png");
	++this->pictureBoxSub->Width;
	++this->pictureBoxSub->Height;
}

System::Void Prog::AdminMainForm::pictureBoxSub_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\sub.png");
	--this->pictureBoxSub->Width;
	--this->pictureBoxSub->Height;
}

System::Void Prog::AdminMainForm::выходИзПрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		Application::Exit();
}

System::Void Prog::AdminMainForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Данная программа создана для записи в очередь в поликлинику.\n\nАвтор программы:\t(c) Бриль А.Э., Т-893", "О программе", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::AdminMainForm::выходВГлавноеМенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//MainMenuForm^ form = gcnew MainMenuForm(); // Создание формы.
	toForm = true;
	this->Close();
	this->mainMenu->Show();
}

System::Void Prog::AdminMainForm::выйтиИзПанелиАдминистрированияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите выйти из панели администрирования?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		MainForm^ form = gcnew MainForm(mainMenu); // Создание формы.
		toForm = true;
		this->Close(); // Закрытие текущей формы.
		form->Show(); // Открытие созданной формы.
	}
}

System::Void Prog::AdminMainForm::открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toForm = true;
	OpenQueueFileForm^ form = gcnew OpenQueueFileForm(mainMenu); // Создание формы.
	this->Close(); // Закрытие текущей формы.
	form->Show(); // Открытие созданной формы.
}

System::Void Prog::AdminMainForm::сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // Данный код уже закомментирован в mainForm.cpp
	std::string path;
	ConvertStringToSTDString(System::Windows::Forms::Application::StartupPath + "\\queues\\currentQueue.txt", path);

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		System::Windows::Forms::MessageBox::Show("Ошибка при открытии файла для чтения!\nСохранить очередь не удалось.", "Ошибка");
		return;
	}
	else {
		MyQueue<queueData> que;
		currentFile >> que;
		currentFile.close();

		std::ofstream queueFileMF(que.GetFileName(), std::ios::out | std::ios::trunc);
		if (!queueFileMF) {
			System::Windows::Forms::MessageBox::Show("Ошибка в момент записи очереди!\nСохранить очередь не удалось.", "Ошибка");
			return;
		}
		else {
			if (queueFileMF << que) {
				ConvertStringToSTDString(System::Windows::Forms::Application::StartupPath + "\\queues\\currentQueue.txt", path);
				std::ofstream queueFile(path, std::ios::out | std::ios::trunc);
				if (!queueFile) {
					System::Windows::Forms::MessageBox::Show("Ошибка в момент открытия файла currentQueue.txt!\nОбновить текущую очередь не удалось.", "Ошибка");
					return;
				}
				else {
					if (queueFile << que)
						System::Windows::Forms::MessageBox::Show("Очередь успешно сохранена.", "Успех");
					else
						System::Windows::Forms::MessageBox::Show("Ошибка в момент записи очереди в файл currentQueue.txt!\nСохранить очередь не удалось.", "Ошибка");
				}
			}
			else
				System::Windows::Forms::MessageBox::Show("Ошибка в момент записи очереди в файл!\nСохранить очередь не удалось.", "Ошибка");
			queueFileMF.close();
		}
	}
}

System::Void Prog::AdminMainForm::создатьНовуюОчередьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toForm = true;
	CreateNewQueueForm^ form = gcnew CreateNewQueueForm(mainMenu); // Создание формы.
	this->Close(); // Закрытие текущей формы.
	form->Show(); // Открытие созданной формы.
}

System::Void Prog::AdminMainForm::SetupDataGridView() { // Данный код уже закомментирован в mainForm.cpp
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;

	this->dataGridView1->Rows->Clear();
	this->dataGridView1->ColumnCount = 3;

	std::string path;
	ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("Ошибка при открытии файла очереди!\nВозможно файл поврежден.\nПопробуйте открыть нужную очередь снова.", "Ошибка");
		return;
	}
	else {
		MyQueue<queueData> que;
		if (currentFile >> que) {
			currentFile.close();

			this->QueueBox->Text = "Очередь " + ConvertSTDStringToString(que.GetTitle()) + " (" + Convert::ToString(que.length()) + ") " + Convert::ToString(que.Day()) + "." + Convert::ToString(que.Month()) + "." + Convert::ToString(que.Year());
			this->dataGridView1->Columns[0]->Width = 20;
			this->dataGridView1->Columns[0]->Name = "№";
			this->dataGridView1->Columns[1]->Width = 205;
			this->dataGridView1->Columns[1]->Name = "Name";
			this->dataGridView1->Columns[2]->Width = 50;
			this->dataGridView1->Columns[2]->Name = "Time";

			Node<queueData>* it{ que.beg() };
			while (it) {
				System::String^ name = ConvertSTDStringToString(it->data.surnameNP);
				this->dataGridView1->Rows->Add(Convert::ToString(it->data.ownNumber), name, Convert::ToString(it->data.time.hours) + " : " + Convert::ToString(it->data.time.minutes));
				it = it->next;
			}

		}
		else {
			currentFile.close();
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("Не удалось прочитать очередь из выбранного файла.\nВозможно файл поврежден.\nПопробуйте открыть нужную очередь снова.", "Ошибка");
			return;
		}
	}
	this->Cursor = System::Windows::Forms::Cursors::Default;
}

System::Void Prog::AdminMainForm::SetupDataGridView2() { // Данный код уже закомментирован в mainForm.cpp
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	this->dataGridView2->Rows->Clear();
	this->dataGridView2->ColumnCount = 3;


	this->dataGridView2->Columns[0]->Width = 20;
	this->dataGridView2->Columns[0]->Name = "№";
	this->dataGridView2->Columns[1]->Width = 205;
	this->dataGridView2->Columns[1]->Name = "Name";
	this->dataGridView2->Columns[2]->Width = 50;
	this->dataGridView2->Columns[2]->Name = "Time";
	
	this->dataGridView2->Rows->Add(this->dataGridView1->CurrentRow->Cells[0]->Value, this->dataGridView1->CurrentRow->Cells[1]->Value, this->dataGridView1->CurrentRow->Cells[2]->Value);

	this->Cursor = System::Windows::Forms::Cursors::Default;
}

System::Void Prog::AdminMainForm::AdminMainForm_Shown(System::Object^ sender, System::EventArgs^ e) {
	SetupDataGridView(); // Предустанавливаем изначально таблицы при запуске формы
	SetupDataGridView2();
}

System::Void Prog::AdminMainForm::dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
	SetupDataGridView2(); // Предустанавливаем таблицу выбранного пользователя
	if (this->dataGridView1->CurrentRow->Cells[1]->Value->ToString() != "Место не занято") { // Если не свободно, тогда даем доступ к удалению
		this->pictureBoxSub->Enabled = true;
		this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\sub.png");
	}
	else { // Иначе - блокируем
		this->pictureBoxSub->Enabled = false;
		this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\subDisabled.png");
	}
}

System::Void Prog::AdminMainForm::AdminMainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
			Application::Exit();
		else
			e->Cancel = true;
}

System::Void Prog::AdminMainForm::pictureBoxAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string uspath = "", nam = "";
	Users user;
	ConvertStringToSTDString(Application::StartupPath + "\\users\\users.txt", uspath);
	ConvertStringToSTDString(this->dataGridView1->CurrentRow->Cells[1]->Value->ToString(), nam);
	if (nam == "Место не занято") {
		MessageBox::Show("Невозможно получить информацию, поскольку запись на данное время отсутствует!", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	std::ifstream currentFileUser(uspath, std::ios::in);
	if (!currentFileUser) {
		MessageBox::Show("Ошибка получения информации (ошибка в открытии файла пользователя).", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	else {
		while (currentFileUser >> &user && user.surnameNP != nam) {} // ищем пользователя в файле
		if (user.surnameNP == nam) { // если нашли
			currentFileUser.close();

			System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
			String^ surnameNP = ConvertSTDStringToString(user.surnameNP),
				^ surname = ConvertSTDStringToString(user.surname),
				^ name = ConvertSTDStringToString(user.name),
				^ prozv = ConvertSTDStringToString(user.prozv); // Выводим данные
			strings->AppendFormat("Информация о пользователе {0}:\nФамилия: {1}\nИмя: {2}\nОтчество: {3}\nДата рождения: {4}.{5}.{6}", surnameNP, surname, name, prozv, user.birthday.day, user.birthday.month, user.birthday.year);
			strings->AppendLine();
			strings->AppendLine();
			MessageBox::Show(strings->ToString(), "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("Дополнительной информации не найдено!", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
}

System::Void Prog::AdminMainForm::pictureBoxSub_Click(System::Object^ sender, System::EventArgs^ e) { // Данный код уже закомментирован в mainForm.cpp
	if (MessageBox::Show("Вы точно уверены, что хотите отменить запись пользователя на выбранное время?", "Внимание", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK) {
		std::string path;
		ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path); // Конвертируем System::String в std::string и помещаем в path.

		std::ifstream currentFile(path, std::ios::in); // Открываем поток для чтения.
		if (!currentFile) {
			MessageBox::Show("Ошибка удаления (невозможно открыть файл очереди).", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		else {
			MyQueue<queueData> que;
			if (currentFile.peek() != EOF && currentFile >> que) {
				currentFile.close();
				//String^ name = gcnew System::String(user.surnameNP.c_str());
				DateTime time = DateTime::Now;
				DateTime timeQue;
				timeQue = timeQue.AddDays(que.Day() - 1);
				timeQue = timeQue.AddMonths(que.Month() - 1);
				timeQue = timeQue.AddYears(que.Year() - 1);
				timeQue = timeQue.AddHours(que.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.hours);
				timeQue = timeQue.AddMinutes(que.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.minutes);

				if (time >= timeQue) {
					MessageBox::Show("Невозможно отменить запись на время, которое прошло.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else {

					que.SetData(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value), "Место не занято");

					ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);

					std::ofstream queueFile(path, std::ios::out | std::ios::trunc);
					if (!queueFile) {
						this->Cursor = System::Windows::Forms::Cursors::Default;
						MessageBox::Show("Ошибка открытия файла для записи очереди!\nПовторите попытку позже.", "Ошибка");
						return;
					}
					else {
						if (!(queueFile << que)) {
							this->Cursor = System::Windows::Forms::Cursors::Default;
							queueFile.close();
							MessageBox::Show("Ошибка в момент записи очереди!", "Ошибка");
							return;
						}

						Users user;
						user.surnameNP = que.GetTitle();
						user.password = que.GetAdminPassword();
						logCancel(user);
						queueFile.close();
					}

					SetupDataGridView();
					SetupDataGridView2();

				}

			}
			else {
				currentFile.close();
				MessageBox::Show("Ошибка удаления (невозможно прочесть очередь из файла).", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

			currentFile.close();
			return;
		}
	}
}

System::Void Prog::AdminMainForm::logCancel(Users& user) { // Данный код уже закомментирован в mainForm.cpp
	std::string path = "";
	ConvertStringToSTDString(Application::StartupPath + "\\users\\cancelLog.txt", path);
	std::ofstream logFile(path, std::ios::out | std::ios::app);
	if (logFile)
		logFile << user.surnameNP << std::endl;
}

System::Void Prog::AdminMainForm::AdminMainForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(8); // Создаем справку с номером данной формы
	form->Show();
}
