#include "CheckPassForm.h"

System::Void Prog::CheckPassForm::textBoxPassword_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBoxPassword->Text = "";
}

System::Void Prog::CheckPassForm::buttonConfirmPassword_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->textBoxPassword->Text->ToString() == correctPassword) { // ���������� ������ � ���������� ���������
		*correct = true;
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		MessageBox::Show("������ ���������.\n\n����� ������� ������ \"OK\" �� ������ �������������� �� ���������� ����.", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}
	else {
		*correct = false;
		this->DialogResult = System::Windows::Forms::DialogResult::Abort;
		MessageBox::Show("������ �� ���������.\n\n����� ������� ������ \"OK\" �� ������ �������������� �� ���������� ����.", "������!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		this->Close();
	}
}

System::Void Prog::CheckPassForm::pictureBoxEye_Click(System::Object^ sender, System::EventArgs^ e) {
	if (eye) { // ���� ������ �����, �� ���������� ���
		eye = false;
		this->textBoxPassword->PasswordChar = false;
		this->pictureBoxEye->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\hidePassOffEnter.png");
	}
	else { // ����� - ��������
		eye = true;
		this->textBoxPassword->PasswordChar = true;
		this->textBoxPassword->PasswordChar = '*';
		this->pictureBoxEye->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\hidePassOnEnter.png");
	}
}

System::Void Prog::CheckPassForm::pictureBoxEye_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	if (eye) 
		this->pictureBoxEye->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\hidePassOnEnter.png");
	else 
		this->pictureBoxEye->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\hidePassOffEnter.png");
}

System::Void Prog::CheckPassForm::pictureBoxEye_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	if (eye)
		this->pictureBoxEye->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\hidePassOn.png");
	else
		this->pictureBoxEye->BackgroundImage = System::Drawing::Image::FromFile(Application::StartupPath + "\\images\\hidePassOff.png");
}