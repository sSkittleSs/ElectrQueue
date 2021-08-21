#include "RegistrationForm.h"

System::Void Prog::RegistrationForm::RegistrationForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
			if (this->buttonSaveUser->Enabled)
				remove(ConvertStringToChar(Application::StartupPath + "\\users\\newUser.tmp"));

			Application::Exit();
		}
		else
			e->Cancel = true;
}

System::Void Prog::RegistrationForm::выйтиВГлавноеМенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->buttonSaveUser->Enabled)
		remove(ConvertStringToChar(Application::StartupPath + "\\users\\newUser.tmp")); // Удаляем временный файл

	toForm = true;
	this->Close();
	mainMenu->Show();
}

System::Void Prog::RegistrationForm::выходИзПрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->buttonSaveUser->Enabled)
			remove(ConvertStringToChar(Application::StartupPath + "\\users\\newUser.tmp")); // Удаляем временный файл
		Application::Exit();
	}
}

System::Void Prog::RegistrationForm::buttonConfirmSurname_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите подтвердить текущую Фамилию?\nПосле нажатия на \"OK\" изменить название будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxSurname->Text == "" || this->maskedTextBoxSurname->Text == "Введите Фамилию") {
			MessageBox::Show("Поле не должно быть пустым или же иметь стандартный текст.", "Внимание!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		surnameConfirmed = true;
		this->buttonConfirmSurname->Enabled = false;
		this->maskedTextBoxSurname->Enabled = false;
	}
}

System::Void Prog::RegistrationForm::buttonConfirmName_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите подтвердить текущее Имя?\nПосле нажатия на \"OK\" изменить название будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxName->Text == "" || this->maskedTextBoxName->Text == "Введите Имя") {
			MessageBox::Show("Поле не должно быть пустым или же иметь стандартный текст.", "Внимание!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		nameConfirmed = true;
		this->buttonConfirmName->Enabled = false;
		this->maskedTextBoxName->Enabled = false;
	}
}

System::Void Prog::RegistrationForm::buttonConfirmProzv_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите подтвердить текущее Отчество?\nПосле нажатия на \"OK\" изменить название будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxProzv->Text == "" || this->maskedTextBoxProzv->Text == "Введите Отчество") {
			MessageBox::Show("Поле не должно быть пустым или же иметь стандартный текст.", "Внимание!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		prozvConfirmed = true;
		this->buttonConfirmProzv->Enabled = false;
		this->maskedTextBoxProzv->Enabled = false;
	}
}

System::Void Prog::RegistrationForm::buttonConfirmBirthday_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите подтвердить текущую дату рождения?\nПосле нажатия на \"OK\" изменить название будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->dateTimePickerBirthday->Value == DateTime::Today) {
			MessageBox::Show("Некорректная дата рождения.", "Внимание!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		birthdayConfirmed = true;
		this->buttonConfirmBirthday->Enabled = false;
		this->dateTimePickerBirthday->Enabled = false;
	}
}

System::Void Prog::RegistrationForm::buttonConfirmPassword_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите подтвердить текущий пароль для пользователя?\nПароль: " + this->maskedTextBoxPassword->Text->ToString() + "\nПосле нажатия на \"OK\" изменить название будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxPassword->Text == "" || this->maskedTextBoxPassword->Text == "Введите пароль для нового пользователя") {
			MessageBox::Show("Поле не должно быть пустым или же иметь стандартный текст.", "Внимание!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		passwordConfirmed = true;
		this->buttonConfirmPassword->Enabled = false;
		this->maskedTextBoxPassword->Enabled = false;
	}
}

System::Void Prog::RegistrationForm::maskedTextBoxSurname_Click(System::Object^ sender, System::EventArgs^ e) {
	this->maskedTextBoxSurname->Text = "";
}

System::Void Prog::RegistrationForm::maskedTextBoxName_Click(System::Object^ sender, System::EventArgs^ e) {
	this->maskedTextBoxName->Text = "";
}

System::Void Prog::RegistrationForm::maskedTextBoxProzv_Click(System::Object^ sender, System::EventArgs^ e) {
	this->maskedTextBoxProzv->Text = "";
}

System::Void Prog::RegistrationForm::maskedTextBoxPassword_Click(System::Object^ sender, System::EventArgs^ e) {
	this->maskedTextBoxPassword->Text = "";
}

System::Void Prog::RegistrationForm::buttonCorrection_Click(System::Object^ sender, System::EventArgs^ e) { // Разрешаем доступ к коррекции данных.
	if (this->buttonSaveUser->Enabled) {
		this->buttonSaveUser->Enabled = false;
		remove(ConvertStringToChar(Application::StartupPath + "\\users\\newUser.tmp")); // Удаляем временный файл
	}
	if (surnameConfirmed) {
		surnameConfirmed = false;
		this->buttonConfirmSurname->Enabled = true;
		this->maskedTextBoxSurname->Enabled = true;
	}
	if (nameConfirmed) {
		nameConfirmed = false;
		this->buttonConfirmName->Enabled = true;
		this->maskedTextBoxName->Enabled = true;
	}
	if (prozvConfirmed) {
		prozvConfirmed = false;
		this->buttonConfirmProzv->Enabled = true;
		this->maskedTextBoxProzv->Enabled = true;
	}
	if (birthdayConfirmed) {
		birthdayConfirmed = false;
		this->buttonConfirmBirthday->Enabled = true;
		this->dateTimePickerBirthday->Enabled = true;
	}
	if (passwordConfirmed) {
		passwordConfirmed = false;
		this->buttonConfirmPassword->Enabled = true;
		this->maskedTextBoxPassword->Enabled = true;
	}
}

System::Void Prog::RegistrationForm::buttonSaveUser_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	std::string path;
	ConvertStringToSTDString(Application::StartupPath + "\\users\\newUser.tmp", path);

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("Ошибка при открытии файла!\nВозможно данного файла не существует,\nлибо путь указан неверно.", "Ошибка");
		return;
	}
	else {
		Users user;
		if (currentFile >> &user) {
			currentFile.close();
			ConvertStringToSTDString(Application::StartupPath + "\\users\\users.txt", path);

			std::ofstream queueFile(path, std::ios::out | std::ios::app);
			if (!queueFile) {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("Ошибка открытия файла для записи пользователя!\nПовторите попытку позже.", "Ошибка");
				return;
			}
			else {
				if (!(queueFile << user)) { // Заносим пользователя в общий файл пользователей
					this->Cursor = System::Windows::Forms::Cursors::Default;
					queueFile.close();
					MessageBox::Show("Ошибка в момент записи пользователя!", "Ошибка");
					return;
				}
				queueFile.close();
			}
		}
		else {
			currentFile.close();
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("Не удалось прочитать файл пользователей.", "Ошибка");
			return;
		}
	}
	remove(ConvertStringToChar(Application::StartupPath + "\\users\\newUser.tmp")); // Удаляем временный файл

	MessageBox::Show("Пользователь. Теперь вы можете авторизироваться в главном меню.", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);

	toForm = true;
	this->Close(); // Закрытие текущей формы.
	mainMenu->Show(); // Открытие созданной формы.
	this->Cursor = System::Windows::Forms::Cursors::Default;
}

System::Void Prog::RegistrationForm::buttonCreateUser_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	if (surnameConfirmed && nameConfirmed && prozvConfirmed && birthdayConfirmed && passwordConfirmed) { // Проверяем флаги подтвеждения
		Users user;

		std::string name = "", path = "", pass = "";
		ConvertStringToSTDString(Application::StartupPath + "\\users\\newUser.tmp", path);
		ConvertStringToSTDString(this->maskedTextBoxSurname->Text->ToString(), name);
		user.surname = name;
		ConvertStringToSTDString(this->maskedTextBoxName->Text->ToString(), name);
		user.name = name;
		DateTime date = this->dateTimePickerBirthday->Value;
		user.birthday.day = date.Day;
		user.birthday.month = date.Month;
		user.birthday.year = date.Year;
		ConvertStringToSTDString(this->maskedTextBoxProzv->Text->ToString(), name);
		user.prozv = name;
		user.surnameNP = user.surname + " " + user.name[0] + "." + user.prozv[0] + ".";
		ConvertStringToSTDString(this->maskedTextBoxPassword->Text->ToString(), pass);
		user.password = pass;


		std::ofstream queueFile(path, std::ios::out | std::ios::trunc);
		if (!queueFile) {
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("Ошибка открытия файла для записи очереди!\nПовторите попытку позже.", "Ошибка");
			return;
		}
		else {
			if (!(queueFile << user)) { // Записываем нового пользователя во временный файл
				this->Cursor = System::Windows::Forms::Cursors::Default;
				queueFile.close();
				MessageBox::Show("Ошибка в момент записи очереди!", "Ошибка");
				return;
			}
			queueFile.close();
			ConvertStringToSTDString(Application::StartupPath + "\\users\\newUser.tmp", path);

			std::ifstream currentFile(path, std::ios::in);
			if (!currentFile) {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("Ошибка при открытии файла!\nВозможно файл очереди не создался и она не будет отрисована.\nПожалуйста, убедитесь, что файл был создан.", "Ошибка");
				return;
			}
			else {
				Users user1;
				user.password = pass;

				if (currentFile >> &user1) { // Читаем пользователя из временного файла для проверки
					currentFile.close();
					this->buttonSaveUser->Enabled = true;
				}
				else {
					currentFile.close();
					this->Cursor = System::Windows::Forms::Cursors::Default;
					MessageBox::Show("Не удалось прочитать пользователя.\nВозможно вам стоит пересоздать файл пользователя.", "Ошибка");
					return;
				}
			}
			this->Cursor = System::Windows::Forms::Cursors::Default;
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("Пользователь был успешно создан и помещен в папку ..\\users\\\nДля сохранения пользователя, нажмите кнопку \"Продолжить\", для коррекции данных - \"Отмена\"", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else { // Иначе собираем список необходимых для подтвеждения полей
		System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
		strings->Append("Для продолжения неободимо: ");
		strings->AppendLine();

		if (!surnameConfirmed) {
			strings->Append("Заполнить/подтвердить поле Фамилия.");
			strings->AppendLine();
		}
		if (!nameConfirmed) {
			strings->Append("Заполнить/подтвердить поле Имя.");
			strings->AppendLine();
		}
		if (!prozvConfirmed) {
			strings->Append("Заполнить/подтвердить поле Отчество.");
			strings->AppendLine();
		}
		if (!birthdayConfirmed) {
			strings->Append("Заполнить/подтвердить поле Дата рождения.");
			strings->AppendLine();
		}
		if (!passwordConfirmed) {
			strings->Append("Заполнить/подтвердить поле Пароль пользователя.");
			strings->AppendLine();
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show(strings->ToString(), "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void Prog::RegistrationForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Данная программа создана для записи в очередь в поликлинику.\n\nАвтор программы:\t(c) Бриль А.Э., Т-893", "О программе", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::RegistrationForm::RegistrationForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(5); // Создаем справку для данной формы
	form->Show();
}

