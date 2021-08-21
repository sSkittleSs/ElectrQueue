#include "MainForm.h"

System::Void Prog::MainForm::pictureBoxAdd_MouseEnter(System::Object^ sender, System::EventArgs^ e) { // ���� ���� ��������� �� Add, �� ������ �������� � �����������.
	this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\addEnter.png");
	++this->pictureBoxAdd->Width;
	++this->pictureBoxAdd->Height;
}

System::Void Prog::MainForm::pictureBoxAdd_MouseLeave(System::Object^ sender, System::EventArgs^ e) { // ���� ���� ��������� � Add, �� ������ �������� � ���������.
	this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\add.png");
	--this->pictureBoxAdd->Width;
	--this->pictureBoxAdd->Height;
}

System::Void Prog::MainForm::pictureBoxSub_MouseEnter(System::Object^ sender, System::EventArgs^ e) { // ���� ���� ��������� �� Sub, �� ������ �������� � �����������.
	this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\subEnter.png");
	++this->pictureBoxSub->Width;
	++this->pictureBoxSub->Height;
}

System::Void Prog::MainForm::pictureBoxSub_MouseLeave(System::Object^ sender, System::EventArgs^ e) { // ���� ���� ��������� � Sub, �� ������ �������� � ���������.
	this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\sub.png");
	--this->pictureBoxSub->Width;
	--this->pictureBoxSub->Height;
}

System::Void Prog::MainForm::����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		Application::Exit();
}

System::Void Prog::MainForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("������ ��������� ������� ��� ������ � ������� � �����������.\n\n����� ���������:\t(c) ����� �.�., �-893", "� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Prog::MainForm::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toForm = true;
	this->Close(); // �������� ������� �����.
	this->mainMenu->Show(); // �������� ����� �������� ����.
}

System::Void Prog::MainForm::���������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string path;
	ConvertStringToSTDString(System::Windows::Forms::Application::StartupPath + "\\queues\\currentQueue.txt", path);

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		System::Windows::Forms::MessageBox::Show("������ ��� �������� ������� �������.", "������");
		return;
	}
	else {
		MyQueue<queueData> que;
		if (currentFile >> que) { // ���� ������� ��������
			bool passwordIsCorrect = false;
			Users user1;
			user1.surnameNP = que.GetTitle();
			user1.password = que.GetAdminPassword();
			CheckPassForm^ form = gcnew CheckPassForm(this, &passwordIsCorrect, &user1);

			switch (form->ShowDialog()) { // ��������� ������
			case System::Windows::Forms::DialogResult::OK: { // ���� ������ ������

				MessageBox::Show("����������� ������ �������!\n", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);

				AdminMainForm^ form = gcnew AdminMainForm(mainMenu); // �������� �����.
				toForm = true;
				this->Close(); // �������� ������� �����.
				form->Show(); // �������� ��������� �����.

				break;
			} // ���� ������ �������� ��� ����� �������, �� ������� ���������
			case System::Windows::Forms::DialogResult::Abort: {
				MessageBox::Show("����������� �� ���� ���������, ��������� ������ ��� ������ �� �����.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}
			case System::Windows::Forms::DialogResult::Cancel: {
				form->Close();
				MessageBox::Show("����������� �� ���� ���������, ��������� ����� ���� �������.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}
			}
		}
		currentFile.close();
	}

}

System::Void Prog::MainForm::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string path;
	ConvertStringToSTDString(System::Windows::Forms::Application::StartupPath + "\\queues\\currentQueue.txt", path);

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		System::Windows::Forms::MessageBox::Show("������ ��� �������� ����� ��� ������!\n��������� ������� �� �������.", "������");
		return;
	}
	else {
		MyQueue<queueData> que;
		currentFile >> que; // ������ �������
		currentFile.close();

		std::ofstream queueFileMF(que.GetFileName(), std::ios::out | std::ios::trunc); // ����� ���� �� �����, ������� ������������� ��� ��������
		if (!queueFileMF) {
			System::Windows::Forms::MessageBox::Show("������ � ������ ������ �������!\n��������� ������� �� �������.", "������");
			return;
		}
		else {
			if (queueFileMF << que) { // ���� ��������
				ConvertStringToSTDString(System::Windows::Forms::Application::StartupPath + "\\queues\\currentQueue.txt", path); // ����� ����� �������������� ������� �������
				std::ofstream queueFile(path, std::ios::out | std::ios::trunc);
				if (!queueFile) { 
					System::Windows::Forms::MessageBox::Show("������ � ������ �������� ����� currentQueue.txt!\n�������� ������� ������� �� �������.", "������");
					return;
				}
				else {
					if (queueFile << que)
						System::Windows::Forms::MessageBox::Show("������� ������� ���������.", "�����");
					else
						System::Windows::Forms::MessageBox::Show("������ � ������ ������ ������� � ���� currentQueue.txt!\n��������� ������� �� �������.", "������");
				}
			}
			else
				System::Windows::Forms::MessageBox::Show("������ � ������ ������ ������� � ����!\n��������� ������� �� �������.", "������");
			queueFileMF.close();
		}
	}
}

System::Void Prog::MainForm::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	toForm = true;
	OpenQueueFileForm^ form = gcnew OpenQueueFileForm(mainMenu); // �������� �����.
	this->Close(); // �������� ������� �����.
	form->Show(); // �������� ��������� �����.
}

System::Void Prog::MainForm::SetupDataGridView() { // ����������� ������� (��� DataTable)
	this->dataGridView1->Rows->Clear();

	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	this->dataGridView1->ColumnCount = 3;

	std::string path;
	ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);

	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("������ ��� �������� ����� �������!\n�������� ���� ���������.\n���������� ������� ������ ������� �����.", "������");
		return;
	}
	else {
		MyQueue<queueData> que;
		if (currentFile >> que) { // ������ �������
			currentFile.close();
			// ������� �������� �������, � ����� � ���� ������
			this->QueueBox->Text = "������� " + ConvertSTDStringToString(que.GetTitle()) + " (" + Convert::ToString(que.length()) + ") " + Convert::ToString(que.Day()) + "." + Convert::ToString(que.Month()) + "." + Convert::ToString(que.Year());
			this->dataGridView1->Columns[0]->Width = 20;
			this->dataGridView1->Columns[0]->Name = "�";
			this->dataGridView1->Columns[1]->Width = 205;
			this->dataGridView1->Columns[1]->Name = "Name";
			this->dataGridView1->Columns[2]->Width = 50;
			this->dataGridView1->Columns[2]->Name = "Time";

			Node<queueData>* it{ que.beg() };
			while (it) { // ������� ��� ������� �� ������ ����, ���� ��� ��������.
				System::String^ name = ConvertSTDStringToString(it->data.surnameNP);
				this->dataGridView1->Rows->Add(Convert::ToString(it->data.ownNumber), name, Convert::ToString(it->data.time.hours) + " : " + Convert::ToString(it->data.time.minutes));
				it = it->next;
			}

		}
		else { // ���� �� ������� ��������� �������
			currentFile.close();
			this->Cursor = System::Windows::Forms::Cursors::Default;
			MessageBox::Show("�� ������� ��������� ������� �� ���������� �����.\n�������� ���� ���������.\n���������� ������� ������ ������� �����.", "������");
			return;
		}
	}
	this->Cursor = System::Windows::Forms::Cursors::Default;
}

System::Void Prog::MainForm::MainForm_Shown(System::Object^ sender, System::EventArgs^ e) {
	SetupDataGridView();
}

System::Void Prog::MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) { // �������, ������� ����������� ��� �������� �����
	if (e->CloseReason == CloseReason::UserClosing && !toForm)
		if (MessageBox::Show("�� �������, ��� ������ ����� �� ���������?", "�������������", System::Windows::Forms::MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
			Application::Exit();
		else
			e->Cancel = true;
}

System::Void Prog::MainForm::pictureBoxAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	
	switch(balance()) { // ������� ��� ���������� ����� balance()
	case 0: // ���� ������� �� ������ ��������� ��� ��� ������
	case 1:{ // ���� ������� ��������� � ������������ ����� ����������
			if (MessageBox::Show("�� ����� �������, ��� ������ ���������� �� ��������� �����?", "��������", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK) {
				std::string path;
				ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path); // ������������ System::String � std::string � �������� � path.

				std::ifstream currentFile(path, std::ios::in); // ��������� ����� ��� ������.
				if (!currentFile) {
					MessageBox::Show("������ ���������� (���������� ������� ���� �������).", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				else {
					MyQueue<queueData> que;
					if (currentFile.peek() != EOF && currentFile >> que) { // ������ ������� � ��������� �����
						currentFile.close();
						//String^ name = gcnew System::String(user.surnameNP.c_str());
						ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.txt", path);
						std::ifstream currentFileUser(path, std::ios::in);
						if (!currentFileUser) {
							//currUser = "NONE";
						}
						else {
							Users user;
							if (currentFileUser >> &user) { // ���� ������������ ��������
								currentFileUser.close(); // ���� ��������� ������� �� ������������ ���-���� ��� �� ��� �� ����� (� ����)
								if (checkTime(user, que.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.hours, que.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.minutes)) {
									MessageBox::Show("�� ��� �������� �� ������ ����� � ������� �����.\n���� �� ��� �� ������ ����������, �� ��� ������� ������ ��������\n������ � ������� �����.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
									return;
								}
								else {
									que.SetData(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value), user.surnameNP); // ��������� ������������, � ����� ��������� �������

									ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);

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
									}

									SetupDataGridView(); // ������������� ������� (�������)
									SetupDataGridView2(); // ������������� ������� (��������� ������������).
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
						MessageBox::Show("������ ���������� (���������� �������� ������� �� �����).", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}

					currentFile.close();
					return;
				}
			}
		}
		break;
	case 2: { // ���� ������������ �� ������� ������������
		return;
	}
	default: { // ���� ���-�� ����� �� ���.
		MessageBox::Show("��������� ������ ��� ������� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
		MessageBox::Show("������ �������� (���������� ������� ���� ������������).", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	else {
		if (currentFileUser >> &user) { // ������ ������������
			currentFileUser.close();
			if (checkCancel(user)) { // ��������� ���-�� ����� � ���������� ����� � ������� ��������� ���� ��� ��������� 3
				MessageBox::Show("�� ������� ����� ���� ����� � ������!", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			if (MessageBox::Show("�� ����� �������, ��� ������ �������� ������ �� ��������� �����?", "��������", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK) {
				std::string path;
				ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path); // ������������ System::String � std::string � �������� � path.

				std::ifstream currentFile(path, std::ios::in); // ��������� ����� ��� ������.
				if (!currentFile) {
					MessageBox::Show("������ �������� (���������� ������� ���� �������).", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				else {
					MyQueue<queueData> que;
					if (currentFile.peek() != EOF && currentFile >> que) { // ���� ������� ��������
						currentFile.close();
						//String^ name = gcnew System::String(user.surnameNP.c_str());
						DateTime time = DateTime::Now; // ����� ������� ����� � ����
						DateTime timeQue;
						timeQue = timeQue.AddDays(que.Day() - 1);
						timeQue = timeQue.AddMonths(que.Month() - 1);
						timeQue = timeQue.AddYears(que.Year() - 1);
						timeQue = timeQue.AddHours(que.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.hours);
						timeQue = timeQue.AddMinutes(que.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.minutes);

						if (time >= timeQue) { // ���� ������� ����� ������, ��� ��������� �����, �� ������� ���������
							MessageBox::Show("���������� �������� ������ � ����� �� �����, ������� ������.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						}
						else { // ����� �������� �����, ��� �� ������� � �������������� �������, �������� �� ����� ����.
							que.SetData(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value), "����� �� ������");

							ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);

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

								logCancel(user);
								queueFile.close();
							}

							SetupDataGridView();
							SetupDataGridView2();

						}

					}
					else {
						currentFile.close();
						MessageBox::Show("������ �������� (���������� �������� ������� �� �����).", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}

					currentFile.close();
					return;
				}
			}
		}
		else {

			MessageBox::Show("������ �������� (���������� �������� ������������ �� �����).", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			currentFileUser.close();
			return;
		}
	}
}

System::Void Prog::MainForm::SetupDataGridView2() { // ����������������� ������� ���������� ������������
	this->Cursor = System::Windows::Forms::Cursors::AppStarting;
	this->dataGridView2->Rows->Clear();
	this->dataGridView2->ColumnCount = 3;


	this->dataGridView2->Columns[0]->Width = 20;
	this->dataGridView2->Columns[0]->Name = "�";
	this->dataGridView2->Columns[1]->Width = 205;
	this->dataGridView2->Columns[1]->Name = "Name";
	this->dataGridView2->Columns[2]->Width = 50;
	this->dataGridView2->Columns[2]->Name = "Time";

	this->dataGridView2->Rows->Add(this->dataGridView1->CurrentRow->Cells[0]->Value, this->dataGridView1->CurrentRow->Cells[1]->Value, this->dataGridView1->CurrentRow->Cells[2]->Value);

	this->Cursor = System::Windows::Forms::Cursors::Default;
}

System::Void Prog::MainForm::SetupButtons() { // ����������������� ������
	
	std::string path = "";
	ConvertStringToSTDString(Application::StartupPath + "\\users\\currentUser.txt", path);
	std::ifstream currentFile(path, std::ios::in);
	if (!currentFile) {
		//currUser = "NONE";
	}
	else {
		Users user;
		if (currentFile >> &user) { // ���� ����� ��������� ������������, �� ������� �������� �� �����
			currentFile.close();
			String^ name = gcnew System::String(user.surnameNP.c_str());

			if (this->dataGridView1->CurrentRow->Cells[1]->Value->ToString() == "����� �� ������") { // ���� ��������, ����� ���� ������ � ����������
				this->pictureBoxAdd->Enabled = true;
				this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\add.png");
			}
			else { // ����� - ���������
				this->pictureBoxAdd->Enabled = false;
				this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\addDisabled.png");
			}
			
			if (this->dataGridView1->CurrentRow->Cells[1]->Value->ToString() == name) { // ���� ����� ������ �������������, �� ���� ������ � ����������� �������� ������
				this->pictureBoxSub->Enabled = true;
				this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\sub.png");
			}
			else { // ����� - ���������
				this->pictureBoxSub->Enabled = false;
				this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\subDisabled.png");
			}
		}
		else { // ���� ������������ �� ������ ���������, �� ��������� ���.
			this->pictureBoxAdd->Enabled = false;
			this->pictureBoxSub->Enabled = false;
			this->pictureBoxAdd->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\addDisabled.png");
			this->pictureBoxSub->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\subDisabled.png");
			currentFile.close();
		}
	}

}

System::Void Prog::MainForm::logCancel(Users& user) { // �������� ������ �� ������
	std::string path = "";
	ConvertStringToSTDString(Application::StartupPath + "\\users\\cancelLog.txt", path);
	std::ofstream logFile(path, std::ios::out | std::ios::app);
	if (logFile)
		logFile << user.surnameNP << std::endl;
}

bool Prog::MainForm::checkCancel(Users& user) { // ������� ���������� ����� ������������ � �����
	std::string path = "", name = user.surnameNP;
	char check[51];
	size_t count = 0;
	ConvertStringToSTDString(Application::StartupPath + "\\users\\cancelLog.txt", path);
	std::ifstream logFile(path, std::ios::in);
	while (logFile.getline(check, 51, '\n')) // ���� ����� ������
		if (check == name)
			count++;
	
	return count >= 3;
}

bool Prog::MainForm::checkTime(Users user, size_t hours, size_t minutes) { // ������� �������� ���������� ��� ��� ������� ������������

	array<String^>^ fileNames = System::IO::Directory::GetFiles(Application::StartupPath + "\\queues"); // �������� ��� ������� � �����
	System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder();
	for (size_t i = 0; i < fileNames->Length; i++) { // �������� �� �� ����
		
		std::string path;
		ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);
		std::ifstream currentFileQueue(path, std::ios::in);
		if (!currentFileQueue) {
			continue;
		}
		else {
			MyQueue<queueData> queue;
			if (currentFileQueue >> queue) { // ������ ������� �������
				currentFileQueue.close();
				
				ConvertStringToSTDString(fileNames[i], path);
				//Application::StartupPath + "\\queues\\"

				if ((queue.GetFileName() == path) || (fileNames[i] == Application::StartupPath + "\\queues\\currentQueue.txt")) // ���� ������� �������� ������� ��� �������� ���, \\
					�� ������� ��������� �������, �� �������� ���������
					continue;

				std::ifstream currentFile(path, std::ios::in);
				if (!currentFile) {
					return false;
				}
				else {
					MyQueue<queueData> que;
					if (currentFile >> que) { // ������ �������
						currentFile.close();

						for (size_t j = 1; j <= que.length(); j++) {// ���� ���� � ����� ���������
							if (que.find(j)->data.time.hours == hours && que.find(j)->data.time.minutes == minutes
								&& que.Day() == queue.Day() && que.Month() == queue.Month() && que.Year() == queue.Year())
								if (que.find(j)->data.surnameNP == user.surnameNP) // � ��� ���� ��� ������� ����� �� ������������, ����� ���������� true
									return true;
						}

					}
					else { // ����� false
						currentFile.close();
						return false;
					}
				}

			}
			else { // ����� ����� ��������� ����
				currentFileQueue.close();
				continue;
			}
		}

		
	}
	return false; // ���� ��� ������ � �� �����, ���������� false
}

int Prog::MainForm::balance() { // ������� ������������ �������� (���������� � ����-�����)
	
	std::string path;
	ConvertStringToSTDString(Application::StartupPath + "\\queues\\currentQueue.txt", path);
	std::ifstream currentFileQueue(path, std::ios::in);
	if (!currentFileQueue) {
		return 0;
	}
	else {
		MyQueue<queueData> queue;
		if (currentFileQueue >> queue) { // ���� �������� ������� �������
			currentFileQueue.close();

			Node<queueData>* toSet{ queue.beg() };
			size_t nempty = 0;
			while (toSet) {	// ������� ���-�� ������� ����
				if (toSet->data.surnameNP != "����� �� ������")
					nempty++;
				toSet = toSet->next;
			}

			if (((double)nempty / (double)queue.length() * 100) >= 90) { // ������� ������ ���� ����� �� �������� 90%, ���� ��

				array<String^>^ fileNames = System::IO::Directory::GetFiles(Application::StartupPath + "\\queues"); // �������� ��� ����� � ����� ��������
				System::Text::StringBuilder^ strings = gcnew System::Text::StringBuilder(); 
				strings->AppendFormat("������� � �������� ����� ��������� �� {0}%.\n���������� ��� ���������� � ��������� ������:", (double)nempty / (double)queue.length() * 100);
				strings->AppendLine();
				for (size_t i = 0; i < fileNames->Length; i++) { // ����� ������ �������
					ConvertStringToSTDString(fileNames[i], path);

					if ((queue.GetFileName() == path) || (fileNames[i] == Application::StartupPath + "\\queues\\currentQueue.txt")) // ���� ������� �������� ������� ��� �������� ���, \\
					�� ������� ��������� �������, �� �������� ���������
						continue;

					std::ifstream currentFile(path, std::ios::in);
					if (!currentFile) {
						continue;
					}
					else {
						MyQueue<queueData> que;
						if (currentFile >> que) { // ���� ������� ��������
							currentFile.close();

							Node<queueData>* toSet{ que.beg() }; // ������� ���������� ������� ����
							size_t nempty = 0;
							while (toSet) {
								if (toSet->data.surnameNP != "����� �� ������")
									nempty++;
								toSet = toSet->next;
							}

							double congestion = ((double)nempty / (double)queue.length()) * 100; // ����������� ��������

							if (congestion > 50) // ���� ������ 50%, �� ����� ���������
								continue;
							else { // ����� ��������� ����������� ������ �� ����� �� �����
								bool possibility = false;
								for (size_t j = 1; j <= que.length(); j++) {
									
									if (que.find(j)->data.time.hours == queue.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.hours && que.find(j)->data.time.minutes == queue.find(Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[0]->Value))->data.time.minutes) {
										possibility = que.find(j)->data.surnameNP == "����� �� ������";
									}

								}
								// ��������� ���������� �� ���� �����
								strings->Append("---------------------");
								strings->AppendLine();
								String^ title = ConvertSTDStringToString(que.GetTitle());
								strings->AppendFormat("����: {0}\n���� ������: {1}.{2}.{3}\n����������� ������ �� �� �� �����: {4}\n���� �������: {5}\n�������������: {6}%", title, que.Day(), que.Month(), que.Year(), (possibility ? "������������" : "�����������"), System::IO::Path::GetFileName(fileNames[i]), congestion);
								strings->AppendLine();
							}

						}
						else { // ����� ����� ���������
							currentFile.close();
							continue;
						}
					}

				}
				strings->AppendLine(); // ������� ���������� � ���� ������
				strings->Append("������� \"OK\", ����� ���������� ������ � �������� �����.\n������� \"Cancel\", ����� �������� ������ � �������� �����.");
				strings->AppendLine();
				return MessageBox::Show(strings->ToString(), "��������", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK ? 1 : 2;
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
	SetupDataGridView2(); // ����������������� ������� ���������� ������������
	SetupButtons(); // ������������������ ������
}

System::Void Prog::MainForm::MainForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	HelpForm^ form = gcnew HelpForm(4); // ������� ���� ������� � ������� ������� ����
	form->Show();
}
