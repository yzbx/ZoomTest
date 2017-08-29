#include "MyForm.h"

using namespace WinHttpDemo;
int Main(array<System::String^>^args) {
	//webget();
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
	return 0;
}
