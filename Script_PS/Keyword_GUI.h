#pragma once
#include "Keyword_Replacer.h"

namespace Script_PS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Keyword_Replace
	/// </summary>
	public ref class Keyword_Replace : public System::Windows::Forms::Form
	{
	public:
		Keyword_Replace(System::String^ Path)
		{
			KeyWrd_Replacer = gcnew Main_package::Keyword_Replacer();
			InitializeComponent();
			if(!this->KeyWrd_Replacer->Load_File(Path))
			{
				System::String^ error = "";
				if(this->KeyWrd_Replacer->Get_Err() == Line_Error_KW_delim)
				{
					error = "there Must be a \"<>\"\nDelimiter in Line " + this->KeyWrd_Replacer->Get_Err_Line();
					System::Windows::Forms::MessageBox::Show("File \"Keywords.pm\" is Corrupted, " + error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					delete this;
					return;
				}
				else if((this->KeyWrd_Replacer->Get_Err() == Line_Error_KW_End) && ((signed long)(this->KeyWrd_Replacer->Get_Err_Line()) > (signed long)0))
				{
					error = "line " + this->KeyWrd_Replacer->Get_Err_Line() + " must be ended with pattern \"=>File name.c\"";
					System::Windows::Forms::MessageBox::Show("File \"Keywords.pm\" is Corrupted, " + error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					delete this;
					return;
				}
				else if((this->KeyWrd_Replacer->Get_Err() == Line_Error_KW_End) && ((signed long)this->KeyWrd_Replacer->Get_Err_Line() == (signed long)-1))
				{
					error = "the Whole File must be started with keyword \"Keywords:\"\nand ended with keyword \"ENDKeywords\" ";
					System::Windows::Forms::MessageBox::Show("File \"Keywords.pm\" is Corrupted, " + error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					delete this;
					return;
				}
			}
			else if(this->KeyWrd_Replacer->Get_File_Length() == 0)
			{
				this->Path = Path;
				this->Enable_Add = false;
				this->Is_File_Name_Entered = false;
				this->pat_num = gcnew Regex ("([0-9]+)");
				return;
			}
			this->Path = Path;
			this->Enable_Add = false;
			this->Is_File_Name_Entered = false;
			this->pat_num = gcnew Regex ("([0-9]+)");
			this->Fill_Tree();
			this->Load_File_Names();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Keyword_Replace()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^  treeView1;
	protected: 


	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  Add_button;
	private: System::Windows::Forms::Button^  Delete_button;
	private: System::Windows::Forms::Button^  Edit_button;
	private: ScintillaNET::Scintilla^  richTextBox1;
	private: Regex^ pat_num;
	private: System::String^ Path;
	private: array<System::Windows::Forms::TreeNode^>^ Snpts;
	private: TreeNode^ Global;
	private: bool Enable_Add;
	private: bool Is_File_Name_Entered;




	private: ScintillaNET::Scintilla^  richTextBox2;



	private: System::Windows::Forms::Button^  NewLine_button;

	private: System::Windows::Forms::Button^  Refresh_button;

	private: Main_package::Keyword_Replacer^ KeyWrd_Replacer;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Add_button = (gcnew System::Windows::Forms::Button());
			this->Delete_button = (gcnew System::Windows::Forms::Button());
			this->Edit_button = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew ScintillaNET::Scintilla());
			this->richTextBox2 = (gcnew ScintillaNET::Scintilla());
			this->NewLine_button = (gcnew System::Windows::Forms::Button());
			this->Refresh_button = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->richTextBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->richTextBox2))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// treeView1
			// 
			this->treeView1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->treeView1->Location = System::Drawing::Point(15, 29);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(148, 356);
			this->treeView1->TabIndex = 0;
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Keyword_Replace::treeView1_AfterSelect);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(308, 301);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Keyword_Replace::comboBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(191, 304);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Choose File Name :";
			this->label1->Click += gcnew System::EventHandler(this, &Keyword_Replace::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(183, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Original Line or Keyword :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(183, 190);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Replacment :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(124, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"List of Lines or Keywords";
			// 
			// Add_button
			// 
			this->Add_button->Location = System::Drawing::Point(308, 364);
			this->Add_button->Name = L"Add_button";
			this->Add_button->Size = System::Drawing::Size(80, 21);
			this->Add_button->TabIndex = 8;
			this->Add_button->Text = L"Add";
			this->Add_button->UseVisualStyleBackColor = true;
			this->Add_button->Click += gcnew System::EventHandler(this, &Keyword_Replace::Add_button_Click);
			// 
			// Delete_button
			// 
			this->Delete_button->Location = System::Drawing::Point(460, 364);
			this->Delete_button->Name = L"Delete_button";
			this->Delete_button->Size = System::Drawing::Size(80, 21);
			this->Delete_button->TabIndex = 9;
			this->Delete_button->Text = L"Delete";
			this->Delete_button->UseVisualStyleBackColor = true;
			this->Delete_button->Click += gcnew System::EventHandler(this, &Keyword_Replace::Delete_button_Click);
			// 
			// Edit_button
			// 
			this->Edit_button->Location = System::Drawing::Point(546, 364);
			this->Edit_button->Name = L"Edit_button";
			this->Edit_button->Size = System::Drawing::Size(80, 21);
			this->Edit_button->TabIndex = 10;
			this->Edit_button->Text = L"Edit";
			this->Edit_button->UseVisualStyleBackColor = true;
			this->Edit_button->Click += gcnew System::EventHandler(this, &Keyword_Replace::Edit_button_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->ConfigurationManager->Language = L"cs";
			this->richTextBox1->Indentation->TabWidth = 4;
			this->richTextBox1->Location = System::Drawing::Point(188, 57);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(438, 42);
			this->richTextBox1->Styles->BraceBad->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->BraceLight->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->CallTip->FontName = L"Segoe UI\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->ControlChar->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->Default->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox1->Styles->Default->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->IndentGuide->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->LastPredefined->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->LineNumber->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->Max->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->TabIndex = 11;
			// 
			// richTextBox2
			// 
			this->richTextBox2->ConfigurationManager->Language = L"cs";
			this->richTextBox2->Indentation->TabWidth = 4;
			this->richTextBox2->Location = System::Drawing::Point(186, 228);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(440, 44);
			this->richTextBox2->Styles->BraceBad->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->BraceLight->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->CallTip->FontName = L"Segoe UI\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->ControlChar->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->Default->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox2->Styles->Default->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->IndentGuide->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->LastPredefined->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->LineNumber->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->Max->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->TabIndex = 12;
			// 
			// NewLine_button
			// 
			this->NewLine_button->Location = System::Drawing::Point(210, 364);
			this->NewLine_button->Name = L"NewLine_button";
			this->NewLine_button->Size = System::Drawing::Size(80, 21);
			this->NewLine_button->TabIndex = 13;
			this->NewLine_button->Text = L"New Line";
			this->NewLine_button->UseVisualStyleBackColor = true;
			this->NewLine_button->Click += gcnew System::EventHandler(this, &Keyword_Replace::NewLine_button_Click);
			// 
			// Refresh_button
			// 
			this->Refresh_button->Location = System::Drawing::Point(546, 21);
			this->Refresh_button->Name = L"Refresh_button";
			this->Refresh_button->Size = System::Drawing::Size(80, 21);
			this->Refresh_button->TabIndex = 14;
			this->Refresh_button->Text = L"Refresh";
			this->Refresh_button->UseVisualStyleBackColor = true;
			this->Refresh_button->Click += gcnew System::EventHandler(this, &Keyword_Replace::Refresh_button_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 398);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(643, 22);
			this->statusStrip1->TabIndex = 15;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(118, 17);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			// 
			// Keyword_Replace
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(643, 420);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->Refresh_button);
			this->Controls->Add(this->NewLine_button);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->Edit_button);
			this->Controls->Add(this->Delete_button);
			this->Controls->Add(this->Add_button);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->treeView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Keyword_Replace";
			this->Text = L"Keyword_Replace";
			this->Load += gcnew System::EventHandler(this, &Keyword_Replace::Keyword_Replace_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->richTextBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->richTextBox2))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void Load_File_Names (void)
		{
			for(int i = 0; i< this->KeyWrd_Replacer->Get_Snpt_Count(); i++)
			{
				if(this->KeyWrd_Replacer->Get_snippit(i)[2]->Equals("") || this->comboBox1->Items->Contains(this->KeyWrd_Replacer->Get_snippit(i)[2]))
				{
					continue;
				}
				else
				{
					this->comboBox1->Items->Add(this->KeyWrd_Replacer->Get_snippit(i)[2]);
				}
			}
		}
		void Add_File_ToCombo(System::String^ s)
		{
			if(this->comboBox1->Items->Contains(s))
			{
				return;
			}
			else
			{
				this->comboBox1->Items->Add(s);
				return;
			}
		}
		bool Check_File_Name(System::String^ s)
		{
			return (Regex::IsMatch(s, "\\.[cC]$"));
		}
		void Fill_Tree(void)
		{
			int index = this->KeyWrd_Replacer->Get_Snpt_Count();
			this->Snpts = gcnew array<System::Windows::Forms::TreeNode^>(index);
			for(int i=0;i<index;i++)
			{
				Snpts[i] = gcnew TreeNode("Snippit " + i);
			}
			Global = gcnew TreeNode("Code", Snpts);
			this->treeView1->Nodes->Add(Global);
		}
		void Refresh_Tree(void)
		{
			int index = this->KeyWrd_Replacer->Get_Snpt_Count();
			this->Snpts = gcnew array<System::Windows::Forms::TreeNode^>(index);
			for(int i=0;i<index;i++)
			{
				Snpts[i] = gcnew TreeNode("Snippit " + i);
			}
			Global = gcnew TreeNode("Code", Snpts);
			this->treeView1->BeginUpdate();
			this->treeView1->Nodes->Clear();
			this->treeView1->Nodes->Add(Global);
			this->treeView1->EndUpdate();
			this->treeView1->ExpandAll();
		}
#pragma endregion
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Keyword_Replace_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) 
		 {
			 System::String^ loc_Text = e->Node->Text;
			 Match^ Num_match = this->pat_num->Match(loc_Text);
			 System::String^ Number = Num_match->Groups[1]->Value;
			 if(!(Number->Equals("")))
			 {
				 unsigned short Num = int::Parse(Number);
				 array<System::String^>^ Snpt =  this->KeyWrd_Replacer->Get_snippit(Num);
				 this->richTextBox1->Text = Snpt[0];
				 this->richTextBox2->Text = Snpt[1];
				 this->comboBox1->Text = Snpt[2];
			 }
			 else
			 {
				 this->richTextBox1->Text = "";
				 this->richTextBox2->Text = "";
				 this->comboBox1->Text = "";
			 }
			 this-> Enable_Add = false;
			 this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
			 this->toolStripStatusLabel1->Text = "Ready";
		 }
private: System::Void Refresh_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			this->KeyWrd_Replacer->Reload();
			if(!this->KeyWrd_Replacer->Load_File(Path))
			{
				System::String^ error = "";
				if(this->KeyWrd_Replacer->Get_Err() == Line_Error_KW_delim)
				{
					error = "there Must be a \"<>\"\nDelimiter in Line " + this->KeyWrd_Replacer->Get_Err_Line();
					System::Windows::Forms::MessageBox::Show("File \"Keywords.pm\" is Corrupted, " + error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					return;
				}
				else if((this->KeyWrd_Replacer->Get_Err() == Line_Error_KW_End) && ((signed long)(this->KeyWrd_Replacer->Get_Err_Line()) > (signed long)0))
				{
					error = "line " + this->KeyWrd_Replacer->Get_Err_Line() + " must be ended with pattern \"=>File name.c\"";
					System::Windows::Forms::MessageBox::Show("File \"Keywords.pm\" is Corrupted, " + error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					return;
				}
				else if((this->KeyWrd_Replacer->Get_Err() == Line_Error_KW_End) && ((signed long)this->KeyWrd_Replacer->Get_Err_Line() == (signed long)-1))
				{
					error = "the Whole File must be started with keyword \"Keywords:\"\nand ended with keyword \"ENDKeywords\" ";
					System::Windows::Forms::MessageBox::Show("File \"Keywords.pm\" is Corrupted, " + error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					return;
				}
			}
			else if(this->KeyWrd_Replacer->Get_File_Length() == 0)
			{
				this-> Enable_Add = false;
				this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
				this->toolStripStatusLabel1->Text = "Ready";
				this->richTextBox1->Text = "";
				this->richTextBox2->Text = "";
				this->Refresh_Tree();
				return;
			}
			this-> Enable_Add = false;
			this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
			this->toolStripStatusLabel1->Text = "Ready";
			this->richTextBox1->Text = "";
			this->richTextBox2->Text = "";
			this->Refresh_Tree();
		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void NewLine_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->richTextBox1->Text = "";
			 this->richTextBox2->Text = "";
			 this->comboBox1->Text = "";
			 this->treeView1->Refresh();
			 this-> Enable_Add = true;
			 this->toolStripStatusLabel1->Text = "Ready to Add Snippit";
			 this->Add_button->BackColor = System::Drawing::Color::Green;
		 }
private: System::Void Add_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(this->richTextBox1->Text->Equals("") || this->richTextBox2->Text->Equals(""))
			 {
				 System::Windows::Forms::MessageBox::Show("Cannot Take Empty String as input","Error",System::Windows::Forms::MessageBoxButtons::OK, 
					 System::Windows::Forms::MessageBoxIcon::Error);
				 return;
			 }
			 if(this->Enable_Add && Check_File_Name(this->comboBox1->Text))
			 {
				this->KeyWrd_Replacer->Create_Snippit(this->richTextBox1->Text,this->richTextBox2->Text, this->comboBox1->Text);
				this->Refresh_Tree();
				this-> Enable_Add = false;
				this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
				this->toolStripStatusLabel1->Text = "New Snippit Added";
				this->Add_File_ToCombo(this->comboBox1->Text);
			 }
			 else
			 {
				 if(!Check_File_Name(this->comboBox1->Text))
				 {
					 System::Windows::Forms::MessageBox::Show("Please Enter Correct File Name","Error",System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				 }
				 else
				 {
					 System::Windows::Forms::MessageBox::Show("Please Create New Snippit First","Error",System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				 }
			 }
		 }
private: System::Void Delete_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 try{if(this->treeView1->SelectedNode == nullptr){throw 1;}}catch(int x){return;}
			System::String^ loc_Text = this->treeView1->SelectedNode->Text;
			Match^ Num_match = this->pat_num->Match(loc_Text);
			System::String^ Number = Num_match->Groups[1]->Value;
			if(System::Windows::Forms::MessageBox::Show("Are you sure you Want to Delete this Snippit","Important",System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
			{
				if(!(Number->Equals("")))
				{
				 unsigned short Num = int::Parse(Number);
				 this->KeyWrd_Replacer->Delete_Snippit(Num);
				 this->richTextBox1->Text = "";
				 this->richTextBox2->Text = "";
				}
				else
				{
				 /* Do Nothing*/
				}
				this->Refresh_Tree();
				this->toolStripStatusLabel1->Text = "Snippit Deleted";
			}
			this-> Enable_Add = false;
			this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
		 }
private: System::Void Edit_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 try{if(this->treeView1->SelectedNode == nullptr){throw 1;}}catch(int x){return;}
			 array<System::String^>^ loc_data = gcnew array<System::String^>{this->richTextBox1->Text, this->richTextBox2->Text, this->comboBox1->Text};
			 System::String^ loc_Text = this->treeView1->SelectedNode->Text;
			 Match^ Num_match = this->pat_num->Match(loc_Text);
			 System::String^ Number = Num_match->Groups[1]->Value;
			 if(!(Number->Equals("")))
			 {
				 if(System::Windows::Forms::MessageBox::Show("Are you sure you Want to Edit this Snippit","Important",System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
				 {
					 if(Regex::IsMatch(this->richTextBox1->Text, "\\r") || Regex::IsMatch(this->richTextBox2->Text, "\\r"))
					 {
						 System::Windows::Forms::MessageBox::Show("Here you are allowed to replace only 1 line","Error",System::Windows::Forms::MessageBoxButtons::OK, 
							 System::Windows::Forms::MessageBoxIcon::Error);
						 return;
					 }
					unsigned short Num = int::Parse(Number);
					this->KeyWrd_Replacer->Edit_Snippit(loc_data,Num);
					this->Add_File_ToCombo(this->comboBox1->Text);
				 }
				 else
				 {
					 return;
				 }
			 }
			 else
			 {
				 /* Do Nothing*/
			 }
			 this->Refresh_Tree();
			 this-> Enable_Add = false;
			 this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
			 this->toolStripStatusLabel1->Text = "Snippit Edited";
		 }
};
}
