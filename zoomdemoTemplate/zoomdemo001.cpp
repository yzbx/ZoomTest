// zoomdemo001.cpp: 主项目文件。
#include "MyForm.h"
#include "MyForm1.h"
using namespace System;
using namespace zoomdemo001;
int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");
	MyForm myform;
	MyForm1 myform1;

	myform.form = %myform1;
	myform1.form = %myform;
	Application::EnableVisualStyles();
	//Application::Run(gcnew MyForm());
	myform.Show();
	Application::Run(%myform1);
    return 0;
}
