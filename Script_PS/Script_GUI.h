#pragma once
#include <string>
#include "Script.h"
#include "Snippit_GUI.h"
namespace Script_PS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms; 
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for Script_GUI
	/// </summary>
	public ref class Script_GUI : public System::Windows::Forms::Form
	{
	public:
		Script_GUI(void)
		{
			InitializeComponent();
			myScript = gcnew Main_package::Script();
			this->Script_Path_Changed = false;
			this->Script_Path_Changed_2 = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Script_GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::GroupBox^  groupBox2;









	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label2;




	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  About_btn;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: Main_package::Script^ myScript;
	private: Script_PS::Snippet_Config^ Snippet_Form;
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::Windows::Forms::Button^  Help_btn;
	private: bool Script_Path_Changed;
	private: bool Script_Path_Changed_2;
	private: System::Windows::Forms::Label^  VerLabel;
	private: System::Windows::Forms::TextBox^  VerText;




	private: System::ComponentModel::IContainer^  components;



	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Script_GUI::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->About_btn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->Help_btn = (gcnew System::Windows::Forms::Button());
			this->VerText = (gcnew System::Windows::Forms::TextBox());
			this->VerLabel = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Location = System::Drawing::Point(20, 74);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(538, 91);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Script";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 44);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(405, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(284, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Please provide the path where the script file (.pl) is located:";
			this->label1->Click += gcnew System::EventHandler(this, &Script_GUI::label1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(430, 39);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(102, 28);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Browse";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Script_GUI::button3_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->panel1);
			this->groupBox2->Location = System::Drawing::Point(20, 266);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(538, 99);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Configuration";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Location = System::Drawing::Point(136, 19);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(230, 65);
			this->panel1->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(159, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Replace Snippits of Code in SW";
			this->label2->Click += gcnew System::EventHandler(this, &Script_GUI::label2_Click);
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(36, 7);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(150, 23);
			this->button5->TabIndex = 0;
			this->button5->Text = L"Replace Snippits of Code";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Script_GUI::button5_Click);
			// 
			// About_btn
			// 
			this->About_btn->Location = System::Drawing::Point(485, 12);
			this->About_btn->Name = L"About_btn";
			this->About_btn->Size = System::Drawing::Size(73, 21);
			this->About_btn->TabIndex = 6;
			this->About_btn->Text = L"About";
			this->About_btn->UseVisualStyleBackColor = true;
			this->About_btn->Click += gcnew System::EventHandler(this, &Script_GUI::button8_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(25, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(70, 34);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::Control;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(156, 18);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(275, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"PolySpace Preparation Script Configurator";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Script_GUI::openFileDialog1_FileOk);
			// 
			// errorProvider1
			// 
			this->errorProvider1->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProvider1->ContainerControl = this;
			// 
			// Help_btn
			// 
			this->Help_btn->Location = System::Drawing::Point(485, 47);
			this->Help_btn->Name = L"Help_btn";
			this->Help_btn->Size = System::Drawing::Size(73, 21);
			this->Help_btn->TabIndex = 9;
			this->Help_btn->Text = L"Help";
			this->Help_btn->UseVisualStyleBackColor = true;
			// 
			// VerText
			// 
			this->VerText->Location = System::Drawing::Point(97, 212);
			this->VerText->Name = L"VerText";
			this->VerText->Size = System::Drawing::Size(74, 20);
			this->VerText->TabIndex = 10;
			// 
			// VerLabel
			// 
			this->VerLabel->AutoSize = true;
			this->VerLabel->Location = System::Drawing::Point(28, 215);
			this->VerLabel->Name = L"VerLabel";
			this->VerLabel->Size = System::Drawing::Size(63, 13);
			this->VerLabel->TabIndex = 11;
			this->VerLabel->Text = L"SW Version";
			// 
			// Script_GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(570, 377);
			this->Controls->Add(this->VerLabel);
			this->Controls->Add(this->VerText);
			this->Controls->Add(this->Help_btn);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->About_btn);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Script_GUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PolySpace Script Configurator";
			this->Load += gcnew System::EventHandler(this, &Script_GUI::Script_GUI_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Script(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void File_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {		 }
private: System::Void Script_GUI_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->openFileDialog1->ShowDialog();
		 }
private: System::Void folder_dialog_1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
			 this->textBox1->Text = "";
			 if(myScript->Set_Script_Path(this->openFileDialog1->FileName))
			 {
				 delete errorProvider1;
				 this->textBox1->Text = myScript->getScript_path();
				 this->button5->Enabled = true;
				 this->Script_Path_Changed = true;
				 this->Script_Path_Changed_2 = true;
			 }
			 else
			 {
				 this -> errorProvider1->SetError(this->textBox1, "Please Choose a script file (Ends with .pl)");
				 this->button5->Enabled = false;
			 }
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 static unsigned short click_count = 0;
			 System::String^ xmlPath = myScript->GetXmlFilePath();
			 double Version;
			 try
			 {
				 Version = double::Parse(this->VerText->Text);
			 }
			 catch (Exception^ exp)
			 {
				 System::Windows::Forms::MessageBox::Show("Please Enter Valid SW Version -> EX: 1.1", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				 return;
			 }
			 //if(click_count == 0 || this->Script_Path_Changed)
			 //{
				if (System::IO::File::Exists(xmlPath))
				{
					 try
					 {
						 Snippet_Form = gcnew Script_PS::Snippet_Config(xmlPath, Version);
					 }
					 catch (Exception^ e)
					 {
						System::Windows::Forms::MessageBox::Show(e->Message, "XML Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
						return;
					 }
				}
				else
				{
					if (System::Windows::Forms::MessageBox::Show("Cannot Find XML file, Create New One?", "Cannot Find File", System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
					{
						try
						{
							Snippet_Form = gcnew Script_PS::Snippet_Config(xmlPath, Version);
						}
						catch (Exception^ e)
						{
							System::Windows::Forms::MessageBox::Show("Error Loading XML", "XML Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
							return;
						}
					}
					else
					{
						return;
					}
				}
			 //}
			 try{ Snippet_Form->ShowDialog(); }
			 catch (Exception^ e){ System::Windows::Forms::MessageBox::Show(e->Message); return; }
			 click_count++;
			 this->Script_Path_Changed = false;
		 }
private: System::Void Script_GUI_Closing( Object^ sender, System::ComponentModel::CancelEventArgs^ e )
		{

		}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 System::Windows::Forms::MessageBox::Show("Version 1.0", "Help", System::Windows::Forms::MessageBoxButtons::OK);
		 }
};
}