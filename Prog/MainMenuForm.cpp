#include "MainMenuForm.h" // ���������� ����� �������� ����

using namespace Prog;

[STAThreadAttribute] //������� ������������� ���������� (STA), ��� ����������� ������ OLE

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ����������� ������ (����), ��������� ���������� �������� �� ������, � �� ������� ������. 
	Application::EnableVisualStyles(); // ������������� ������������ ���������� ������ � �� ��������� ���������� �������.
	Application::SetCompatibleTextRenderingDefault(false); // ������������� ������������� ����������� ������� ������, ���� ������ �������� false
	Application::Run(gcnew MainMenuForm); // �������� ����� Run � �������� ��������� �� ����������� ��� �� ������������� ��������� ������ MyForm (���� �������� �����)
	return 0;
}

System::Void Prog::MainMenuForm::�����ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) { // ����������� ������������� � ������� �� ���������, � ������ "��".
	if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		Application::Exit();
}

System::Void Prog::MainMenuForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) { // ����� ������ � ���������
	MessageBox::Show("������ ��������� ������� ��� ������ � ������� � �����������.\n\n����� ���������:\t(c) ����� �.�., �-893", "� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::MainMenuForm::buttonExit_Click(System::Object^ sender, System::EventArgs^ e) { // ����������� ������������� � ������� �� ���������, � ������ "��".
	if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		Application::Exit();
}

System::Void Prog::MainMenuForm::buttonOpenQueueFile_Click(System::Object^ sender, System::EventArgs^ e) { // ��������� � ����� �������� ������.
	OpenQueueFileForm^ form = gcnew OpenQueueFileForm(this); // �������� �����.
	this->Hide(); // �������� ������� �����.
	form->Show(); // �������� ��������� �����.
}

System::Void Prog::MainMenuForm::buttonContinue_Click(System::Object^ sender, System::EventArgs^ e) { // ��������� � ������� ����� ������ � ��������
	MainForm^ form = gcnew MainForm(this); // �������� �����.
	this->Hide(); // �������� ������� �����.
	form->Show(); // �������� ��������� �����.
}

System::Void Prog::MainMenuForm::buttonCreateNewQueue_Click(System::Object^ sender, System::EventArgs^ e){
	CreateNewQueueForm^ form = gcnew CreateNewQueueForm(this); // �������� �����.
	this->Hide(); // �������� ������� �����.
	form->Show(); // �������� ��������� �����.
}

System::Void Prog::MainMenuForm::preset(System::Object^ sender, System::EventArgs^ e) { // �������� ����� � ������� (���������, � ������� ��������) ��������
	std::string path; // �� ������� � ������������� ������ "���������� ������" �� ���/���� � ����������� �� ������ � currentFile.
	ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path); // ������������ System::String � std::string � �������� � path.

	std::ifstream currentFile(path, std::ios::in); // ��������� ����� ��� ������.
	if (!currentFile) {
		this->buttonContinue->Enabled = false; // ���� ���� �� ������ ������� (�������� ��� ���), �� ��������� ������ "���������� ������" 
		return; // � ������� �� ������ �������.
	}
	else {
		MyQueue<queueData> que;
		if (currentFile.peek() != EOF && currentFile >> que) // ����� ��������� ���� �� ������ ����
			this->buttonContinue->Enabled = true; // ���� ���� �� ���� � ������ �������� �������, ��������.
		else 
			this->buttonContinue->Enabled = false; // ����� - ���������.
		currentFile.close(); // ��������� �����.
		return; // ������� �� �������.
	}
}

System::Void Prog::MainMenuForm::MainMenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing)
		if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
			Application::Exit();
		else
			e->Cancel = true;
}

System::Void Prog::MainMenuForm::timerCheck_Tick(System::Object^ sender, System::EventArgs^ e) {
	preset(sender, e); // ����������������� ������ "���������� ������"
	bool flag = this->buttonContinue->Enabled; // ������ ���� ����� ���������� ����������� �������� ������� �� �����, � ������������� ����������� ������ "���������� ������".
	std::string path = "";
	ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.txt", path); // ����������� System::String � std::string
	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) { // ���� ����� �� ��������, �� ����������������� ������ ��������� �������
		this->�����������ToolStripMenuItem->Text = "�����������";
		this->�����������ToolStripMenuItem->Visible = true;
		this->����ToolStripMenuItem->Visible = true;
		this->�����ToolStripMenuItem->Visible = false;
		this->�������������ToolStripMenuItem->Visible = false;
		currUser = "NONE";
		this->buttonContinue->Enabled = false;
		this->buttonOpenQueueFile->Enabled = false;
	}
	else { // �����
		Users user;
		if (currentFile >> &user) { // ���� ������������ �������� �� �����
			currentFile.close(); // ��������� �����

			currUser = gcnew System::String(user.surnameNP.c_str()); // ��������� std::string � System::String

			// ����� ����������������� ���������
			if (flag)
				this->buttonContinue->Enabled = true;
			this->buttonOpenQueueFile->Enabled = true;

			this->�����������ToolStripMenuItem->Text = "�������";
			this->����ToolStripMenuItem->Visible = false;
			this->�����������ToolStripMenuItem->Visible = false;
			this->�����ToolStripMenuItem->Visible = true;
			this->�������������ToolStripMenuItem->Visible = true;

		}
		else { // ����� ����������������� ��������� � ��������� �����.
			this->�����������ToolStripMenuItem->Text = "�����������";
			this->�����������ToolStripMenuItem->Visible = true;
			this->����ToolStripMenuItem->Visible = true;
			this->�����ToolStripMenuItem->Visible = false;
			this->�������������ToolStripMenuItem->Visible = false;
			currUser = "NONE";
			this->buttonContinue->Enabled = false;
			this->buttonOpenQueueFile->Enabled = false;
			currentFile.close();
		}
	}

	this->labelCurrentUser->Text = "������� ������������: " + currUser; // ������� �������� ������������.
	if (currUser == "NONE") // ������������� ���� � ����������� �� ����, ���� �� ������������ ��� ��� ���.
		this->labelCurrentUser->ForeColor = Color::Red;
	else 
		this->labelCurrentUser->ForeColor = Color::Green;

	if (admin) { // ����������� ����������� � ����������� ������ � ����������� �� ����� ����.
		this->buttonCreateNewQueue->Enabled = true;
		this->����ToolStripMenuItem2->Visible = false;
		this->�����ToolStripMenuItem->Visible = true;
	}
	else {
		this->buttonCreateNewQueue->Enabled = false;
		this->����ToolStripMenuItem2->Visible = true;
		this->�����ToolStripMenuItem->Visible = false;
	}

}

System::Void Prog::MainMenuForm::MainMenuForm_Activated(System::Object^ sender, System::EventArgs^ e) {
	this->timerCheck->Start(); // ��������� ������ � ����������.
}

System::Void Prog::MainMenuForm::MainMenuForm_Deactivate(System::Object^ sender, System::EventArgs^ e) {
	this->timerCheck->Stop(); // ������������� ������ � ����������.
}

System::Void Prog::MainMenuForm::����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	LogInForm^ form = gcnew LogInForm(this); // �������� �����.
	this->Hide(); // �������� ������� �����.
	form->Show(); // �������� ��������� �����.
}

System::Void Prog::MainMenuForm::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	RegistrationForm^ form = gcnew RegistrationForm(this); // �������� �����.
	this->Hide(); // �������� ������� �����.
	form->Show(); // �������� ��������� �����.
}

System::Void Prog::MainMenuForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����� �� ��������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		remove(ConvertStringToChar(Application::StartupPath + "\\users\\currentUser.txt"));
}

System::Void Prog::MainMenuForm::�������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	PersonalCabinetForm^ form = gcnew PersonalCabinetForm(this); // �������� �����.
	this->Hide(); // �������� ������� �����.
	form->Show(); // �������� ��������� �����.
}

System::Void Prog::MainMenuForm::checkQueues() { // ������� �������� �������� �� ���� � �������� �� � �����.

	array<String^>^ fileNames = System::IO::Directory::GetFiles(Application::StartupPath + "\\queues");
	System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
	for (size_t i = 0; i < fileNames->Length; i++) {

		std::string path;
		ConvertStringToSTDString(fileNames[i], path);
		std::ifstream currentFile(path, std::ios::in); // ��������� �����
		if (!currentFile) { // ���� �� ��������, �� �� ��������� � ������� ���������
			continue;
		}
		else { // �����
			MyQueue<queueData> queue;
			if (currentFile >> queue) { // ���� �������� �������
				currentFile.close();

				DateTime queTime, time = DateTime::Today; // ������������� ����� ������� � ������� (����)
				queTime = queTime.AddDays(queue.Day() - 1);
				queTime = queTime.AddMonths(queue.Month() - 1);
				queTime = queTime.AddYears(queue.Year() - 1);

				if (time > queTime) { // ���� ������� ���� ������, ��� ���� ������ �������, �� ��������� (��������) ������ ���� � ����� ����� � ������� ��� �� ���� �����.
					String^ cmd = "md " + Application::StartupPath + "\\archive";
					system(ConvertStringToChar(cmd));
					cmd = "copy /v /a \"" + fileNames[i] + "\" \"" + Application::StartupPath + "\\archive\" /a";
					system(ConvertStringToChar(cmd));
					remove(ConvertStringToChar(fileNames[i]));
				}

			}
			else { // ����� ��������� ����� � ����� ��������� �������.
				currentFile.close();
				continue;
			}
		}


	}

}

System::Void Prog::MainMenuForm::����ToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	bool passwordIsCorrect = false; // ������ ���� �������� ��������������� ��������� ����� �������� ������.
	Users user1;
	DateTime date = DateTime::Today;
	user1.surnameNP = "�������������";
	std::string pass;
	ConvertStringToSTDString(date.Day.ToString() + "queueAdmin" + date.Year.ToString(), pass);
	user1.password = pass;
	CheckPassForm^ form = gcnew CheckPassForm(this, &passwordIsCorrect, &user1); // ������� ����� ��� �������� ������.

	switch (form->ShowDialog()) { // ��������� ������ �������� ������
	case System::Windows::Forms::DialogResult::OK: {

		MessageBox::Show("����������� ������ �������!\n������ �� ������ ��������� �������.", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);

		admin = true; // ���� �������� ������ ������ �������, ����� ���������� ���� admin � ��������� true

		break;
	} // ����� - � false.
	case System::Windows::Forms::DialogResult::Abort: {
		MessageBox::Show("����������� �� ���� ���������, ��������� ������ ��� ������ �� �����.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		admin = false;
		break;
	}
	case System::Windows::Forms::DialogResult::Cancel: {
		form->Close();
		MessageBox::Show("����������� �� ���� ���������, ��������� ����� ���� �������.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		admin = false;
		break;
	}
	}
}

System::Void Prog::MainMenuForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� ����� �������, ��� ������ ����� �� ������ ��������������?\n�������� �������� ������ ����������.","�������������", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
		admin = false;
}

System::Void Prog::MainMenuForm::MainMenuForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(1); // ������� ����� ������� � �������� ����� ����� (1), ���� ���������� ������ ������� � �����.
	form->Show();
}
