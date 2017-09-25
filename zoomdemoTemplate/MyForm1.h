#pragma once
#include "CppQREncoder.h"
#include <string>
#include <iostream>
namespace zoomdemo001 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm1 摘要
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;
	public:
		Form ^form;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(101, 152);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->form->Hide();
		std::string std_str = "hello";
		const char *string = std_str.c_str();
		int version = 1;
		QRecLevel level = QR_ECLEVEL_L;
		QRencodeMode hint = QR_MODE_8;
		int casesensitive = 1;
		//QRcode * qrcode=QRcode_encodeString8bit(string, version, level);
		QRcode* qrcode = QRcode_encodeString(string, version, level, hint, casesensitive);
		if (qrcode == NULL){
			std::cout << "qrcode is null" << std::endl;
		}
		else{
			enum imageType image_type = PNG_TYPE;
			CppQREncoder *CppQr = new CppQREncoder();
			const char *outfile = "hello.png";
			std::cout << "outifle is " << outfile << std::endl;
			CppQr->writePNG(qrcode, outfile, image_type);

			if (CppQr != NULL){
				delete CppQr;
			}

			if (outfile != NULL){
				delete outfile;
			}
		}

		if (string != NULL){
			delete string;
		}
		if (qrcode != NULL){
			delete qrcode;
		}
		
	}
	};
}
