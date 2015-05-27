#pragma once
#include "pa7a.h"

namespace PA7A {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			caesarText = new Caesar ();
			substitutionText = new Substitution ();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  cipherKey;
	private: System::Windows::Forms::TextBox^  cipherText;

			 Caesar *caesarText;
			 Substitution *substitutionText;
	private: System::Windows::Forms::TextBox^  statusText;
	private: System::Windows::Forms::Button^  button3;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cipherKey = (gcnew System::Windows::Forms::TextBox());
			this->cipherText = (gcnew System::Windows::Forms::TextBox());
			this->statusText = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			//
			// menuStrip1
			//
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(9, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(465, 31);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			//
			// fileToolStripMenuItem
			//
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->openToolStripMenuItem,
				this->saveToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 25);
			this->fileToolStripMenuItem->Text = L"File";
			//
			// openToolStripMenuItem
			//
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			//
			// saveToolStripMenuItem
			//
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			//
			// button1
			//
			this->button1->Location = System::Drawing::Point(62, 480);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Encode";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			//
			// button2
			//
			this->button2->Location = System::Drawing::Point(182, 480);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 35);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Decode";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 40);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Cipher Key:";
			//
			// radioButton1
			//
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(118, 79);
			this->radioButton1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(128, 24);
			this->radioButton1->TabIndex = 4;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Caesar Cipher";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			//
			// radioButton2
			//
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(118, 113);
			this->radioButton2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(162, 24);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->Text = L"Substitution Cipher";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			//
			// label2
			//
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 81);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Cipher Type:";
			//
			// label3
			//
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 149);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Text:";
			//
			// cipherKey
			//
			this->cipherKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cipherKey->Location = System::Drawing::Point(110, 40);
			this->cipherKey->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cipherKey->Name = L"cipherKey";
			this->cipherKey->Size = System::Drawing::Size(292, 26);
			this->cipherKey->TabIndex = 0;
			//
			// cipherText
			//
			this->cipherText->Location = System::Drawing::Point(64, 148);
			this->cipherText->Multiline = true;
			this->cipherText->Name = L"cipherText";
			this->cipherText->Size = System::Drawing::Size(338, 292);
			this->cipherText->TabIndex = 0;
			//
			// statusText
			//
			this->statusText->Location = System::Drawing::Point(12, 446);
			this->statusText->Name = L"statusText";
			this->statusText->ReadOnly = true;
			this->statusText->Size = System::Drawing::Size(441, 26);
			this->statusText->TabIndex = 8;
			this->statusText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			//
			// button3
			//
			this->button3->Location = System::Drawing::Point(301, 480);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(103, 35);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Codebreak";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			//
			// Form1
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(465, 524);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->statusText);
			this->Controls->Add(this->cipherText);
			this->Controls->Add(this->cipherKey);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->Text = L"PA7A: Cipher Objects in C++";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
		// Encode Button
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				bool isCaesar = this->radioButton1->Checked;
				this->statusText->Text = "Encoding...";
				string temp = marshal_as<std::string>(this->cipherText->Text);
				string cipherTemp = marshal_as<std::string>(this->cipherKey->Text);

				if (cipherTemp != "")
				{
					if (isCaesar == true)
					{
						 this->statusText->Text += "Caesar Shift...";
						caesarText->setMText (temp);
						caesarText->setCipher (cipherTemp);
						bool success = caesarText->encode ();
						if (success)
						{
							temp = caesarText->getMText ();
							this->cipherText->Text = gcnew String(temp.c_str());
							this->statusText->Text += "Encoding Successful!";
						}
						else
						{
							this->statusText->Text += "Failed to Encode!";
						}
					}
					else
					{
						 this->statusText->Text += "Substitution Method...";
						substitutionText->setMText (temp);
						substitutionText->setCipher (cipherTemp);
						bool success = substitutionText->encode ();
						if (success)
						{
							temp = substitutionText->getMText ();
							this->cipherText->Text = gcnew String(temp.c_str());
							this->statusText->Text += "Encoding Successful!";
						}
						else
						{
							this->statusText->Text += "Failed to Encode!";
						}
					}
				}
				else
				{
					this->statusText->Text += "Failed to Encode, no cipher key!";
				}
			 }
			 // Decode Button
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				bool isCaesar = this->radioButton1->Checked;
				this->statusText->Text = "Decoding...";
				string temp = marshal_as<std::string>(this->cipherText->Text);
				string cipherTemp = marshal_as<std::string>(this->cipherKey->Text);

				if (cipherTemp != "")
				{
					if (isCaesar == true)
					{
						 this->statusText->Text += "Caesar Shift...";
						caesarText->setMText (temp);
						caesarText->setCipher (cipherTemp);
						bool success = caesarText->decode ();
						if (success)
						{
							temp = caesarText->getMText ();
							this->cipherText->Text = gcnew String(temp.c_str());
							this->statusText->Text += "Decoding Successful!";
						}
						else
						{
							this->statusText->Text += "Failed to Decode!";
						}
					}
					else
					{
						 this->statusText->Text += "Substitution Method...";
						substitutionText->setMText (temp);
						substitutionText->setCipher (cipherTemp);
						bool success = substitutionText->decode ();
						if (success)
						{
							temp = substitutionText->getMText ();
							this->cipherText->Text = gcnew String(temp.c_str());
							this->statusText->Text += "Decoding Successful!";
						}
						else
						{
							this->statusText->Text += "Failed to Decode!";
						}
					}
				}
				else
				{
					this->statusText->Text += "Failed to Encode, no cipher key!";
				}
		 }
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->statusText->Text = "Cipher method changed to Caesar shift";
		 }
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->statusText->Text = "Cipher method changed to Substitution shift";
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Code Break Attempt
			bool isCaesar = this->radioButton1->Checked;
			this->statusText->Text = "Attempting to break code...";
			string temp = marshal_as<std::string>(this->cipherText->Text);

				if (isCaesar == true)
				{
					 this->statusText->Text += "Caesar Shift...";
					caesarText->setMText (temp);
					bool success = caesarText->breakCode ();
					if (success)
					{
						temp = caesarText->getMText ();
						this->cipherText->Text = gcnew String(temp.c_str());
						this->statusText->Text += "Attempt Successful!";
					}
					else
					{
						this->statusText->Text += "Attempt failed!";
					}
				}
				else
				{
					 this->statusText->Text += "Substitution Method...";
					substitutionText->setMText (temp);
					bool success = substitutionText->breakCode ();
					if (success)
					{
						temp = substitutionText->getMText ();
						this->cipherText->Text = gcnew String(temp.c_str());
						this->statusText->Text += "Attempt Successful!";
					}
					else
					{
						this->statusText->Text += "Attempt failed!";
					}
				}
		 }
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ofstream output;
			string outputFile = "cipher.txt";
			output.open (outputFile.c_str (), std::ios::out);
			output << marshal_as<std::string>(this->cipherKey->Text) << endl;
			output << marshal_as<std::string>(this->cipherText->Text);
			output.close ();
		 }
private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ifstream input;
			string inputFile = "cipher.txt";
			string tempKey;
			string tempText;
			input.open (inputFile.c_str (), std::ios::in);
			input >> tempKey;
			input >> tempText;
			input.close ();
			this->cipherKey->Text = gcnew String(tempKey.c_str());
			this->cipherText->Text = gcnew String(tempText.c_str());
		 }
};
}