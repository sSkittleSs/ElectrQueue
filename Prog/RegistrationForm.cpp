#include "RegistrationForm.h"

System::Void Prog::RegistrationForm::RegistrationForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
			if (this->buttonSaveUser->Enabled)
				remove(ConvertStringToChar(Application::StartupPath + "\\users\\newUser.tmp"));

			Application::Exit();
		}
		else
			e->Cancel = true;
}

System::Void Prog::RegistrationForm::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->buttonSaveUser->Enabled)
		remove(ConvertStringToChar(Application::StartupPath + "\\users\\newUser.tmp")); // ������� ��������� ����

	toForm = true;
	this->Close();
	mainMenu->Show();
}

System::Void Prog::RegistrationForm::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->buttonSaveUser->Enabled)
			remove(ConvertStringToChar(Application::StartupPath + "\\users\\newUser.tmp")); // ������� ��������� ����
		Application::Exit();
	}
}

System::Void Prog::RegistrationForm::buttonConfirmSurname_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����������� ������� �������?\n����� ������� �� \"OK\" �������� �������� ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxSurname->Text == "" || this->maskedTextBoxSurname->Text == "������� �������") {
			MessageBox::Show("���� �� ������ ���� ������ ��� �� ����� ����������� �����.", "��������!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		surnameConfirmed = true;
		this->buttonConfirmSurname->Enabled = false;
		this->maskedTextBoxSurname->Enabled = false;
	}
}

System::Void Prog::RegistrationForm::buttonConfirmName_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����������� ������� ���?\n����� ������� �� \"OK\" �������� �������� ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxName->Text == "" || this->maskedTextBoxName->Text == "������� ���") {
			MessageBox::Show("���� �� ������ ���� ������ ��� �� ����� ����������� �����.", "��������!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		nameConfirmed = true;
		this->buttonConfirmName->Enabled = false;
		this->maskedTextBoxName->Enabled = false;
	}
}

System::Void Prog::RegistrationForm::buttonConfirmProzv_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����������� ������� ��������?\n����� ������� �� \"OK\" �������� �������� ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxProzv->Text == "" || this->maskedTextBoxProzv->Text == "������� ��������") {
			MessageBox::Show("���� �� ������ ���� ������ ��� �� ����� ����������� �����.", "��������!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		prozvConfirmed = true;
		this->buttonConfirmProzv->Enabled = false;
		this->maskedTextBoxProzv->Enabled = false;
	}
}

System::Void Prog::RegistrationForm::buttonConfirmBirthday_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����������� ������� ���� ��������?\n����� ������� �� \"OK\" �������� �������� ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->dateTimePickerBirthday->Value == DateTime::Today) {
			MessageBox::Show("������������ ���� ��������.", "��������!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		birthdayConfirmed = true;
		this->buttonConfirmBirthday->Enabled = false;
		this->dateTimePickerBirthday->Enabled = false;
	}
}

System::Void Prog::RegistrationForm::buttonConfirmPassword_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����������� ������� ������ ��� ������������?\n������: " + this->maskedTextBoxPassword->Text->ToString() + "\n����� ������� �� \"OK\" �������� �������� ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxPassword->Text == "" || this->maskedTextBoxPassword->Text == "������� ������ ��� ������ ������������") {
			MessageBox::Show("���� �� ������ ���� ������ ��� �� ����� ����������� �����.", "��������!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
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

System::Void Prog::RegistrationForm::buttonCorrection_Click(System::Object^ sender, System::EventArgs^ e) { // ��������� ������ � ��������� ������.
	if (this->buttonSaveUser->Enabled) {
		this->buttonSaveUser->Enabled = false;
		remove(ConvertStringToChar(Application::StartupPath + "\\users\\newUser.tmp")); // ������� ��������� ����
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
		MessageBox::Show("������ ��� �������� �����!\n�������� ������� ����� �� ����������,\n���� ���� ������ �������.", "������");
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
				MessageBox::Show("������ �������� ����� ��� ������ ������������!\n��������� ������� �����.", "������");
				return;
			}
			else {
				if (!(queueFile << user)) { // ������� ������������ � ����� ���� �������������
					this->Cursor = System::Windows::Forms::Cursors::Default;
					queueFile.close();
					MessageBox::Show("������ � ������ ������ ������������!", "������");
					return;
				}
				queueFile.close();
			}
		}
		else {
			currentFile.close();
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("�� ������� ��������� ���� �������������.", "������");
			return;
		}
	}
	remove(ConvertStringToChar(Application::StartupPath + "\\users\\newUser.tmp")); // ������� ��������� ����

	MessageBox::Show("������������. ������ �� ������ ���������������� � ������� ����.", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);

	toForm = true;
	this->Close(); // �������� ������� �����.
	mainMenu->Show(); // �������� ��������� �����.
	this->Cursor = System::Windows::Forms::Cursors::Default;
}

System::Void Prog::RegistrationForm::buttonCreateUser_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	if (surnameConfirmed && nameConfirmed && prozvConfirmed && birthdayConfirmed && passwordConfirmed) { // ��������� ����� ������������
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
			MessageBox::Show("������ �������� ����� ��� ������ �������!\n��������� ������� �����.", "������");
			return;
		}
		else {
			if (!(queueFile << user)) { // ���������� ������ ������������ �� ��������� ����
				this->Cursor = System::Windows::Forms::Cursors::Default;
				queueFile.close();
				MessageBox::Show("������ � ������ ������ �������!", "������");
				return;
			}
			queueFile.close();
			ConvertStringToSTDString(Application::StartupPath + "\\users\\newUser.tmp", path);

			std::ifstream currentFile(path, std::ios::in);
			if (!currentFile) {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("������ ��� �������� �����!\n�������� ���� ������� �� �������� � ��� �� ����� ����������.\n����������, ���������, ��� ���� ��� ������.", "������");
				return;
			}
			else {
				Users user1;
				user.password = pass;

				if (currentFile >> &user1) { // ������ ������������ �� ���������� ����� ��� ��������
					currentFile.close();
					this->buttonSaveUser->Enabled = true;
				}
				else {
					currentFile.close();
					this->Cursor = System::Windows::Forms::Cursors::Default;
					MessageBox::Show("�� ������� ��������� ������������.\n�������� ��� ����� ����������� ���� ������������.", "������");
					return;
				}
			}
			this->Cursor = System::Windows::Forms::Cursors::Default;
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("������������ ��� ������� ������ � ������� � ����� ..\\users\\\n��� ���������� ������������, ������� ������ \"����������\", ��� ��������� ������ - \"������\"", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else { // ����� �������� ������ ����������� ��� ������������ �����
		System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
		strings->Append("��� ����������� ���������: ");
		strings->AppendLine();

		if (!surnameConfirmed) {
			strings->Append("���������/����������� ���� �������.");
			strings->AppendLine();
		}
		if (!nameConfirmed) {
			strings->Append("���������/����������� ���� ���.");
			strings->AppendLine();
		}
		if (!prozvConfirmed) {
			strings->Append("���������/����������� ���� ��������.");
			strings->AppendLine();
		}
		if (!birthdayConfirmed) {
			strings->Append("���������/����������� ���� ���� ��������.");
			strings->AppendLine();
		}
		if (!passwordConfirmed) {
			strings->Append("���������/����������� ���� ������ ������������.");
			strings->AppendLine();
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show(strings->ToString(), "��������!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void Prog::RegistrationForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("������ ��������� ������� ��� ������ � ������� � �����������.\n\n����� ���������:\t(c) ����� �.�., �-893", "� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::RegistrationForm::RegistrationForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(5); // ������� ������� ��� ������ �����
	form->Show();
}

