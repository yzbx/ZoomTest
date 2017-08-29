#pragma once
#include "ZoomTest.h"
//#pragma comment(lib, "user32.lib")
namespace zoomdemo {

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

			if (zoomtest) 
			{
				delete zoomtest;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;


	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;
		ZoomTest* zoomtest;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(102)));
			this->label1->Location = System::Drawing::Point(17, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"二维码扫描登录";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(5, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(200, 200);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(153)),
				static_cast<System::Int32>(static_cast<System::Byte>(153)));
			this->label2->Location = System::Drawing::Point(43, 267);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(152, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"打开手机随会，扫描二维码";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)));
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Padding = System::Windows::Forms::Padding(10);
			this->panel1->Size = System::Drawing::Size(250, 308);
			this->panel1->TabIndex = 3;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->panel2->Location = System::Drawing::Point(20, 50);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(210, 210);
			this->panel2->TabIndex = 4;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Controls->Add(this->label7);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Controls->Add(this->panel5);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Location = System::Drawing::Point(251, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(273, 308);
			this->panel3->TabIndex = 4;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"微软雅黑", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(153)),
				static_cast<System::Int32>(static_cast<System::Byte>(153)));
			this->label7->Location = System::Drawing::Point(190, 167);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(79, 20);
			this->label7->TabIndex = 8;
			this->label7->Text = L"忘记密码？";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"微软雅黑", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(143, 270);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(65, 20);
			this->label6->TabIndex = 7;
			this->label6->Text = L"立即注册";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"微软雅黑", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->label5->Location = System::Drawing::Point(56, 270);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 20);
			this->label5->TabIndex = 6;
			this->label5->Text = L"还有没账号？";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"微软雅黑", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(153)),
				static_cast<System::Int32>(static_cast<System::Byte>(153)));
			this->label4->Location = System::Drawing::Point(125, 246);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"或";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(186)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(12, 196);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(250, 40);
			this->button1->TabIndex = 4;
			this->button1->Text = L"登录";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Controls->Add(this->textBox2);
			this->panel5->Location = System::Drawing::Point(12, 115);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(250, 40);
			this->panel5->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"微软雅黑", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->textBox2->Location = System::Drawing::Point(3, 10);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(242, 19);
			this->textBox2->TabIndex = 0;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->textBox1);
			this->panel4->Font = (gcnew System::Drawing::Font(L"宋体", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(134)));
			this->panel4->Location = System::Drawing::Point(12, 56);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(250, 40);
			this->panel4->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->textBox1->Location = System::Drawing::Point(3, 10);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(242, 19);
			this->textBox1->TabIndex = 1;
			this->textBox1->WordWrap = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"微软雅黑", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(134)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
				static_cast<System::Int32>(static_cast<System::Byte>(102)));
			this->label3->Location = System::Drawing::Point(9, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 20);
			this->label3->TabIndex = 0;
			this->label3->Text = L"账号登录";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(209)), static_cast<System::Int32>(static_cast<System::Byte>(216)),
				static_cast<System::Int32>(static_cast<System::Byte>(223)));
			this->ClientSize = System::Drawing::Size(524, 308);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"微软雅黑", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"随会";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		/*if (zoomtest->SDKAuth()) {
			MessageBox::Show(_T("SDK auth okay!"), _T("SDK auth"));
		}
		else {
			MessageBox::Show(_T("SDK auth faild!"), _T("SDK auth"));
		}

		if (zoomtest->APIUserStart()) {
			MessageBox::Show(_T("APIUserStart okay!"), _T("APIUserStart"));
		}
		else {
			MessageBox::Show(_T("APIUserStart faild!"), _T("APIUserStart"));
		}*/

		zoomtest->showMessage(zoomtest->SDKAuth(), "SDK auth");
		MessageBox::Show(_T("进入会议!"), _T("进入会议"));
		zoomtest->showMessage(zoomtest->APIUserStart(), "APIUserStart");
		
		System::String^ username = this->textBox1->Text;
		System::String^ password = this->textBox2->Text;
		//Console::WriteLine("username is "+username);
		//Console::WriteLine("password is " + password);
	}
};
}
