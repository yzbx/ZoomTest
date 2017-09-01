#pragma once
#include "ZoomTest.h"
#include "WinHttp001.h"
#include "WinJson.h"
namespace zoomdemo001 {

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
			zoomtest = new ZoomTest();
			winhttp001 = new WinHttp001();
		}

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

			if (zoomtest) {
				delete zoomtest;
			}

			if (winhttp001) {
				delete winhttp001;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;
		ZoomTest * zoomtest;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
		WinHttp001 *winhttp001;
	public:
		Form ^form;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(21, 214);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"zoomtest";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(176, 214);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"httptest";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// pictureBox1
			// 
			//this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Image = System::Drawing::Image::FromFile(L"libqrencode\\hello.png");
			this->pictureBox1->Location = System::Drawing::Point(85, 65);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(91, 88);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		zoomtest->showMessage(zoomtest->SDKAuth(), "SDK auth");
		MessageBox::Show(_T("进入会议!"), _T("进入会议"));
		zoomtest->showMessage(zoomtest->APIUserStart(), "APIUserStart");
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		winhttp001->WinHttpTest();

		//msclr::interop::marshal_context context;
		std::map<std::string, std::wstring> param_map;
		/*param_map["hostname"] = context.marshal_as<std::wstring>(this->textBox_hostname->Text);
		param_map["urlpath"] = context.marshal_as<std::wstring>(this->textBox_urlpath->Text);
		param_map["apiversion"] = context.marshal_as<std::wstring>(this->textBox_apiversion->Text);
		param_map["password"] = context.marshal_as<std::wstring>(this->textBox_password->Text);
		param_map["phone"] = context.marshal_as<std::wstring>(this->textBox_phone->Text);
		param_map["safecode"] = context.marshal_as<std::wstring>(this->textBox_safecode->Text);
		param_map["site_id"] = context.marshal_as<std::wstring>(this->textBox_site_id->Text);*/
		param_map["hostname"] = L"www.suimeeting.cn";
		param_map["urlpath"] = L"Api/User/login.html";
		param_map["apiversion"] = L"v1";
		param_map["password"] = L"123456";
		param_map["phone"] = L"18210560183";
		param_map["safecode"] = L"c989e271e11455ea290252ec9e216912";
		param_map["site_id"] = L"0";
		std::string returnstr = winhttp001->WinHttpPost(param_map);

		std::cout << "\n return string is: \n";
		std::cout << returnstr << std::endl;

		WinJson *winjson = new WinJson();
		std::map<std::string, std::string> jmap = winjson->process(returnstr);
		for (std::map<std::string, std::string>::iterator it = jmap.begin(); it != jmap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		WinJson *winjson1 = new WinJson();
		std::string resstr = jmap["res"];
		std::map<std::string, std::string> resmap = winjson1->process(resstr);
		for (std::map<std::string, std::string>::iterator it = resmap.begin(); it != resmap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		if (winjson)
		{
			delete winjson;
		}

		if (winjson1){
			delete winjson1;
		}

	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->pictureBox1->Image = (System::Drawing::Image::FromFile(L"libqrencode\\hello.png"));
	}
};
}
