#include "MyForm.h"
#include <Windows.h>
using namespace ElectrQueue;

[STAThreadAttribute] //Атрибут однопоточного контейнера (STA), для возможности вызова OLE

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// Статические методы (ниже), поскольку вызывается напрямую из класса, а не объекта класса. 
	Application::EnableVisualStyles(); // Устанавливает доуступность визуальных стилей и не позволяет отображать консоль.
	Application::SetCompatibleTextRenderingDefault(false); // Устанавливает единообразное отображение шрифтов текста, если примет аргумент false
	Application::Run(gcnew MyForm); // Вызываем метод Run и передаем указатель на создаваемый тут же конструктором экземпляр класса MyForm (либо название формы)
	return 0;
}
