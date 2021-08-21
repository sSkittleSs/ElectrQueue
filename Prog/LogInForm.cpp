#include "LogInForm.h"

System::Void Prog::LogInForm::LogInForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
			if (this->buttonContinue->Enabled)
				remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.tmp"));

			Application::Exit();
		}
		else
			e->Cancel = true;
}

System::Void Prog::LogInForm::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->buttonContinue->Enabled)
		remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.tmp")); // ������� ��������� ����

	toForm = true;
	this->Close();
	mainMenu->Show();
}

System::Void Prog::LogInForm::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->buttonContinue->Enabled)
			remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.tmp")); // ������� ��������� ����
		Application::Exit();
	}
}

System::Void Prog::LogInForm::buttonConfirmSurname_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����������� ������� �������?\n����� ������� �� \"OK\" �������� �������� ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxSurname->Text == "" || this->maskedTextBoxSurname->Text == "������� �������") {
			MessageBox::Show("���� �� ������ ���� ������ ��� �� ����� ����������� �����.", "��������!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		surnameConfirmed = true; // ��������� ���� ������������� � ��������� true � ��������� ������ ��� ���������
		this->buttonConfirmSurname->Enabled = false;
		this->maskedTextBoxSurname->Enabled = false;
	}
}

System::Void Prog::LogInForm::buttonConfirmBirthday_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����������� ������� ���� ��������?\n����� ������� �� \"OK\" �������� �������� ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->dateTimePickerBirthday->Value == DateTime::Today) {
			MessageBox::Show("������������ ���� ��������.", "��������!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		birthdayConfirmed = true; // ��������� ���� ������������� � ��������� true � ��������� ������ ��� ���������
		this->buttonConfirmBirthday->Enabled = false;
		this->dateTimePickerBirthday->Enabled = false;
	}
}

System::Void Prog::LogInForm::buttonLogIn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	if (surnameConfirmed && birthdayConfirmed) { // ��������� ����� �������������

		std::string name = "", path = "", pass = "";
		ConvertStringToSTDString(Application::StartupPath + "\\users\\users.txt", path);
		ConvertStringToSTDString(this->maskedTextBoxSurname->Text->ToString(), name);

		DateTime date = this->dateTimePickerBirthday->Value;

		std::ifstream currentFile(path, std::ios::in);
		if (!currentFile) {
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("������ ��� �������� ����� �������������!\n���������� ��� ���.", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		else {
			Users user1;
			bool passwordIsCorrect = false;
			while (currentFile >> &user1 && (user1.surname != name || user1.birthday.day != date.Day || user1.birthday.month != date.Month || user1.birthday.year != date.Year)) {
				// ���� ������������, ����� ���
			}
			currentFile.close();
			if (user1.surname == name && user1.birthday.day == date.Day && user1.birthday.month == date.Month && user1.birthday.year == date.Year) {
				CheckPassForm^ form = gcnew CheckPassForm(this, &passwordIsCorrect, &user1);

				switch (form->ShowDialog()) { // ���� ����� ������� ������������, ����������� ������ ������
				case System::Windows::Forms::DialogResult::OK: { // ���� ������ ������, �� ���������� ������� ������������, ��� �������� �� ��������� ����.
					this->buttonContinue->Enabled = true;
					MessageBox::Show("����������� ������ �������!\n��� ����������� (����������) ������� ������ \"����������\".", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
					
					ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.tmp", path);

					std::ofstream queueFile(path, std::ios::out | std::ios::trunc);
					if (!queueFile) {
						this->Cursor = System::Windows::Forms::Cursors::Default;
						MessageBox::Show("������ �������� ����� ��� ������ ������������!\n��������� ������� �����.", "������");
						return;
					}
					else {
						if (!(queueFile << user1)) {
							this->Cursor = System::Windows::Forms::Cursors::Default;
							queueFile.close();
							MessageBox::Show("������ � ������ ������ ������������!", "������");
							return;
						}
						queueFile.close();
					}
					
					break;
				}
				case System::Windows::Forms::DialogResult::Abort: { // ���� ������ �� ������
					this->buttonContinue->Enabled = false;
					MessageBox::Show("����������� �� ���� ���������, ��������� ������ ��� ������ �� �����.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					break;
				}
				case System::Windows::Forms::DialogResult::Cancel: { // ���� ����� �������� ������ �������
					form->Close();
					this->buttonContinue->Enabled = false;
					MessageBox::Show("����������� �� ���� ���������, ��������� ����� ���� �������.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					break;
				}
				}

			}
			else {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("�� ������� ����� ������� ������������.\n�������� ��� ����� ����������� ���� ������������ ��� ��������� ������.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			//this->buttonContinue->Enabled = true;

		}
		
		this->Cursor = System::Windows::Forms::Cursors::Default;
		//MessageBox::Show("����������� ������ �������!", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else { // ����� �������� ����������� ��� ������������ �������������
		System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
		strings->Append("��� ����������� ���������: ");
		strings->AppendLine();

		if (!surnameConfirmed) {
			strings->Append("���������/����������� ���� �������.");
			strings->AppendLine();
		}
		if (!birthdayConfirmed) {
			strings->Append("���������/����������� ���� ���� ��������.");
			strings->AppendLine();
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show(strings->ToString(), "��������!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void Prog::LogInForm::buttonCorrection_Click(System::Object^ sender, System::EventArgs^ e) { // ��������� ������ � �������������� ������
	if (this->buttonContinue->Enabled) {
		this->buttonContinue->Enabled = false;
		remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.tmp")); // ������� ��������� ����
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
		MessageBox::Show("������ ��� �������� ����� ������������!\n", "������");
		return;
	}
	else {
		Users user;
		if (currentFile >> &user) { // ������ ��������� ����
			currentFile.close();
			ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.txt", path);

			std::ofstream queueFile(path, std::ios::out | std::ios::trunc); // �������� ������������ � �������� ���� �������� ������������.
			if (!queueFile) {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("������ �������� ����� ��� ������ ������������!\n��������� ������� �����.", "������");
				return;
			}
			else {
				if (!(queueFile << user)) {
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
	remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.tmp")); // ������� ��������� ����

	MessageBox::Show("������� ������������ ������� �������.", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);

	toForm = true;
	this->Close(); // �������� ������� �����.
	mainMenu->Show(); // �������� ��������� �����.
	this->Cursor = System::Windows::Forms::Cursors::Default;
}

System::Void Prog::LogInForm::maskedTextBoxSurname_Click(System::Object^ sender, System::EventArgs^ e) {
	this->maskedTextBoxSurname->Text = "";
}

System::Void Prog::LogInForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("������ ��������� ������� ��� ������ � ������� � �����������.\n\n����� ���������:\t(c) ����� �.�., �-893", "� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::LogInForm::LogInForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(6); // ������� ������� ��� ����� ����.
	form->Show();
}
