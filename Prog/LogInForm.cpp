#include "LogInForm.h"

System::Void Prog::LogInForm::LogInForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
			if (this->buttonContinue->Enabled)
				remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.tmp"));

			Application::Exit();
		}
		else
			e->Cancel = true;
}

System::Void Prog::LogInForm::выйтиВГлавноеМенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->buttonContinue->Enabled)
		remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.tmp")); // Удаляем временный файл

	toForm = true;
	this->Close();
	mainMenu->Show();
}

System::Void Prog::LogInForm::выходИзПрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите выйти из программы?", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->buttonContinue->Enabled)
			remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.tmp")); // Удаляем временный файл
		Application::Exit();
	}
}

System::Void Prog::LogInForm::buttonConfirmSurname_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите подтвердить текущую Фамилию?\nПосле нажатия на \"OK\" изменить название будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxSurname->Text == "" || this->maskedTextBoxSurname->Text == "Введите Фамилию") {
			MessageBox::Show("Поле не должно быть пустым или же иметь стандартный текст.", "Внимание!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		surnameConfirmed = true; // Переводим флаг подтверждение в положение true и блокируем кнопки для изменения
		this->buttonConfirmSurname->Enabled = false;
		this->maskedTextBoxSurname->Enabled = false;
	}
}

System::Void Prog::LogInForm::buttonConfirmBirthday_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Вы уверены, что хотите подтвердить текущую дату рождения?\nПосле нажатия на \"OK\" изменить название будет уже нельзя.", "Подтверждение", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->dateTimePickerBirthday->Value == DateTime::Today) {
			MessageBox::Show("Некорректная дата рождения.", "Внимание!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		birthdayConfirmed = true; // Переводим флаг подтверждение в положение true и блокируем кнопки для изменения
		this->buttonConfirmBirthday->Enabled = false;
		this->dateTimePickerBirthday->Enabled = false;
	}
}

System::Void Prog::LogInForm::buttonLogIn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	if (surnameConfirmed && birthdayConfirmed) { // Проверяем флаги подтверждения

		std::string name = "", path = "", pass = "";
		ConvertStringToSTDString(Application::StartupPath + "\\users\\users.txt", path);
		ConvertStringToSTDString(this->maskedTextBoxSurname->Text->ToString(), name);

		DateTime date = this->dateTimePickerBirthday->Value;

		std::ifstream currentFile(path, std::ios::in);
		if (!currentFile) {
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("Ошибка при открытии файла пользователей!\nПопробуйте ещё раз.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		else {
			Users user1;
			bool passwordIsCorrect = false;
			while (currentFile >> &user1 && (user1.surname != name || user1.birthday.day != date.Day || user1.birthday.month != date.Month || user1.birthday.year != date.Year)) {
				// ищем пользователя, читая его
			}
			currentFile.close();
			if (user1.surname == name && user1.birthday.day == date.Day && user1.birthday.month == date.Month && user1.birthday.year == date.Year) {
				CheckPassForm^ form = gcnew CheckPassForm(this, &passwordIsCorrect, &user1);

				switch (form->ShowDialog()) { // Если нашли нужного пользователя, запрашиваем ввести пароль
				case System::Windows::Forms::DialogResult::OK: { // Если пароль верный, то записываем данного пользователя, как текущего во временный файл.
					this->buttonContinue->Enabled = true;
					MessageBox::Show("Авторизация прошла успешно!\nДля продолжения (сохранения) нажмите кнопку \"Продолжить\".", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
					
					ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.tmp", path);

					std::ofstream queueFile(path, std::ios::out | std::ios::trunc);
					if (!queueFile) {
						this->Cursor = System::Windows::Forms::Cursors::Default;
						MessageBox::Show("Ошибка открытия файла для записи пользователя!\nПовторите попытку позже.", "Ошибка");
						return;
					}
					else {
						if (!(queueFile << user1)) {
							this->Cursor = System::Windows::Forms::Cursors::Default;
							queueFile.close();
							MessageBox::Show("Ошибка в момент записи пользователя!", "Ошибка");
							return;
						}
						queueFile.close();
					}
					
					break;
				}
				case System::Windows::Forms::DialogResult::Abort: { // Если пароль не верный
					this->buttonContinue->Enabled = false;
					MessageBox::Show("Авторизация не была завершена, поскольку пароль был введен не верно.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					break;
				}
				case System::Windows::Forms::DialogResult::Cancel: { // Если форму проверки пароля закрыли
					form->Close();
					this->buttonContinue->Enabled = false;
					MessageBox::Show("Авторизация не была завершена, поскольку форма была закрыта.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					break;
				}
				}

			}
			else {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("Не удалось найти данного пользователя.\nВозможно вам стоит пересоздать файл пользователя или проверить данные.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			//this->buttonContinue->Enabled = true;

		}
		
		this->Cursor = System::Windows::Forms::Cursors::Default;
		//MessageBox::Show("Авторизация прошла успешно!", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else { // Иначе собираем необходимые для продолжнения подтверждения
		System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
		strings->Append("Для продолжения неободимо: ");
		strings->AppendLine();

		if (!surnameConfirmed) {
			strings->Append("Заполнить/подтвердить поле Фамилия.");
			strings->AppendLine();
		}
		if (!birthdayConfirmed) {
			strings->Append("Заполнить/подтвердить поле Дата рождения.");
			strings->AppendLine();
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show(strings->ToString(), "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void Prog::LogInForm::buttonCorrection_Click(System::Object^ sender, System::EventArgs^ e) { // Открываем доступ к редактированию данных
	if (this->buttonContinue->Enabled) {
		this->buttonContinue->Enabled = false;
		remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.tmp")); // Удаляем временный файл
	}
	if (surnameConfirmed) {
		surnameConfirmed = false;
		this->buttonConfirmSurname->Enabled = true;
		this->maskedTextBoxSurname->Enabled = true;
	}
	if (birthdayConfirmed) {
		birthdayConfirmed = false;
		this->buttonConfirmBirthday->Enabled = true;
		this->dateTimePickerBirthday->Enabled = true;
	}
	if (passwordConfirmed) {
		passwordConfirmed = false;
	}
}

System::Void Prog::LogInForm::buttonContinue_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	std::string path;
	ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.tmp", path);

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("Ошибка при открытии файла пользователя!\n", "Ошибка");
		return;
	}
	else {
		Users user;
		if (currentFile >> &user) { // Читаем временный файл
			currentFile.close();
			ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.txt", path);

			std::ofstream queueFile(path, std::ios::out | std::ios::trunc); // Помещаем пользователя в конечный файл текущего пользователя.
			if (!queueFile) {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("Ошибка открытия файла для записи пользователя!\nПовторите попытку позже.", "Ошибка");
				return;
			}
			else {
				if (!(queueFile << user)) {
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
	remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.tmp")); // Удаляем временный файл

	MessageBox::Show("Текущий пользователь успешно записан.", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);

	toForm = true;
	this->Close(); // Закрытие текущей формы.
	mainMenu->Show(); // Открытие созданной формы.
	this->Cursor = System::Windows::Forms::Cursors::Default;
}

System::Void Prog::LogInForm::maskedTextBoxSurname_Click(System::Object^ sender, System::EventArgs^ e) {
	this->maskedTextBoxSurname->Text = "";
}

System::Void Prog::LogInForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Данная программа создана для записи в очередь в поликлинику.\n\nАвтор программы:\t(c) Бриль А.Э., Т-893", "О программе", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::LogInForm::LogInForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(6); // Создаем справку для этого окна.
	form->Show();
}
