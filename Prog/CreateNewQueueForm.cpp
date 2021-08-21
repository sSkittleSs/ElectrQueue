#include "CreateNewQueueForm.h"

System::Void Prog::CreateNewQueueForm::CreateNewQueueForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
			if (this->buttonContinue->Enabled)
				remove(ConvertStringToChar(file + ".tmp")); // удаляем временный файл.

			Application::Exit();
		}
		else
			e->Cancel = true;
}

System::Void Prog::CreateNewQueueForm::выйтиВГлавноеМенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->buttonContinue->Enabled)
		remove(ConvertStringToChar(file + ".tmp")); // удаляем временный файл.

	toForm = true;
	this->Close(); // Закрытие текущей формы.
	this->mainMenu->Show(); // Открытие созданной формы.
}

System::Void Prog::CreateNewQueueForm::выходИзПрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->buttonContinue->Enabled)
			remove(ConvertStringToChar(file + ".tmp")); // удаляем временный файл.
		Application::Exit();
	}
}

System::Void Prog::CreateNewQueueForm::maskedTextBoxTitle_Click(System::Object^ sender, System::EventArgs^ e) {
	this->maskedTextBoxTitle->Text = "";
}

System::Void Prog::CreateNewQueueForm::maskedTextBoxFileName_Click(System::Object^ sender, System::EventArgs^ e) {
	this->maskedTextBoxFileName->Text = "";
}

System::Void Prog::CreateNewQueueForm::maskedTextBoxPassword_Click(System::Object^ sender, System::EventArgs^ e) {
	this->maskedTextBoxPassword->Text = "";
	this->maskedTextBoxPassword->PasswordChar = '*';
}

System::Void Prog::CreateNewQueueForm::buttonConfirmTitle_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите подтвердить текущее название очереди?\nПосле нажатия на \"OK\" изменить название будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxTitle->Text == "" || this->maskedTextBoxTitle->Text == "Введите название очереди (Врач)") {
			MessageBox::Show("Поле не должно быть пустым или же иметь стандартный текст.", "Внимание!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		titleConfirmed = true; // Переводим флаг подтверждение в положение true и блокируем кнопки для изменения
		this->buttonConfirmTitle->Enabled = false;
		this->maskedTextBoxTitle->Enabled = false;
	}
}

System::Void Prog::CreateNewQueueForm::buttonConfirmFileName_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите подтвердить текущее название файла?\nПосле нажатия на \"OK\" изменить название будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxFileName->Text == "" || this->maskedTextBoxFileName->Text == "Введите имя файла (без расширения)") {
			MessageBox::Show("Поле не должно быть пустым или же иметь стандартный текст.", "Внимание!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		fileNameConfirmed = true; // Переводим флаг подтверждение в положение true и блокируем кнопки для изменения
		this->buttonConfirmFileName->Enabled = false;
		this->maskedTextBoxFileName->Enabled = false;

		file = Application::StartupPath + "\\queues\\" + this->maskedTextBoxFileName->Text->ToString();

		array<String^>^ fileNames = System::IO::Directory::GetFiles(Application::StartupPath + "\\queues");
		for (int i = 0; i < fileNames->Length; i++) {
			if (System::IO::Path::GetFileNameWithoutExtension(fileNames[i]) == this->maskedTextBoxFileName->Text->ToString())
				if (MessageBox::Show("Файл с таким именем уже существует. При создании очереди старая информация в файле будет перезаписана.\n\nВы уверены, что хотите продолжить?", "Внимание!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Cancel) {
					fileNameConfirmed = false; // Переводим флаг подтверждение в положение false и разблокируем кнопки для изменения
					file = "";
					this->buttonConfirmFileName->Enabled = true;
					this->maskedTextBoxFileName->Enabled = true;
				}
		}
	}
}

System::Void Prog::CreateNewQueueForm::buttonConfirmTime_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->numericUpDownMinutesEnd->Value != 0 && this->numericUpDownMinutesEnd->Value != 30) {
		MessageBox::Show("Время конца работы (минуты) должны быть равны 0 или 30.", "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (this->numericUpDownMinutesStart->Value != 0 && this->numericUpDownMinutesStart->Value != 30) {
		MessageBox::Show("Время начала работы (минуты) должны быть равны 0 или 30.", "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (this->numericUpDownHoursEnd->Value == this->numericUpDownHoursStart->Value && this->numericUpDownMinutesEnd->Value == this->numericUpDownMinutesStart->Value) {
		MessageBox::Show("Время начала работы и конца работы не могут совпадать.", "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if ((Convert::ToInt32(this->numericUpDownMinutesEnd->Value) + Convert::ToInt32(this->numericUpDownHoursEnd->Value) * 10) < (Convert::ToInt32(this->numericUpDownMinutesStart->Value) + Convert::ToInt32(this->numericUpDownHoursStart->Value) * 10)) {
		MessageBox::Show("Время конца работы не должно быть раньше, чем время конца работы.", "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	else
		if (MessageBox::Show("Вы уверены, что хотите подтвердить текущее название файла?\nПосле нажатия на \"OK\" изменить название будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
			timeConfirmed = true; // Переводим флаг подтверждение в положение true и блокируем кнопки для изменения
			this->buttonConfirmTime->Enabled = false;
			this->numericUpDownHoursEnd->Enabled = false;
			this->numericUpDownMinutesEnd->Enabled = false;
			this->numericUpDownHoursStart->Enabled = false;
			this->numericUpDownMinutesStart->Enabled = false;
		}
}

System::Void Prog::CreateNewQueueForm::buttonConfirmPassword_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите подтвердить текущий пароль для очереди?\nПароль: " + this->maskedTextBoxPassword->Text->ToString() + "\nПосле нажатия на \"OK\" изменить пароль будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxPassword->Text == "" || this->maskedTextBoxPassword->Text == "Введите пароль администратора очереди") {
			MessageBox::Show("Поле не должно быть пустым или же иметь стандартный текст.", "Внимание!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		passwordConfirmed = true; // Переводим флаг подтверждение в положение true и блокируем кнопки для изменения
		this->buttonConfirmPassword->Enabled = false;
		this->maskedTextBoxPassword->Enabled = false;
	}
}

System::Void Prog::CreateNewQueueForm::buttonConfirmDate_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите подтвердить текущую дату приема?\nПосле нажатия на \"OK\" изменить дату будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		dateConfirmed = true; // Переводим флаг подтверждение в положение true и блокируем кнопки для изменения
		this->buttonConfirmDate->Enabled = false;
		this->dateTimePickerDate->Enabled = false;
	}
}

System::Void Prog::CreateNewQueueForm::buttonCreateQueue_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	if (titleConfirmed && fileNameConfirmed && timeConfirmed && passwordConfirmed) { // Если все поля подтверждены
		size_t start{}, end{}, counter{ 1 };
		start = Convert::ToInt32(this->numericUpDownHoursStart->Value) * 2 + Convert::ToInt32(this->numericUpDownMinutesStart->Value) / 30; // Высчитываем начальное значение для цикла
		end = Convert::ToInt32(this->numericUpDownHoursEnd->Value) * 2 + Convert::ToInt32(this->numericUpDownMinutesEnd->Value) / 30; // Высчитываем конечное значение для цикла

		ownTime time;
		MyQueue<queueData> que;
		for (size_t i = start; i <= end; i++) { // Идем от начала до конца и производим обратную операцию по вычеслению времени
			time.hours = i / 2;
			time.minutes = (i * 30) % 60;
			queueData data(time, counter++, "Место не занято");
			que.queue(data); // Помещаем стандартные данные по указанному времени
		}

		std::string title = "", path = "", pass = ""; // Меняем поля очереди на те, которые в текстбоксах
		ConvertStringToSTDString(this->maskedTextBoxTitle->Text->ToString(), title);
		que.SetTitle(title);
		ConvertStringToSTDString(Application::StartupPath + "\\queues\\" + this->maskedTextBoxFileName->Text->ToString() + ".tmp", path);
		que.SetFileName(path);
		ConvertStringToSTDString(this->maskedTextBoxPassword->Text->ToString(), pass);
		que.SetAdminPassword(pass);
		DateTime date = this->dateTimePickerDate->Value;
		que.Day(date.Day);
		que.Month(date.Month);
		que.Year(date.Year);
		file = Application::StartupPath + "\\queues\\" + this->maskedTextBoxFileName->Text->ToString();

		std::ofstream queueFile(que.GetFileName(), std::ios::out | std::ios::trunc); // По указанному пути в очереди открываем поток
		if (!queueFile) {
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("Ошибка открытия файла для записи очереди!\nПовторите попытку позже.", "Ошибка");
			return;
		}
		else {
			if (!(queueFile << que)) { // Если очередь не записывается выдаем ошибку, иначе закрываем поток и читаем очередь заново, выводя таблицу.
				this->Cursor = System::Windows::Forms::Cursors::Default;
				queueFile.close();
				MessageBox::Show("Ошибка в момент записи очереди!", "Ошибка");
				return;
			}
			queueFile.close();

			std::ifstream currentFile(path, std::ios::in);
			if (!currentFile) {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("Ошибка при открытии файла!\nВозможно файл очереди не создался и она не будет отрисована.\nПожалуйста, убедитесь, что файл был создан.", "Ошибка");
				return;
			}
			else {
				MyQueue<queueData> que;
				if (currentFile >> que) {
					currentFile.close();
					this->buttonContinue->Enabled = true;
					SetupDataGridView(path);
				}
				else {
					currentFile.close();
					this->Cursor = System::Windows::Forms::Cursors::Default;
					MessageBox::Show("Не удалось прочитать очередь из выбранного файла.\nВозможно вам стоит пересоздать файл очереди.", "Ошибка");
					return;
				}
			}
			this->Cursor = System::Windows::Forms::Cursors::Default;
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("Очередь была успешно создана и помещена в папку ..\\queues\\\nДля сохранения очереди, нажмите кнопку \"Продолжить\", для коррекции данных - \"Отмена\"", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else { // Иначе составляем список необходимых подтверждений.
		System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
		strings->Append("Для продолжения неободимо: ");
		strings->AppendLine();

		if (!titleConfirmed) {
			strings->Append("Заполнить/подтвердить поле имени очереди.");
			strings->AppendLine();
		}
		if (!fileNameConfirmed) {
			strings->Append("Заполнить/подтвердить поле имени файла.");
			strings->AppendLine();
		}
		if (!timeConfirmed) {
			strings->Append("Заполнить/подтвердить поля времени работы.");
			strings->AppendLine();
		}
		if (!passwordConfirmed) {
			strings->Append("Заполнить/подтвердить поле пароля администратора очереди.");
			strings->AppendLine();
		}
		if (!dateConfirmed) {
			strings->Append("Заполнить/подтвердить поле даты приема очереди.");
			strings->AppendLine();
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show(strings->ToString(),"Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void Prog::CreateNewQueueForm::SetupDataGridView(std::string path) {  // Данный код уже закомментирован в mainForm.cpp
	this->dataGridView1->Rows->Clear();

	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	this->dataGridView1->ColumnCount = 3;

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

			this->QueueBox->Text = "Предпросмотр очереди из файла " + ConvertSTDStringToString(que.GetTitle()) + " (" + Convert::ToString(que.length()) + ")";
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

System::Void Prog::CreateNewQueueForm::buttonContinue_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	std::string path;
	ConvertStringToSTDString(file + ".tmp", path);

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("Ошибка при открытии файла!\nВозможно данного файла не существует,\nлибо путь указан неверно.", "Ошибка");
		return;
	}
	else {
		MyQueue<queueData> que;
		if (currentFile >> que) { // Читаем очередь из временного файла
			currentFile.close();
			SetupDataGridView(path);
			ConvertStringToSTDString(file + ".txt", path);
			que.SetFileName(path);

			std::ofstream queueFile(path, std::ios::out | std::ios::trunc);
			if (!queueFile) {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("Ошибка открытия файла для записи очереди!\nПовторите попытку позже.", "Ошибка");
				return;
			}
			else {
				if (!(queueFile << que)) { // Помещаем очередь в конечный файл
					this->Cursor = System::Windows::Forms::Cursors::Default;
					queueFile.close();
					MessageBox::Show("Ошибка в момент записи очереди!", "Ошибка");
					return;
				}
				queueFile.close();
			}
		}
		else {
			currentFile.close();
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("Не удалось прочитать очередь из выбранного файла.", "Ошибка");
			return;
		}
	}
	remove(ConvertStringToChar(file + ".tmp")); // удаляем временный файл.
	
	MessageBox::Show("Очередь успешно сохранена. Теперь вы можете открыть данную очередь в главном меню.", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);

	toForm = true;
	this->Close(); // Закрытие текущей формы.
	mainMenu->Show(); // Открытие созданной формы.
	this->Cursor = System::Windows::Forms::Cursors::Default;
}

System::Void Prog::CreateNewQueueForm::buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) { // Разрешаем доступ к тем кнопкам, к которым уже запрещен доступ и переводим флаги
	if (this->buttonContinue->Enabled) { 
		this->buttonContinue->Enabled = false;
		this->dataGridView1->Rows->Clear();
		this->dataGridView1->Columns->Clear();
		remove(ConvertStringToChar(file + ".tmp")); // удаляем временный файл.
	}
	if (titleConfirmed) {
		titleConfirmed = false;
		this->buttonConfirmTitle->Enabled = true;
		this->maskedTextBoxTitle->Enabled = true;
	}
	if (fileNameConfirmed) {
		fileNameConfirmed = false;
		this->buttonConfirmFileName->Enabled = true;
		this->maskedTextBoxFileName->Enabled = true;
	}
	if (timeConfirmed) {
		timeConfirmed = false;
		this->buttonConfirmTime->Enabled = true;
		this->numericUpDownHoursEnd->Enabled = true;
		this->numericUpDownMinutesEnd->Enabled = true;
		this->numericUpDownHoursStart->Enabled = true;
		this->numericUpDownMinutesStart->Enabled = true;
	}
	if (passwordConfirmed) {
		passwordConfirmed = false;
		this->buttonConfirmPassword->Enabled = true;
		this->maskedTextBoxPassword->Enabled = true;
	}
	if (dateConfirmed) {
		dateConfirmed = false;
		this->buttonConfirmDate->Enabled = true;
		this->dateTimePickerDate->Enabled = true;
	}

}

System::Void Prog::CreateNewQueueForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Данная программа создана для записи в очередь в поликлинику.\n\nАвтор программы:\t(c) Бриль А.Э., Т-893", "О программе", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::CreateNewQueueForm::открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toForm = true;
	OpenQueueFileForm^ form = gcnew OpenQueueFileForm(mainMenu); // Создание формы.
	this->Close(); // Закрытие текущей формы.
	form->Show(); // Открытие созданной формы.
}

System::Void Prog::CreateNewQueueForm::CreateNewQueueForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(3); // Создаем справку для данной формы.
	form->Show();
}

