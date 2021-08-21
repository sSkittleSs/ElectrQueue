#pragma once
#include "MainForm.h"
#include "MainMenuForm.h"

namespace Prog {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� AdminMainForm
	/// </summary>
	public ref class AdminMainForm : public System::Windows::Forms::Form
	{
	public:
		AdminMainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}
		AdminMainForm(System::Windows::Forms::Form^ mainMenu)
		{
			InitializeComponent();
			this->mainMenu = mainMenu;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~AdminMainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Form^ mainMenu;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������������������������ToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ QueueBox;

	private: System::Windows::Forms::Label^ labelSub;
	private: System::Windows::Forms::Label^ labelAdd;
	private: System::Windows::Forms::PictureBox^ pictureBoxSub;
	private: System::Windows::Forms::PictureBox^ pictureBoxAdd;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::GroupBox^ groupBoxSelectedUser;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminMainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->QueueBox = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->labelSub = (gcnew System::Windows::Forms::Label());
			this->labelAdd = (gcnew System::Windows::Forms::Label());
			this->pictureBoxSub = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxAdd = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBoxSelectedUser = (gcnew System::Windows::Forms::GroupBox());
			this->menuStrip1->SuspendLayout();
			this->QueueBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSub))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAdd))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->groupBoxSelectedUser->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->�����ToolStripMenuItem,
					this->����������ToolStripMenuItem, this->������������������������������ToolStripMenuItem, this->�����ToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(439, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->�������ToolStripMenuItem,
					this->���������ToolStripMenuItem, this->�������������������ToolStripMenuItem
			});
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->�����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(247, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminMainForm::�������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(247, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminMainForm::���������ToolStripMenuItem_Click);
			// 
			// �������������������ToolStripMenuItem
			// 
			this->�������������������ToolStripMenuItem->Name = L"�������������������ToolStripMenuItem";
			this->�������������������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->�������������������ToolStripMenuItem->Size = System::Drawing::Size(247, 22);
			this->�������������������ToolStripMenuItem->Text = L"������� ����� �������";
			this->�������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminMainForm::�������������������ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->����������ToolStripMenuItem->Text = L"� ���������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminMainForm::����������ToolStripMenuItem_Click);
			// 
			// ������������������������������ToolStripMenuItem
			// 
			this->������������������������������ToolStripMenuItem->Name = L"������������������������������ToolStripMenuItem";
			this->������������������������������ToolStripMenuItem->Size = System::Drawing::Size(228, 20);
			this->������������������������������ToolStripMenuItem->Text = L"����� �� ������ �����������������";
			this->������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminMainForm::������������������������������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem1
			// 
			this->�����ToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�����������������ToolStripMenuItem,
					this->����������������ToolStripMenuItem
			});
			this->�����ToolStripMenuItem1->Name = L"�����ToolStripMenuItem1";
			this->�����ToolStripMenuItem1->Size = System::Drawing::Size(54, 20);
			this->�����ToolStripMenuItem1->Text = L"�����";
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->�����������������ToolStripMenuItem->Text = L"����� � ������� ����";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminMainForm::�����������������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->����������������ToolStripMenuItem->Text = L"����� �� ���������";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminMainForm::����������������ToolStripMenuItem_Click);
			// 
			// QueueBox
			// 
			this->QueueBox->Controls->Add(this->dataGridView1);
			this->QueueBox->Location = System::Drawing::Point(42, 27);
			this->QueueBox->Name = L"QueueBox";
			this->QueueBox->Size = System::Drawing::Size(347, 442);
			this->QueueBox->TabIndex = 4;
			this->QueueBox->TabStop = false;
			this->QueueBox->Text = L"������� ";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView1->Location = System::Drawing::Point(6, 19);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->Size = System::Drawing::Size(335, 416);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->SelectionChanged += gcnew System::EventHandler(this, &AdminMainForm::dataGridView1_SelectionChanged);
			// 
			// labelSub
			// 
			this->labelSub->AutoSize = true;
			this->labelSub->Location = System::Drawing::Point(213, 97);
			this->labelSub->Name = L"labelSub";
			this->labelSub->Size = System::Drawing::Size(103, 13);
			this->labelSub->TabIndex = 5;
			this->labelSub->Text = L"������ �� �������";
			// 
			// labelAdd
			// 
			this->labelAdd->AutoSize = true;
			this->labelAdd->Location = System::Drawing::Point(31, 93);
			this->labelAdd->Name = L"labelAdd";
			this->labelAdd->Size = System::Drawing::Size(78, 26);
			this->labelAdd->TabIndex = 4;
			this->labelAdd->Text = L"�������� ���.\r\n����������";
			// 
			// pictureBoxSub
			// 
			this->pictureBoxSub->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxSub->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxSub.BackgroundImage")));
			this->pictureBoxSub->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBoxSub->Location = System::Drawing::Point(251, 67);
			this->pictureBoxSub->Name = L"pictureBoxSub";
			this->pictureBoxSub->Size = System::Drawing::Size(25, 25);
			this->pictureBoxSub->TabIndex = 3;
			this->pictureBoxSub->TabStop = false;
			this->pictureBoxSub->Click += gcnew System::EventHandler(this, &AdminMainForm::pictureBoxSub_Click);
			this->pictureBoxSub->MouseEnter += gcnew System::EventHandler(this, &AdminMainForm::pictureBoxSub_MouseEnter);
			this->pictureBoxSub->MouseLeave += gcnew System::EventHandler(this, &AdminMainForm::pictureBoxSub_MouseLeave);
			// 
			// pictureBoxAdd
			// 
			this->pictureBoxAdd->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxAdd->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxAdd.BackgroundImage")));
			this->pictureBoxAdd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBoxAdd->Location = System::Drawing::Point(54, 67);
			this->pictureBoxAdd->Name = L"pictureBoxAdd";
			this->pictureBoxAdd->Size = System::Drawing::Size(25, 25);
			this->pictureBoxAdd->TabIndex = 2;
			this->pictureBoxAdd->TabStop = false;
			this->pictureBoxAdd->Click += gcnew System::EventHandler(this, &AdminMainForm::pictureBoxAdd_Click);
			this->pictureBoxAdd->MouseEnter += gcnew System::EventHandler(this, &AdminMainForm::pictureBoxAdd_MouseEnter);
			this->pictureBoxAdd->MouseLeave += gcnew System::EventHandler(this, &AdminMainForm::pictureBoxAdd_MouseLeave);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToResizeColumns = false;
			this->dataGridView2->AllowUserToResizeRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(5, 19);
			this->dataGridView2->MultiSelect = false;
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->Size = System::Drawing::Size(318, 44);
			this->dataGridView2->TabIndex = 5;
			// 
			// groupBoxSelectedUser
			// 
			this->groupBoxSelectedUser->Controls->Add(this->labelSub);
			this->groupBoxSelectedUser->Controls->Add(this->dataGridView2);
			this->groupBoxSelectedUser->Controls->Add(this->labelAdd);
			this->groupBoxSelectedUser->Controls->Add(this->pictureBoxAdd);
			this->groupBoxSelectedUser->Controls->Add(this->pictureBoxSub);
			this->groupBoxSelectedUser->Location = System::Drawing::Point(52, 475);
			this->groupBoxSelectedUser->Name = L"groupBoxSelectedUser";
			this->groupBoxSelectedUser->Size = System::Drawing::Size(327, 122);
			this->groupBoxSelectedUser->TabIndex = 6;
			this->groupBoxSelectedUser->TabStop = false;
			this->groupBoxSelectedUser->Text = L"��������� ������������";
			// 
			// AdminMainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(439, 605);
			this->Controls->Add(this->groupBoxSelectedUser);
			this->Controls->Add(this->QueueBox);
			this->Controls->Add(this->menuStrip1);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(455, 644);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(455, 644);
			this->Name = L"AdminMainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�������: �������������";
			this->HelpButtonClicked += gcnew System::ComponentModel::CancelEventHandler(this, &AdminMainForm::AdminMainForm_HelpButtonClicked);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AdminMainForm::AdminMainForm_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &AdminMainForm::AdminMainForm_Shown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->QueueBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSub))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAdd))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->groupBoxSelectedUser->ResumeLayout(false);
			this->groupBoxSelectedUser->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool toForm = false;
	private: System::Void pictureBoxAdd_MouseEnter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxAdd_MouseLeave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxSub_MouseEnter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxSub_MouseLeave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void �����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ������������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void �������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SetupDataGridView();
	private: System::Void SetupDataGridView2();
	private: System::Void AdminMainForm_Shown(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AdminMainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void pictureBoxAdd_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxSub_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void logCancel(Users&);
	private: System::Void AdminMainForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
};
}
