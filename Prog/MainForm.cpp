#include "MainForm.h"

System::Void Prog::MainForm::pictureBoxAdd_MouseEnter(System::Object^ sender, System::EventArgs^ e) { // Если мышь наводится на Add, то меняем картинку и увеличиваем.
	this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\addEnter.png");
	++this->pictureBoxAdd->Width;
	++this->pictureBoxAdd->Height;
}

System::Void Prog::MainForm::pictureBoxAdd_MouseLeave(System::Object^ sender, System::EventArgs^ e) { // Если мышь выводится с Add, то меняем картинку и уменьшаем.
	this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\add.png");
	--this->pictureBoxAdd->Width;
	--this->pictureBoxAdd->Height;
}

System::Void Prog::MainForm::pictureBoxSub_MouseEnter(System::Object^ sender, System::EventArgs^ e) { // Если мышь наводится на Sub, то меняем картинку и увеличиваем.
	this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\subEnter.png");
	++this->pictureBoxSub->Width;
	++this->pictureBoxSub->Height;
}

System::Void Prog::MainForm::pictureBoxSub_MouseLeave(System::Object^ sender, System::EventArgs^ e) { // Если мышь выводится с Sub, то меняем картинку и уменьшаем.
	this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\sub.png");
	--this->pictureBoxSub->Width;
	--this->pictureBoxSub->Height;
}

System::Void Prog::MainForm::выходИзПрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		Application::Exit();
}

System::Void Prog::MainForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Данная программа создана для записи в очередь в поликлинику.\n\nАвтор программы:\t(c) Бриль А.Э., Т-893", "О программе", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::MainForm::выйтиВГлавноеМенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toForm = true;
	this->Close(); // Закрытие текущей формы.
	this->mainMenu->Show(); // Открытие формы главного меню.
}

System::Void Prog::MainForm::войтиКакАдминистраторToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string path;
	ConvertStringToSTDString(System::Windows::Forms::Application::StartupPath + "\\queues\\currentQueue.txt", path);

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		System::Windows::Forms::MessageBox::Show("Ошибка при открытии текущей очереди.", "Ошибка");
		return;
	}
	else {
		MyQueue<queueData> que;
		if (currentFile >> que) { // Если очередь читается
			bool passwordIsCorrect = false;
			Users user1;
			user1.surnameNP = que.GetTitle();
			user1.password = que.GetAdminPassword();
			CheckPassForm^ form = gcnew CheckPassForm(this, &passwordIsCorrect, &user1);

			switch (form->ShowDialog()) { // Проверяем пароль
			case System::Windows::Forms::DialogResult::OK: { // Если пароль верный

				MessageBox::Show("Авторизация прошла успешно!\n", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);

				AdminMainForm^ form = gcnew AdminMainForm(mainMenu); // Создание формы.
				toForm = true;
				this->Close(); // Закрытие текущей формы.
				form->Show(); // Открытие созданной формы.

				break;
			} // Если пароль неверный или форму закрыли, то выводим сообщение
			case System::Windows::Forms::DialogResult::Abort: {
				MessageBox::Show("Авторизация не была завершена, поскольку пароль был введен не верно.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}
			case System::Windows::Forms::DialogResult::Cancel: {
				form->Close();
				MessageBox::Show("Авторизация не была завершена, поскольку форма была закрыта.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}
			}
		}
		currentFile.close();
	}

}

System::Void Prog::MainForm::сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string path;
	ConvertStringToSTDString(System::Windows::Forms::Application::StartupPath + "\\queues\\currentQueue.txt", path);

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		System::Windows::Forms::MessageBox::Show("Ошибка при открытии файла для чтения!\nСохранить очередь не удалось.", "Ошибка");
		return;
	}
	else {
		MyQueue<queueData> que;
		currentFile >> que; // Читаем очередь
		currentFile.close();

		std::ofstream queueFileMF(que.GetFileName(), std::ios::out | std::ios::trunc); // Берем путь до файла, который использовался при открытии
		if (!queueFileMF) {
			System::Windows::Forms::MessageBox::Show("Ошибка в момент записи очереди!\nСохранить очередь не удалось.", "Ошибка");
			return;
		}
		else {
			if (queueFileMF << que) { // Если записали
				ConvertStringToSTDString(System::Windows::Forms::Application::StartupPath + "\\queues\\currentQueue.txt", path); // Далее будем перезаписывать текущую очередь
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

System::Void Prog::MainForm::открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toForm = true;
	OpenQueueFileForm^ form = gcnew OpenQueueFileForm(mainMenu); // Создание формы.
	this->Close(); // Закрытие текущей формы.
	form->Show(); // Открытие созданной формы.
}

System::Void Prog::MainForm::SetupDataGridView() { // Перестройка таблицы (без DataTable)
	this->dataGridView1->Rows->Clear();

	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
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
		if (currentFile >> que) { // Читаем очередь
			currentFile.close();
			// Выводим название очереди, её длину и дату приема
			this->QueueBox->Text = "Очередь " + ConvertSTDStringToString(que.GetTitle()) + " (" + Convert::ToString(que.length()) + ") " + Convert::ToString(que.Day()) + "." + Convert::ToString(que.Month()) + "." + Convert::ToString(que.Year());
			this->dataGridView1->Columns[0]->Width = 20;
			this->dataGridView1->Columns[0]->Name = "№";
			this->dataGridView1->Columns[1]->Width = 205;
			this->dataGridView1->Columns[1]->Name = "Name";
			this->dataGridView1->Columns[2]->Width = 50;
			this->dataGridView1->Columns[2]->Name = "Time";

			Node<queueData>* it{ que.beg() };
			while (it) { // Выводим всю очередь по одному узлу, пока это возможно.
				System::String^ name = ConvertSTDStringToString(it->data.surnameNP);
				this->dataGridView1->Rows->Add(Convert::ToString(it->data.ownNumber), name, Convert::ToString(it->data.time.hours) + " : " + Convert::ToString(it->data.time.minutes));
				it = it->next;
			}

		}
		else { // Если не удалось прочитать очередь
			currentFile.close();
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("Не удалось прочитать очередь из выбранного файла.\nВозможно файл поврежден.\nПопробуйте открыть нужную очередь снова.", "Ошибка");
			return;
		}
	}
	this->Cursor = System::Windows::Forms::Cursors::Default;
}

System::Void Prog::MainForm::MainForm_Shown(System::Object^ sender, System::EventArgs^ e) {
	SetupDataGridView();
}

System::Void Prog::MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) { // Событие, которое срабатывает при закрытии формы
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
			Application::Exit();
		else
			e->Cancel = true;
}

System::Void Prog::MainForm::pictureBoxAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	
	switch(balance()) { // Смотрим что возвращает метод balance()
	case 0: // Если функция не смогла проверить или все хорошо
	case 1:{ // Если функция проверила и пользователь хочет записаться
			if (MessageBox::Show("Вы точно уверены, что хотите записаться на выбранное время?", "Внимание", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK) {
				std::string path;
				ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path); // Конвертируем System::String в std::string и помещаем в path.

				std::ifstream currentFile(path, std::ios::in); // Открываем поток для чтения.
				if (!currentFile) {
					MessageBox::Show("Ошибка добавления (невозможно открыть файл очереди).", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				else {
					MyQueue<queueData> que;
					if (currentFile.peek() != EOF && currentFile >> que) { // Читаем очередь и проверяем сразу
						currentFile.close();
						//String^ name = gcnew System::String(user.surnameNP.c_str());
						ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.txt", path);
						std::ifstream currentFileUser(path, std::ios::in);
						if (!currentFileUser) {
							//currUser = "NONE";
						}
						else {
							Users user;
							if (currentFileUser >> &user) { // Если пользователь читается
								currentFileUser.close(); // Ниже проверяем записан ли пользователь где-либо ещё на это же время (и дату)
								if (checkTime(user, que.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.hours, que.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.minutes)) {
									MessageBox::Show("Вы уже записаны на данное время у другого врача.\nЕсли вы все же хотите записаться, то вам следует сперва отменить\nзапись у другого врача.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
									return;
								}
								else {
									que.SetData(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value), user.surnameNP); // Добавляем пользователя, а затем обновляем таблицы

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
										queueFile.close();
									}

									SetupDataGridView(); // Предустановка таблицы (главной)
									SetupDataGridView2(); // Предустановка таблицы (выбранный пользователь).
								}
							}
							else {
								///
								currentFileUser.close();
							}
						}

					}
					else {
						currentFile.close();
						MessageBox::Show("Ошибка добавления (невозможно прочесть очередь из файла).", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}

					currentFile.close();
					return;
				}
			}
		}
		break;
	case 2: { // Если пользователь не захотел записываться
		return;
	}
	default: { // Если что-то пошло не так.
		MessageBox::Show("Произошла ошибка при попытке записи.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	}
}

System::Void Prog::MainForm::pictureBoxSub_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string uspath;
	Users user;
	ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.txt", uspath);
	std::ifstream currentFileUser(uspath, std::ios::in);
	if (!currentFileUser) {
		MessageBox::Show("Ошибка удаления (невозможно открыть файл пользователя).", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	else {
		if (currentFileUser >> &user) { // Читаем пользователя
			currentFileUser.close();
			if (checkCancel(user)) { // Проверяем кол-во отмен в специльном файле и выводим сообщение если оно превышает 3
				MessageBox::Show("Вы делаете более трех отмен в неделю!", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			if (MessageBox::Show("Вы точно уверены, что хотите отменить запись на выбранное время?", "Внимание", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK) {
				std::string path;
				ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path); // Конвертируем System::String в std::string и помещаем в path.

				std::ifstream currentFile(path, std::ios::in); // Открываем поток для чтения.
				if (!currentFile) {
					MessageBox::Show("Ошибка удаления (невозможно открыть файл очереди).", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				else {
					MyQueue<queueData> que;
					if (currentFile.peek() != EOF && currentFile >> que) { // Если очередь читается
						currentFile.close();
						//String^ name = gcnew System::String(user.surnameNP.c_str());
						DateTime time = DateTime::Now; // Берем текущее время и дату
						DateTime timeQue;
						timeQue = timeQue.AddDays(que.Day() - 1);
						timeQue = timeQue.AddMonths(que.Month() - 1);
						timeQue = timeQue.AddYears(que.Year() - 1);
						timeQue = timeQue.AddHours(que.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.hours);
						timeQue = timeQue.AddMinutes(que.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.minutes);

						if (time >= timeQue) { // Если текущее время больше, чем выбранное время, то выводим сообщение
							MessageBox::Show("Невозможно отменить запись к врачу на время, которое прошло.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						}
						else { // Иначе помечаем место, как не занятое и перерисовываем таблицы, сохранив их перед этим.
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
		else {

			MessageBox::Show("Ошибка удаления (невозможно прочесть пользователя из файла).", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			currentFileUser.close();
			return;
		}
	}
}

System::Void Prog::MainForm::SetupDataGridView2() { // Предустанавливаем таблицу выбранного пользователя
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

System::Void Prog::MainForm::SetupButtons() { // Предустанавливаем кнопки
	
	std::string path = "";
	ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.txt", path);
	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		//currUser = "NONE";
	}
	else {
		Users user;
		if (currentFile >> &user) { // Если можем прочитать пользователя, то смотрим свободно ли место
			currentFile.close();
			String^ name = gcnew System::String(user.surnameNP.c_str());

			if (this->dataGridView1->CurrentRow->Cells[1]->Value->ToString() == "Место не занято") { // Если свободно, тогда даем доступ к добавлению
				this->pictureBoxAdd->Enabled = true;
				this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\add.png");
			}
			else { // Иначе - блокируем
				this->pictureBoxAdd->Enabled = false;
				this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\addDisabled.png");
			}
			
			if (this->dataGridView1->CurrentRow->Cells[1]->Value->ToString() == name) { // Если место занято пользователем, то даем доступ к возможности отменить запись
				this->pictureBoxSub->Enabled = true;
				this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\sub.png");
			}
			else { // Иначе - блокируем
				this->pictureBoxSub->Enabled = false;
				this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\subDisabled.png");
			}
		}
		else { // Если пользователя не смогли прочитать, то блокируем все.
			this->pictureBoxAdd->Enabled = false;
			this->pictureBoxSub->Enabled = false;
			this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\addDisabled.png");
			this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\subDisabled.png");
			currentFile.close();
		}
	}

}

System::Void Prog::MainForm::logCancel(Users& user) { // Логируем данные об отмене
	std::string path = "";
	ConvertStringToSTDString(Application::StartupPath + "\\users\\cancelLog.txt", path);
	std::ofstream logFile(path, std::ios::out | std::ios::app);
	if (logFile)
		logFile << user.surnameNP << std::endl;
}

bool Prog::MainForm::checkCancel(Users& user) { // Считаем количество отмен пользователя в файле
	std::string path = "", name = user.surnameNP;
	char check[51];
	size_t count = 0;
	ConvertStringToSTDString(Application::StartupPath + "\\users\\cancelLog.txt", path);
	std::ifstream logFile(path, std::ios::in);
	while (logFile.getline(check, 51, '\n')) // Пока можем читать
		if (check == name)
			count++;
	
	return count >= 3;
}

bool Prog::MainForm::checkTime(Users user, size_t hours, size_t minutes) { // Функция проверки совпадения дат для данного пользователя

	array<String^>^ fileNames = System::IO::Directory::GetFiles(Application::StartupPath + "\\queues"); // Получаем все очереди в папке
	System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
	for (size_t i = 0; i < fileNames->Length; i++) { // Проходим по им всем
		
		std::string path;
		ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);
		std::ifstream currentFileQueue(path, std::ios::in);
		if (!currentFileQueue) {
			continue;
		}
		else {
			MyQueue<queueData> queue;
			if (currentFileQueue >> queue) { // Читаем текущую очередь
				currentFileQueue.close();
				
				ConvertStringToSTDString(fileNames[i], path);
				//Application::StartupPath + "\\queues\\"

				if ((queue.GetFileName() == path) || (fileNames[i] == Application::StartupPath + "\\queues\\currentQueue.txt")) // Если очередь является текущей или является той, \\
					из которой открывали текущую, то выбираем следующую
					continue;

				std::ifstream currentFile(path, std::ios::in);
				if (!currentFile) {
					return false;
				}
				else {
					MyQueue<queueData> que;
					if (currentFile >> que) { // Читаем очередь
						currentFile.close();

						for (size_t j = 1; j <= que.length(); j++) {// Если дата и время совпадает
							if (que.find(j)->data.time.hours == hours && que.find(j)->data.time.minutes == minutes
								&& que.Day() == queue.Day() && que.Month() == queue.Month() && que.Year() == queue.Year())
								if (que.find(j)->data.surnameNP == user.surnameNP) // И при этом там записан такой же пользователь, тогда возвращаем true
									return true;
						}

					}
					else { // Иначе false
						currentFile.close();
						return false;
					}
				}

			}
			else { // Иначе берем следующий файл
				currentFileQueue.close();
				continue;
			}
		}

		
	}
	return false; // Если все прошло и не нашло, возвращаем false
}

int Prog::MainForm::balance() { // Функция балансировки нагрузки (отображена в блок-схеме)
	
	std::string path;
	ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);
	std::ifstream currentFileQueue(path, std::ios::in);
	if (!currentFileQueue) {
		return 0;
	}
	else {
		MyQueue<queueData> queue;
		if (currentFileQueue >> queue) { // Если читается текущая очередь
			currentFileQueue.close();

			Node<queueData>* toSet{ queue.beg() };
			size_t nempty = 0;
			while (toSet) {	// Считаем кол-во занятых мест
				if (toSet->data.surnameNP != "Место не занято")
					nempty++;
				toSet = toSet->next;
			}

			if (((double)nempty / (double)queue.length() * 100) >= 90) { // Смотрим больше либо равна ли нагрузка 90%, если да

				array<String^>^ fileNames = System::IO::Directory::GetFiles(Application::StartupPath + "\\queues"); // Получаем все файлы в папке очередей
				System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder(); 
				strings->AppendFormat("Очередь к текущему врачу заполнена на {0}%.\nПредлагаем вам записаться к следующим врачам:", (double)nempty / (double)queue.length() * 100);
				strings->AppendLine();
				for (size_t i = 0; i < fileNames->Length; i++) { // Берем каждую очередь
					ConvertStringToSTDString(fileNames[i], path);

					if ((queue.GetFileName() == path) || (fileNames[i] == Application::StartupPath + "\\queues\\currentQueue.txt")) // Если очередь является текущей или является той, \\
					из которой открывали текущую, то выбираем следующую
						continue;

					std::ifstream currentFile(path, std::ios::in);
					if (!currentFile) {
						continue;
					}
					else {
						MyQueue<queueData> que;
						if (currentFile >> que) { // Если очередь читается
							currentFile.close();

							Node<queueData>* toSet{ que.beg() }; // Считаем количество занятых мест
							size_t nempty = 0;
							while (toSet) {
								if (toSet->data.surnameNP != "Место не занято")
									nempty++;
								toSet = toSet->next;
							}

							double congestion = ((double)nempty / (double)queue.length()) * 100; // Высчитываем нагрузку

							if (congestion > 50) // Если больше 50%, то берем следующую
								continue;
							else { // Иначе проверяем возможность записи на такое же время
								bool possibility = false;
								for (size_t j = 1; j <= que.length(); j++) {
									
									if (que.find(j)->data.time.hours == queue.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.hours && que.find(j)->data.time.minutes == queue.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.minutes) {
										possibility = que.find(j)->data.surnameNP == "Место не занято";
									}

								}
								// Добавляем информацию об этом враче
								strings->Append("---------------------");
								strings->AppendLine();
								String^ title = ConvertSTDStringToString(que.GetTitle());
								strings->AppendFormat("Врач: {0}\nДата приема: {1}.{2}.{3}\nВозможность записи на то же время: {4}\nФайл очереди: {5}\nЗагруженность: {6}%", title, que.Day(), que.Month(), que.Year(), (possibility ? "Присутствует" : "Отсутствует"), System::IO::Path::GetFileName(fileNames[i]), congestion);
								strings->AppendLine();
							}

						}
						else { // Иначе берем следующую
							currentFile.close();
							continue;
						}
					}

				}
				strings->AppendLine(); // Выводим информацию о всех врачах
				strings->Append("Нажмите \"OK\", чтобы продолжить запись к текущему врачу.\nНажмите \"Cancel\", чтобы отменить запись к текущему врачу.");
				strings->AppendLine();
				return MessageBox::Show(strings->ToString(), "Внимание", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK ? 1 : 2;
			}
			else
				return 0;

		}
		else {
			currentFileQueue.close();
			return 0;
		}
	}

}

System::Void Prog::MainForm::dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
	SetupDataGridView2(); // Предустанавливаем таблицу выбранного пользователя
	SetupButtons(); // Предустаннавливаем кнопки
}

System::Void Prog::MainForm::MainForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(4); // Создаем окно справки с номером данного окна
	form->Show();
}
