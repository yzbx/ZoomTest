#pragma once
#include <msclr\marshal_cppstd.h>
#include <stdio.h>
#include <map>
#include <iostream>

namespace WinHttpDemo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
			this->textBox_apiversion->Text = L"v1";
			this->textBox_hostname->Text = L"www.suimeeting.cn";
			this->textBox_password->Text = L"123456";
			this->textBox_phone->Text = L"18210560183";
			this->textBox_safecode->Text = L"c989e271e11455ea290252ec9e216912";
			this->textBox_site_id->Text = L"0";
			this->textBox_urlpath->Text = L"Api/User/login.html";
		};
		void WinHttpTest();
		std::string WinHttpPost(std::map<std::string,std::wstring> param_map);
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_post;
	private: System::Windows::Forms::TextBox^  textBox_hostname;
	private: System::Windows::Forms::TextBox^  textBox_urlpath;
	private: System::Windows::Forms::TextBox^  textBox_apiversion;
	private: System::Windows::Forms::TextBox^  textBox_site_id;
	private: System::Windows::Forms::TextBox^  textBox_safecode;
	private: System::Windows::Forms::TextBox^  textBox_phone;
	private: System::Windows::Forms::TextBox^  textBox_password;
	protected:








	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  label_password;

	private: System::Windows::Forms::Label^  label_safecode;

	private: System::Windows::Forms::Label^  label_hostname;
	private: System::Windows::Forms::Label^  label_site_id;
	private: System::Windows::Forms::Label^  label_phone;




	private: System::Windows::Forms::Label^  label_apiversion;

	private: System::Windows::Forms::Label^  label_urlpath;
	private: System::Windows::Forms::Button^  button_test;


	protected:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_post = (gcnew System::Windows::Forms::Button());
			this->textBox_hostname = (gcnew System::Windows::Forms::TextBox());
			this->textBox_urlpath = (gcnew System::Windows::Forms::TextBox());
			this->textBox_apiversion = (gcnew System::Windows::Forms::TextBox());
			this->textBox_site_id = (gcnew System::Windows::Forms::TextBox());
			this->textBox_safecode = (gcnew System::Windows::Forms::TextBox());
			this->textBox_phone = (gcnew System::Windows::Forms::TextBox());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label_phone = (gcnew System::Windows::Forms::Label());
			this->label_hostname = (gcnew System::Windows::Forms::Label());
			this->label_apiversion = (gcnew System::Windows::Forms::Label());
			this->label_urlpath = (gcnew System::Windows::Forms::Label());
			this->label_site_id = (gcnew System::Windows::Forms::Label());
			this->label_password = (gcnew System::Windows::Forms::Label());
			this->label_safecode = (gcnew System::Windows::Forms::Label());
			this->button_test = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_post
			// 
			this->button_post->Location = System::Drawing::Point(244, 220);
			this->button_post->Name = L"button_post";
			this->button_post->Size = System::Drawing::Size(75, 23);
			this->button_post->TabIndex = 0;
			this->button_post->Text = L"post";
			this->button_post->UseVisualStyleBackColor = true;
			this->button_post->Click += gcnew System::EventHandler(this, &MyForm::button_post_Click);
			// 
			// textBox_hostname
			// 
			this->textBox_hostname->Location = System::Drawing::Point(74, 3);
			this->textBox_hostname->Name = L"textBox_hostname";
			this->textBox_hostname->Size = System::Drawing::Size(294, 21);
			this->textBox_hostname->TabIndex = 1;
			// 
			// textBox_urlpath
			// 
			this->textBox_urlpath->Location = System::Drawing::Point(74, 30);
			this->textBox_urlpath->Name = L"textBox_urlpath";
			this->textBox_urlpath->Size = System::Drawing::Size(294, 21);
			this->textBox_urlpath->TabIndex = 4;
			// 
			// textBox_apiversion
			// 
			this->textBox_apiversion->Location = System::Drawing::Point(74, 56);
			this->textBox_apiversion->Name = L"textBox_apiversion";
			this->textBox_apiversion->Size = System::Drawing::Size(294, 21);
			this->textBox_apiversion->TabIndex = 5;
			// 
			// textBox_site_id
			// 
			this->textBox_site_id->Location = System::Drawing::Point(74, 84);
			this->textBox_site_id->Name = L"textBox_site_id";
			this->textBox_site_id->Size = System::Drawing::Size(294, 21);
			this->textBox_site_id->TabIndex = 6;
			// 
			// textBox_safecode
			// 
			this->textBox_safecode->Location = System::Drawing::Point(74, 112);
			this->textBox_safecode->Name = L"textBox_safecode";
			this->textBox_safecode->Size = System::Drawing::Size(294, 21);
			this->textBox_safecode->TabIndex = 7;
			// 
			// textBox_phone
			// 
			this->textBox_phone->Location = System::Drawing::Point(74, 137);
			this->textBox_phone->Name = L"textBox_phone";
			this->textBox_phone->Size = System::Drawing::Size(294, 21);
			this->textBox_phone->TabIndex = 13;
			// 
			// textBox_password
			// 
			this->textBox_password->Location = System::Drawing::Point(74, 157);
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->Size = System::Drawing::Size(294, 21);
			this->textBox_password->TabIndex = 14;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->textBox_password, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->textBox_phone, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->label_phone, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->textBox_hostname, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox_safecode, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->textBox_urlpath, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox_site_id, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox_apiversion, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label_hostname, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label_apiversion, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label_urlpath, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label_site_id, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label_password, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->label_safecode, 0, 4);
			this->tableLayoutPanel1->Location = System::Drawing::Point(38, 23);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 7;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 22)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(368, 176);
			this->tableLayoutPanel1->TabIndex = 15;
			// 
			// label_phone
			// 
			this->label_phone->AutoSize = true;
			this->label_phone->Location = System::Drawing::Point(3, 134);
			this->label_phone->Name = L"label_phone";
			this->label_phone->Size = System::Drawing::Size(35, 12);
			this->label_phone->TabIndex = 18;
			this->label_phone->Text = L"phone";
			// 
			// label_hostname
			// 
			this->label_hostname->AutoSize = true;
			this->label_hostname->Location = System::Drawing::Point(3, 0);
			this->label_hostname->Name = L"label_hostname";
			this->label_hostname->Size = System::Drawing::Size(53, 12);
			this->label_hostname->TabIndex = 13;
			this->label_hostname->Text = L"hostname";
			// 
			// label_apiversion
			// 
			this->label_apiversion->AutoSize = true;
			this->label_apiversion->Location = System::Drawing::Point(3, 53);
			this->label_apiversion->Name = L"label_apiversion";
			this->label_apiversion->Size = System::Drawing::Size(65, 12);
			this->label_apiversion->TabIndex = 15;
			this->label_apiversion->Text = L"apiversion";
			// 
			// label_urlpath
			// 
			this->label_urlpath->AutoSize = true;
			this->label_urlpath->Location = System::Drawing::Point(3, 27);
			this->label_urlpath->Name = L"label_urlpath";
			this->label_urlpath->Size = System::Drawing::Size(47, 12);
			this->label_urlpath->TabIndex = 14;
			this->label_urlpath->Text = L"urlpath";
			// 
			// label_site_id
			// 
			this->label_site_id->AutoSize = true;
			this->label_site_id->Location = System::Drawing::Point(3, 81);
			this->label_site_id->Name = L"label_site_id";
			this->label_site_id->Size = System::Drawing::Size(47, 12);
			this->label_site_id->TabIndex = 17;
			this->label_site_id->Text = L"site_id";
			// 
			// label_password
			// 
			this->label_password->AutoSize = true;
			this->label_password->Location = System::Drawing::Point(3, 154);
			this->label_password->Name = L"label_password";
			this->label_password->Size = System::Drawing::Size(53, 12);
			this->label_password->TabIndex = 19;
			this->label_password->Text = L"password";
			// 
			// label_safecode
			// 
			this->label_safecode->AutoSize = true;
			this->label_safecode->Location = System::Drawing::Point(3, 109);
			this->label_safecode->Name = L"label_safecode";
			this->label_safecode->Size = System::Drawing::Size(53, 12);
			this->label_safecode->TabIndex = 16;
			this->label_safecode->Text = L"safecode";
			// 
			// button_test
			// 
			this->button_test->Location = System::Drawing::Point(112, 219);
			this->button_test->Name = L"button_test";
			this->button_test->Size = System::Drawing::Size(75, 23);
			this->button_test->TabIndex = 16;
			this->button_test->Text = L"test";
			this->button_test->UseVisualStyleBackColor = true;
			this->button_test->Click += gcnew System::EventHandler(this, &MyForm::button_test_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 251);
			this->Controls->Add(this->button_test);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->button_post);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_post_Click(System::Object^  sender, System::EventArgs^  e) {
		
		msclr::interop::marshal_context context;
		std::map<std::string, std::wstring> param_map;
		param_map["hostname"]= context.marshal_as<std::wstring>(this->textBox_hostname->Text);
		param_map["urlpath"] = context.marshal_as<std::wstring>(this->textBox_urlpath->Text);
		param_map["apiversion"] = context.marshal_as<std::wstring>(this->textBox_apiversion->Text);
		param_map["password"] = context.marshal_as<std::wstring>(this->textBox_password->Text);
		param_map["phone"] = context.marshal_as<std::wstring>(this->textBox_phone->Text);
		param_map["safecode"] = context.marshal_as<std::wstring>(this->textBox_safecode->Text);
		param_map["site_id"] = context.marshal_as<std::wstring>(this->textBox_site_id->Text);
		std::string returnstr=WinHttpPost(param_map);
		
		std::cout << "\n return string is: \n";
		std::cout << returnstr << std::endl;
	}
	private: System::Void button_test_Click(System::Object^  sender, System::EventArgs^  e) {
		WinHttpTest();
	}
};
	
std::string WStringToString(const std::wstring & wstr);

}
