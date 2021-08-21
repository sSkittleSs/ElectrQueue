#include "CreateNewQueueForm.h"

System::Void Prog::CreateNewQueueForm::CreateNewQueueForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
			if (this->buttonContinue->Enabled)
				remove(ConvertStringToChar(file + ".tmp")); // ������� ��������� ����.

			Application::Exit();
		}
		else
			e->Cancel = true;
}

System::Void Prog::CreateNewQueueForm::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->buttonContinue->Enabled)
		remove(ConvertStringToChar(file + ".tmp")); // ������� ��������� ����.

	toForm = true;
	this->Close(); // �������� ������� �����.
	this->mainMenu->Show(); // �������� ��������� �����.
}

System::Void Prog::CreateNewQueueForm::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->buttonContinue->Enabled)
			remove(ConvertStringToChar(file + ".tmp")); // ������� ��������� ����.
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
	if (MessageBox::Show("�� �������, ��� ������ ����������� ������� �������� �������?\n����� ������� �� \"OK\" �������� �������� ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxTitle->Text == "" || this->maskedTextBoxTitle->Text == "������� �������� ������� (����)") {
			MessageBox::Show("���� �� ������ ���� ������ ��� �� ����� ����������� �����.", "��������!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		titleConfirmed = true; // ��������� ���� ������������� � ��������� true � ��������� ������ ��� ���������
		this->buttonConfirmTitle->Enabled = false;
		this->maskedTextBoxTitle->Enabled = false;
	}
}

System::Void Prog::CreateNewQueueForm::buttonConfirmFileName_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����������� ������� �������� �����?\n����� ������� �� \"OK\" �������� �������� ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxFileName->Text == "" || this->maskedTextBoxFileName->Text == "������� ��� ����� (��� ����������)") {
			MessageBox::Show("���� �� ������ ���� ������ ��� �� ����� ����������� �����.", "��������!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		fileNameConfirmed = true; // ��������� ���� ������������� � ��������� true � ��������� ������ ��� ���������
		this->buttonConfirmFileName->Enabled = false;
		this->maskedTextBoxFileName->Enabled = false;

		file = Application::StartupPath + "\\queues\\" + this->maskedTextBoxFileName->Text->ToString();

		array<String^>^ fileNames = System::IO::Directory::GetFiles(Application::StartupPath + "\\queues");
		for (int i = 0; i < fileNames->Length; i++) {
			if (System::IO::Path::GetFileNameWithoutExtension(fileNames[i]) == this->maskedTextBoxFileName->Text->ToString())
				if (MessageBox::Show("���� � ����� ������ ��� ����������. ��� �������� ������� ������ ���������� � ����� ����� ������������.\n\n�� �������, ��� ������ ����������?", "��������!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Cancel) {
					fileNameConfirmed = false; // ��������� ���� ������������� � ��������� false � ������������ ������ ��� ���������
					file = "";
					this->buttonConfirmFileName->Enabled = true;
					this->maskedTextBoxFileName->Enabled = true;
				}
		}
	}
}

System::Void Prog::CreateNewQueueForm::buttonConfirmTime_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->numericUpDownMinutesEnd->Value != 0 && this->numericUpDownMinutesEnd->Value != 30) {
		MessageBox::Show("����� ����� ������ (������) ������ ���� ����� 0 ��� 30.", "��������!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (this->numericUpDownMinutesStart->Value != 0 && this->numericUpDownMinutesStart->Value != 30) {
		MessageBox::Show("����� ������ ������ (������) ������ ���� ����� 0 ��� 30.", "��������!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (this->numericUpDownHoursEnd->Value == this->numericUpDownHoursStart->Value && this->numericUpDownMinutesEnd->Value == this->numericUpDownMinutesStart->Value) {
		MessageBox::Show("����� ������ ������ � ����� ������ �� ����� ���������.", "��������!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if ((Convert::ToInt32(this->numericUpDownMinutesEnd->Value) + Convert::ToInt32(this->numericUpDownHoursEnd->Value) * 10) < (Convert::ToInt32(this->numericUpDownMinutesStart->Value) + Convert::ToInt32(this->numericUpDownHoursStart->Value) * 10)) {
		MessageBox::Show("����� ����� ������ �� ������ ���� ������, ��� ����� ����� ������.", "��������!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	else
		if (MessageBox::Show("�� �������, ��� ������ ����������� ������� �������� �����?\n����� ������� �� \"OK\" �������� �������� ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
			timeConfirmed = true; // ��������� ���� ������������� � ��������� true � ��������� ������ ��� ���������
			this->buttonConfirmTime->Enabled = false;
			this->numericUpDownHoursEnd->Enabled = false;
			this->numericUpDownMinutesEnd->Enabled = false;
			this->numericUpDownHoursStart->Enabled = false;
			this->numericUpDownMinutesStart->Enabled = false;
		}
}

System::Void Prog::CreateNewQueueForm::buttonConfirmPassword_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����������� ������� ������ ��� �������?\n������: " + this->maskedTextBoxPassword->Text->ToString() + "\n����� ������� �� \"OK\" �������� ������ ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->maskedTextBoxPassword->Text == "" || this->maskedTextBoxPassword->Text == "������� ������ �������������� �������") {
			MessageBox::Show("���� �� ������ ���� ������ ��� �� ����� ����������� �����.", "��������!", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			return;
		}

		passwordConfirmed = true; // ��������� ���� ������������� � ��������� true � ��������� ������ ��� ���������
		this->buttonConfirmPassword->Enabled = false;
		this->maskedTextBoxPassword->Enabled = false;
	}
}

System::Void Prog::CreateNewQueueForm::buttonConfirmDate_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����������� ������� ���� ������?\n����� ������� �� \"OK\" �������� ���� ����� ��� ������.", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		dateConfirmed = true; // ��������� ���� ������������� � ��������� true � ��������� ������ ��� ���������
		this->buttonConfirmDate->Enabled = false;
		this->dateTimePickerDate->Enabled = false;
	}
}

System::Void Prog::CreateNewQueueForm::buttonCreateQueue_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	if (titleConfirmed && fileNameConfirmed && timeConfirmed && passwordConfirmed) { // ���� ��� ���� ������������
		size_t start{}, end{}, counter{ 1 };
		start = Convert::ToInt32(this->numericUpDownHoursStart->Value) * 2 + Convert::ToInt32(this->numericUpDownMinutesStart->Value) / 30; // ����������� ��������� �������� ��� �����
		end = Convert::ToInt32(this->numericUpDownHoursEnd->Value) * 2 + Convert::ToInt32(this->numericUpDownMinutesEnd->Value) / 30; // ����������� �������� �������� ��� �����

		ownTime time;
		MyQueue<queueData> que;
		for (size_t i = start; i <= end; i++) { // ���� �� ������ �� ����� � ���������� �������� �������� �� ���������� �������
			time.hours = i / 2;
			time.minutes = (i * 30) % 60;
			queueData data(time, counter++, "����� �� ������");
			que.queue(data); // �������� ����������� ������ �� ���������� �������
		}

		std::string title = "", path = "", pass = ""; // ������ ���� ������� �� ��, ������� � �����������
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

		std::ofstream queueFile(que.GetFileName(), std::ios::out | std::ios::trunc); // �� ���������� ���� � ������� ��������� �����
		if (!queueFile) {
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("������ �������� ����� ��� ������ �������!\n��������� ������� �����.", "������");
			return;
		}
		else {
			if (!(queueFile << que)) { // ���� ������� �� ������������ ������ ������, ����� ��������� ����� � ������ ������� ������, ������ �������.
				this->Cursor = System::Windows::Forms::Cursors::Default;
				queueFile.close();
				MessageBox::Show("������ � ������ ������ �������!", "������");
				return;
			}
			queueFile.close();

			std::ifstream currentFile(path, std::ios::in);
			if (!currentFile) {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("������ ��� �������� �����!\n�������� ���� ������� �� �������� � ��� �� ����� ����������.\n����������, ���������, ��� ���� ��� ������.", "������");
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
					MessageBox::Show("�� ������� ��������� ������� �� ���������� �����.\n�������� ��� ����� ����������� ���� �������.", "������");
					return;
				}
			}
			this->Cursor = System::Windows::Forms::Cursors::Default;
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("������� ���� ������� ������� � �������� � ����� ..\\queues\\\n��� ���������� �������, ������� ������ \"����������\", ��� ��������� ������ - \"������\"", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else { // ����� ���������� ������ ����������� �������������.
		System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
		strings->Append("��� ����������� ���������: ");
		strings->AppendLine();

		if (!titleConfirmed) {
			strings->Append("���������/����������� ���� ����� �������.");
			strings->AppendLine();
		}
		if (!fileNameConfirmed) {
			strings->Append("���������/����������� ���� ����� �����.");
			strings->AppendLine();
		}
		if (!timeConfirmed) {
			strings->Append("���������/����������� ���� ������� ������.");
			strings->AppendLine();
		}
		if (!passwordConfirmed) {
			strings->Append("���������/����������� ���� ������ �������������� �������.");
			strings->AppendLine();
		}
		if (!dateConfirmed) {
			strings->Append("���������/����������� ���� ���� ������ �������.");
			strings->AppendLine();
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show(strings->ToString(),"��������!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void Prog::CreateNewQueueForm::SetupDataGridView(std::string path) {  // ������ ��� ��� ��������������� � mainForm.cpp
	this->dataGridView1->Rows->Clear();

	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	this->dataGridView1->ColumnCount = 3;

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("������ ��� �������� ����� �������!\n�������� ���� ���������.\n���������� ������� ������ ������� �����.", "������");
		return;
	}
	else {
		MyQueue<queueData> que;
		if (currentFile >> que) {
			currentFile.close();

			this->QueueBox->Text = "������������ ������� �� ����� " + ConvertSTDStringToString(que.GetTitle()) + " (" + Convert::ToString(que.length()) + ")";
			this->dataGridView1->Columns[0]->Width = 20;
			this->dataGridView1->Columns[0]->Name = "�";
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
			MessageBox::Show("�� ������� ��������� ������� �� ���������� �����.\n�������� ���� ���������.\n���������� ������� ������ ������� �����.", "������");
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
		MessageBox::Show("������ ��� �������� �����!\n�������� ������� ����� �� ����������,\n���� ���� ������ �������.", "������");
		return;
	}
	else {
		MyQueue<queueData> que;
		if (currentFile >> que) { // ������ ������� �� ���������� �����
			currentFile.close();
			SetupDataGridView(path);
			ConvertStringToSTDString(file + ".txt", path);
			que.SetFileName(path);

			std::ofstream queueFile(path, std::ios::out | std::ios::trunc);
			if (!queueFile) {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("������ �������� ����� ��� ������ �������!\n��������� ������� �����.", "������");
				return;
			}
			else {
				if (!(queueFile << que)) { // �������� ������� � �������� ����
					this->Cursor = System::Windows::Forms::Cursors::Default;
					queueFile.close();
					MessageBox::Show("������ � ������ ������ �������!", "������");
					return;
				}
				queueFile.close();
			}
		}
		else {
			currentFile.close();
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("�� ������� ��������� ������� �� ���������� �����.", "������");
			return;
		}
	}
	remove(ConvertStringToChar(file + ".tmp")); // ������� ��������� ����.
	
	MessageBox::Show("������� ������� ���������. ������ �� ������ ������� ������ ������� � ������� ����.", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);

	toForm = true;
	this->Close(); // �������� ������� �����.
	mainMenu->Show(); // �������� ��������� �����.
	this->Cursor = System::Windows::Forms::Cursors::Default;
}

System::Void Prog::CreateNewQueueForm::buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) { // ��������� ������ � ��� �������, � ������� ��� �������� ������ � ��������� �����
	if (this->buttonContinue->Enabled) { 
		this->buttonContinue->Enabled = false;
		this->dataGridView1->Rows->Clear();
		this->dataGridView1->Columns->Clear();
		remove(ConvertStringToChar(file + ".tmp")); // ������� ��������� ����.
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

System::Void Prog::CreateNewQueueForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("������ ��������� ������� ��� ������ � ������� � �����������.\n\n����� ���������:\t(c) ����� �.�., �-893", "� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::CreateNewQueueForm::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toForm = true;
	OpenQueueFileForm^ form = gcnew OpenQueueFileForm(mainMenu); // �������� �����.
	this->Close(); // �������� ������� �����.
	form->Show(); // �������� ��������� �����.
}

System::Void Prog::CreateNewQueueForm::CreateNewQueueForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(3); // ������� ������� ��� ������ �����.
	form->Show();
}

