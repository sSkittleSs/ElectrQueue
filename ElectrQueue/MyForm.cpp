#include "MyForm.h"
#include <Windows.h>
using namespace ElectrQueue;

[STAThreadAttribute] //������� ������������� ���������� (STA), ��� ����������� ������ OLE

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ����������� ������ (����), ��������� ���������� �������� �� ������, � �� ������� ������. 
	Application::EnableVisualStyles(); // ������������� ������������ ���������� ������ � �� ��������� ���������� �������.
	Application::SetCompatibleTextRenderingDefault(false); // ������������� ������������� ����������� ������� ������, ���� ������ �������� false
	Application::Run(gcnew MyForm); // �������� ����� Run � �������� ��������� �� ����������� ��� �� ������������� ��������� ������ MyForm (���� �������� �����)
	return 0;
}
