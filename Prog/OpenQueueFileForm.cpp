#include "OpenQueueFileForm.h"

//#include "Queue.h"
//#include "QueueData.h"
//#include "FunctionsConvert.h"

System::Void Prog::OpenQueueFileForm::pictureBoxBrowse1_MouseEnter(System::Object^ sender, System::EventArgs^ e) { // �������� ��� ��� ��������������� � mainForm.cpp
	this->pictureBoxBrowse1->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\browseEnter.png");
	++this->pictureBoxBrowse1->Width;
	++this->pictureBoxBrowse1->Height;
}

System::Void Prog::OpenQueueFileForm::pictureBoxBrowse1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBoxBrowse1->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\browse.png");
	--this->pictureBoxBrowse1->Width;
	--this->pictureBoxBrowse1->Height;
}

System::Void Prog::OpenQueueFileForm::pictureBoxBrowse2_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBoxBrowse2->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\browseEnter.png");
	++this->pictureBoxBrowse2->Width;
	++this->pictureBoxBrowse2->Height;
}

System::Void Prog::OpenQueueFileForm::pictureBoxBrowse2_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBoxBrowse2->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\browse.png");
	--this->pictureBoxBrowse2->Width;
	--this->pictureBoxBrowse2->Height;
}

System::Void Prog::OpenQueueFileForm::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->buttonContinue->Enabled)
		remove(ConvertStringToChar(Application::StartupPath + "\\queues\\openQueueTmp.txt"));

	toForm = true;
	this->Close(); // �������� ������� �����.
	this->mainMenu->Show(); // �������� ��������� �����.
}

System::Void Prog::OpenQueueFileForm::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		if (this->buttonContinue->Enabled)
			remove(ConvertStringToChar(Application::StartupPath + "\\queues\\openQueueTmp.txt"));
		Application::Exit();
	}
}

System::Void Prog::OpenQueueFileForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("������ ��������� ������� ��� ������ � ������� � �����������.\n\n����� ���������:\t(c) ����� �.�., �-893", "� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::OpenQueueFileForm::pictureBoxBrowse1_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;

	openFileDialog->InitialDirectory = "c:\\";
	openFileDialog->Filter = "txt files (*.txt)|*.txt";
	openFileDialog->FilterIndex = 1;
	openFileDialog->RestoreDirectory = true;

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) // ��������� ���������� ���� ������ ���� � ���� ������ ������ OK, ��������� ���� � ����� � ���������
	{
		this->textBoxPath1->Text = openFileDialog->FileName;
	}
}

System::Void Prog::OpenQueueFileForm::pictureBoxBrowse2_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
	
	openFileDialog->InitialDirectory = Application::StartupPath + "\\queues\\";
	openFileDialog->Filter = "txt files (*.txt)|*.txt";
	openFileDialog->FilterIndex = 1;
	openFileDialog->RestoreDirectory = true;

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) // ��������� ���������� ���� ������ ���� � ���� ������ ������ OK, ��������� �������� ����� � ����������� � ���������
	{
		this->textBoxPath2->Text = openFileDialog->SafeFileName;
	}
}

System::Void Prog::OpenQueueFileForm::textBoxPath1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBoxPath1->Text = "";
}

System::Void Prog::OpenQueueFileForm::textBoxPath2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBoxPath2->Text = "";
}

System::Void Prog::OpenQueueFileForm::radioButtonManualPath_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { // ��������� ������ � ������� ��� ������ � ������ ����� � ��������� ������ ��� ������ � ������������� �����.
	this->buttonOpenFile1->Enabled = true;
	this->textBoxPath1->Enabled = true;
	this->pictureBoxBrowse1->Enabled = true;
	this->pictureBoxBrowse1->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\browse.png");

	this->buttonOpenFile2->Enabled = false;
	this->textBoxPath2->Enabled = false;
	this->pictureBoxBrowse2->Enabled = false;
	this->pictureBoxBrowse2->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\browseDisabled.png");
}

System::Void Prog::OpenQueueFileForm::radioButtonPath_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { // ��������� ������ � ������� ��� ������ � ������������� ����� � ��������� ������ ��� ������ � ������ �����.
	this->buttonOpenFile2->Enabled = true;
	this->textBoxPath2->Enabled = true;
	this->pictureBoxBrowse2->Enabled = true;
	this->pictureBoxBrowse2->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\browse.png");

	this->buttonOpenFile1->Enabled = false;
	this->textBoxPath1->Enabled = false;
	this->pictureBoxBrowse1->Enabled = false;
	this->pictureBoxBrowse1->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\browseDisabled.png");
}

System::Void Prog::OpenQueueFileForm::buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) { 
	if (this->buttonContinue->Enabled) // ���� ������ ����������� �������, �� ��� ������, ��� ������ ����� ������ ��������� ���� �������. ������� ���.
		remove(ConvertStringToChar(Application::StartupPath + "\\queues\\openQueueTmp.txt"));
	OpenQueueFileForm::�����������������ToolStripMenuItem_Click(sender, e); // ������� � ������� ����.
}

System::Void Prog::OpenQueueFileForm::buttonOpenFile1_Click(System::Object^ sender, System::EventArgs^ e) // ������ ������� ���������� ������� buttonOpenFile2_Click, �� ����������� ����, ��� ����� �������� ������ ���� �� ����������
{
	if (this->textBoxPath1->Text != "" && this->textBoxPath1->Text != "������� ���� � �����") {
		this->Cursor = System::Windows::Forms::Cursors::AppStarting;
		std::string path;
		ConvertStringToSTDString(Convert::ToString(this->textBoxPath1->Text), path);

		std::ifstream currentFile(path, std::ios::in);
		if (!currentFile) {
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("������ ��� �������� �����!\n�������� ������� ����� �� ����������,\n���� ���� ������ �������.", "������");
			return;
		}
		else {
			MyQueue<queueData> que;
			if (currentFile >> que) {
				currentFile.close();
				SetupDataGridView(path);
				this->buttonContinue->Enabled = true;
				ConvertStringToSTDString(Application::StartupPath + "\\queues\\openQueueTmp.txt", path);

				std::ofstream queueFile(path, std::ios::out | std::ios::trunc);
				if (!queueFile) {
					this->Cursor = System::Windows::Forms::Cursors::Default;
					MessageBox::Show("������ �������� ����� ��� ������ �������!\n��������� ������� �����.", "������");
					return;
				}
				else {
					if (!(queueFile << que)) {
						this->Cursor = System::Windows::Forms::Cursors::Default;
						queueFile.close();
						MessageBox::Show("������ � ������ ������ �������!", "������");
						return;
					}
					queueFile.close();
					this->buttonContinue->Enabled = true;
				}
			}
			else {
				currentFile.close();
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("�� ������� ��������� ������� �� ���������� �����.", "������");
				return;
			}
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
	}
	else {
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("������ ���� ����� ��� ����� �������� �� ���������!", "������");
		return;
	}
}

System::Void Prog::OpenQueueFileForm::buttonOpenFile2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxPath2->Text != "" && this->textBoxPath2->Text != "������� ������ ��� �����") {
		this->Cursor = System::Windows::Forms::Cursors::AppStarting;
		std::string path;
		ConvertStringToSTDString(Application::StartupPath + "\\queues\\" + Convert::ToString(this->textBoxPath2->Text), path);

		std::ifstream currentFile(path, std::ios::in);
		if (!currentFile) {
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("������ ��� �������� �����!\n�������� ������� ����� �� ����������,\n���� ���� ������ �������.", "������");
			return;
		}
		else {
			MyQueue<queueData> que;
			if (currentFile >> que) { // ������ ������� �� ����� �� �������������� ����
				currentFile.close();
				SetupDataGridView(path);
				this->buttonContinue->Enabled = true;
				ConvertStringToSTDString(Application::StartupPath + "\\queues\\openQueueTmp.txt", path);

				std::ofstream queueFile(path, std::ios::out | std::ios::trunc); // ���������� ������� �� ��������� ����
				if (!queueFile) {
					this->Cursor = System::Windows::Forms::Cursors::Default;
					MessageBox::Show("������ �������� ����� ��� ������ �������!\n��������� ������� �����.", "������");
					return;
				}
				else {
					if (!(queueFile << que)) {
						this->Cursor = System::Windows::Forms::Cursors::Default;
						queueFile.close();
						MessageBox::Show("������ � ������ ������ �������!", "������");
						return;
					}
					queueFile.close();
					this->buttonContinue->Enabled = true;
				}
			}
			else {
				currentFile.close();
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("�� ������� ��������� ������� �� ���������� �����.", "������");
				return;
			}
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
	}
	else {
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("������ ���� ����� ��� ����� �������� �� ���������!", "������");
		return;
	}
}

System::Void Prog::OpenQueueFileForm::SetupDataGridView(std::string path) { // ������ ��� ��� ��������������� � mainForm.cpp
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

			this->QueueBox->Text = "������������ ������� �� ����� " + ConvertSTDStringToString(que.GetTitle()) + " (" + Convert::ToString(que.length()) + ") " + Convert::ToString(que.Day()) + "." + Convert::ToString(que.Month()) + "." + Convert::ToString(que.Year());
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

System::Void Prog::OpenQueueFileForm::buttonContinue_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	std::string path;
	ConvertStringToSTDString(Application::StartupPath + "\\queues\\openQueueTmp.txt", path);

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("������ ��� �������� �����!\n�������� ������� ����� �� ����������,\n���� ���� ������ �������.", "������");
		return;
	}
	else {
		MyQueue<queueData> que;
		if (currentFile >> que) { // ������ ��������-��������� ����
			currentFile.close();
			SetupDataGridView(path);
			ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);

			std::ofstream queueFile(path, std::ios::out | std::ios::trunc);
			if (!queueFile) {
				this->Cursor = System::Windows::Forms::Cursors::Default;
				MessageBox::Show("������ �������� ����� ��� ������ �������!\n��������� ������� �����.", "������");
				return;
			}
			else {
				if (!(queueFile << que)) { // �������� ����������� ������� � ���� ������� �������
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
	remove(ConvertStringToChar(Application::StartupPath + "\\queues\\openQueueTmp.txt")); // ������� ��������� ����.
	this->Cursor = System::Windows::Forms::Cursors::Default;
	MainForm^ form = gcnew MainForm(mainMenu); // �������� �����.
	toForm = true;
	this->Close(); // �������� ������� �����.
	form->Show(); // �������� ��������� �����.
}

System::Void Prog::OpenQueueFileForm::OpenQueueFileForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
			if (this->buttonContinue->Enabled)
				remove(ConvertStringToChar(Application::StartupPath + "\\queues\\openQueueTmp.txt"));

			Application::Exit();
		}
		else
			e->Cancel = true;
}

System::Void Prog::OpenQueueFileForm::OpenQueueFileForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(2); // �������� ����� ������� ��� ������ �����
	form->Show();
}
