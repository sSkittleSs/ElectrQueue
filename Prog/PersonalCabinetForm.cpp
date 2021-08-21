#include "PersonalCabinetForm.h"

System::Void Prog::PersonalCabinetForm::setupData() { 
	std::string path = "";
	ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.txt", path);
	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		MessageBox::Show("������ �������� ����� ��� ������ ������ � ������������!", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		toForm = true;
		this->Close(); // �������� ������� �����.
		this->mainMenu->Show(); // �������� ��������� �����.
	}
	else {
		Users user;
		if (currentFile >> &user) { // ���� ������������ ��������, �� ������� ��� ������ � ������������
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
		else { // ����� ��������� ����� � ������ ������
			MessageBox::Show("������ ������ ������ � ������������!", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			toForm = true;
			this->Close(); // �������� ������� �����.
			this->mainMenu->Show(); // �������� ��������� �����.
			currentFile.close();
		}
	}
}

System::Void Prog::PersonalCabinetForm::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toForm = true;
	this->Close(); // �������� ������� �����.
	this->mainMenu->Show(); // �������� ��������� �����.
}

System::Void Prog::PersonalCabinetForm::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		Application::Exit();
}

System::Void Prog::PersonalCabinetForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("������ ��������� ������� ��� ����������� ������� �������.\n\n����� ���������:\t(c) ����� �.�., �-893", "� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::PersonalCabinetForm::buttonGetAllRecords_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string path;
	ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);

	array<String^>^ fileNames = System::IO::Directory::GetFiles(Application::StartupPath + "\\queues");
	System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
	strings->Append("���� ������ � ������:");
	strings->AppendLine();
	for (size_t i = 0; i < fileNames->Length; i++) { // ���� �� ���� ������

		ConvertStringToSTDString(fileNames[i], path);

		if (fileNames[i] == Application::StartupPath + "\\queues\\currentQueue.txt") // ���� ���� �������� ������� ��������, �� ���������� (���� �� ���� ������� �����������)
			continue;

		std::ifstream currentFile(path, std::ios::in);
		if (!currentFile) {
			continue;
		}
		else {
			MyQueue<queueData> que;
			if (currentFile >> que) { // ���� ������� ��������
				currentFile.close();

				Node<queueData>* toSet{ que.beg() };
				size_t nempty = 0;
				while (toSet) { // ���� ������������ � ��������� ���������� � ������
					std::string SurnameNP;
					ConvertStringToSTDString(this->labelInfoSurnameNP->Text, SurnameNP);
					if (toSet->data.surnameNP == SurnameNP) {
						strings->Append("---------------------");
						strings->AppendLine();
						String^ title = ConvertSTDStringToString(que.GetTitle());
						strings->AppendFormat("����: {0}\n���� ������: {1}.{2}.{3}\n����� � �������: {4}\n����� ������: {5}:{6}\n���� �������: {7}", title, que.Day(), que.Month(), que.Year(), toSet->data.ownNumber, toSet->data.time.hours, toSet->data.time.minutes, System::IO::Path::GetFileName(fileNames[i]));
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
	MessageBox::Show(strings->ToString(), "����������", MessageBoxButtons::OK, MessageBoxIcon::Information); // ������� ��� ����������
	return;
}

System::Void Prog::PersonalCabinetForm::buttonGetRecord_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;

	openFileDialog->InitialDirectory = Application::StartupPath;
	openFileDialog->Filter = "txt files (*.txt)|*.txt";
	openFileDialog->FilterIndex = 1;
	openFileDialog->RestoreDirectory = true;

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) // ��������� ���������� ���� ������ � ��������� ������ �� �� 
	{
		std::string path;
		ConvertStringToSTDString(openFileDialog->FileName, path);

		System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
		strings->Append("���� ������ � ������:");
		strings->AppendLine();


		std::ifstream currentFile(path, std::ios::in);
		if (!currentFile) {
			MessageBox::Show("���������� ������� ��������� ���� ����!", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		else {
			MyQueue<queueData> que;
			if (currentFile >> que) { // ������ ������� �� ���������� �����
				currentFile.close();

				Node<queueData>* toSet{ que.beg() };
				size_t nempty = 0;
				while (toSet) { // ���� ��� ������ ������� ������������ � ��������� � ��� ����������
					std::string SurnameNP;
					ConvertStringToSTDString(this->labelInfoSurnameNP->Text, SurnameNP);
					if (toSet->data.surnameNP == SurnameNP) {
						strings->Append("---------------------");
						strings->AppendLine();
						String^ title = ConvertSTDStringToString(que.GetTitle());
						strings->AppendFormat("����: {0}\n���� ������: {1}.{2}.{3}\n����� � �������: {4}\n����� ������: {5}:{6}\n���� �������: {7}", title, que.Day(), que.Month(), que.Year(), toSet->data.ownNumber, toSet->data.time.hours, toSet->data.time.minutes, openFileDialog->FileName);
						strings->AppendLine();
					}
					toSet = toSet->next;
				}

			}
			else {
				MessageBox::Show("���������� ��������� ������� �� ���������� �����!", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
		}

		MessageBox::Show(strings->ToString(), "����������", MessageBoxButtons::OK, MessageBoxIcon::Information); // ������� ����������
		return;

	}
}

System::Void Prog::PersonalCabinetForm::PersonalCabinetForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
			Application::Exit();
		else
			e->Cancel = true;
}

System::Void Prog::PersonalCabinetForm::PersonalCabinetForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(7); // ������� ����� � �������� ����� �����.
	form->Show();
}
