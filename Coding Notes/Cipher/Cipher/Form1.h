#pragma once
#include "Ceasar.h"
#include <string>

namespace Cipher
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
   using namespace System::IO;
   using std::string;

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
         fred = new Ceasar();
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

   private: System::Windows::Forms::TextBox^  txtbxMessage;
   private: System::Windows::Forms::MenuStrip^  menuStrip1;
   private: System::Windows::Forms::ToolStripMenuItem^  fileMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  openMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  saveMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  quitMenuItem;
   private: System::Windows::Forms::Button^  btnEncode;
   private: System::Windows::Forms::Button^  btnDecode;
   private: System::Windows::Forms::TextBox^  txtbxShift;
   private: System::Windows::Forms::Label^   lblShift;

            Ceasar *fred;
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
			this->txtbxMessage = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnEncode = (gcnew System::Windows::Forms::Button());
			this->btnDecode = (gcnew System::Windows::Forms::Button());
			this->txtbxShift = (gcnew System::Windows::Forms::TextBox());
			this->lblShift = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			//
			// txtbxMessage
			//
			this->txtbxMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtbxMessage->Location = System::Drawing::Point(12, 117);
			this->txtbxMessage->Multiline = true;
			this->txtbxMessage->Name = L"txtbxMessage";
			this->txtbxMessage->ReadOnly = true;
			this->txtbxMessage->Size = System::Drawing::Size(768, 433);
			this->txtbxMessage->TabIndex = 0;
			this->txtbxMessage->Text = L"ABCDEFGHIIJKLMNOPQRSTUVWXYZ";
			//
			// menuStrip1
			//
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(792, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuMain";
			//
			// fileMenuItem
			//
			this->fileMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->openMenuItem,
				this->saveMenuItem, this->quitMenuItem});
			this->fileMenuItem->Name = L"fileMenuItem";
			this->fileMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileMenuItem->Text = L"File";
			//
			// openMenuItem
			//
			this->openMenuItem->Name = L"openMenuItem";
			this->openMenuItem->Size = System::Drawing::Size(103, 22);
			this->openMenuItem->Text = L"Open";
			//
			// saveMenuItem
			//
			this->saveMenuItem->Name = L"saveMenuItem";
			this->saveMenuItem->Size = System::Drawing::Size(103, 22);
			this->saveMenuItem->Text = L"Save";
			//
			// quitMenuItem
			//
			this->quitMenuItem->Name = L"quitMenuItem";
			this->quitMenuItem->Size = System::Drawing::Size(103, 22);
			this->quitMenuItem->Text = L"Quit";
			//
			// btnEncode
			//
			this->btnEncode->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEncode->Location = System::Drawing::Point(12, 57);
			this->btnEncode->Name = L"btnEncode";
			this->btnEncode->Size = System::Drawing::Size(195, 54);
			this->btnEncode->TabIndex = 2;
			this->btnEncode->Text = L"ENCODE";
			this->btnEncode->UseVisualStyleBackColor = true;
			this->btnEncode->Click += gcnew System::EventHandler(this, &Form1::btnEncode_Click);
			//
			// btnDecode
			//
			this->btnDecode->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDecode->Location = System::Drawing::Point(238, 57);
			this->btnDecode->Name = L"btnDecode";
			this->btnDecode->Size = System::Drawing::Size(195, 54);
			this->btnDecode->TabIndex = 3;
			this->btnDecode->Text = L"DECODE";
			this->btnDecode->UseVisualStyleBackColor = true;
			this->btnDecode->Click += gcnew System::EventHandler(this, &Form1::btnDecode_Click);
			//
			// txtbxShift
			//
			this->txtbxShift->Font = (gcnew System::Drawing::Font(L"Verdana", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtbxShift->Location = System::Drawing::Point(667, 57);
			this->txtbxShift->Name = L"txtbxShift";
			this->txtbxShift->Size = System::Drawing::Size(113, 50);
			this->txtbxShift->TabIndex = 4;
			this->txtbxShift->Text = L"0";
			//
			// lblShift
			//
			this->lblShift->AutoSize = true;
			this->lblShift->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblShift->Location = System::Drawing::Point(577, 73);
			this->lblShift->Name = L"lblShift";
			this->lblShift->Size = System::Drawing::Size(72, 25);
			this->lblShift->TabIndex = 5;
			this->lblShift->Text = L"SHIFT";
			//
			// Form1
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 562);
			this->Controls->Add(this->lblShift);
			this->Controls->Add(this->txtbxShift);
			this->Controls->Add(this->btnDecode);
			this->Controls->Add(this->btnEncode);
			this->Controls->Add(this->txtbxMessage);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Cipher Demo";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

private:
   System::Void openMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
   {
      OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
      StreamReader^ srTextFile;
      Stream^ inputStream;
      openFileDialog1->InitialDirectory = ".";
      openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
      openFileDialog1->FilterIndex = 2;
      openFileDialog1->RestoreDirectory = true;
      if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
      {
         if ( (inputStream = openFileDialog1->OpenFile()) != nullptr )
         {
            // Insert code to read the stream here.
            try
            {
               // Create an instance of StreamReader to read from a file.
               // The using statement also closes the StreamReader.
               srTextFile = gcnew StreamReader(inputStream);
               try
               {
                  String^ strLine;
                  this->txtbxMessage->Text = "";  // clear out the textbox for a new file
                  // Read and display lines from the file until the end of
                  // the file is reached.
                  while ( strLine = srTextFile->ReadLine() )
                  {
                     this->txtbxMessage->Text += strLine + "\r\n";
                  }
               }
               finally
               {
                  if ( srTextFile )
                  {
                     delete (IDisposable^)srTextFile;
                  }
               }
            }
            catch ( Exception^ ex )
            {
               // Let the user know what went wrong.
               MessageBox::Show( "The file could not be read: " + ex->Message );
            }
            inputStream->Close();
         }
      }
   }
private: System::Void btnEncode_Click(System::Object^  sender, System::EventArgs^  e)
         {
            string temp;
            for ( int i = 0; i < this->txtbxMessage->Text->Length; ++i )
            {
               temp.push_back(char(this->txtbxMessage->Text[i]));
            }
            fred->setMessage(temp);
            fred->setShift(Int32::Parse(this->txtbxShift->Text));
            fred->encode();
            temp = fred->getMessage();
            this->txtbxMessage->Text = gcnew String(temp.c_str());
         }
private: System::Void btnDecode_Click(System::Object^  sender, System::EventArgs^  e)
         {
            string temp;
            for ( int i = 0; i < this->txtbxMessage->Text->Length; ++i )
            {
               temp.push_back(char(this->txtbxMessage->Text[i]));
            }
            fred->setMessage(temp);
            fred->setShift(Int32::Parse(this->txtbxShift->Text));
            fred->decode();
            temp = fred->getMessage();
            this->txtbxMessage->Text = gcnew String(temp.c_str());
         }
};
}