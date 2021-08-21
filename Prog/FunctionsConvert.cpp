#include "FunctionsConvert.h"

std::string& ConvertStringToSTDString(System::String^ string, std::string& stdString) {
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(string)).ToPointer();
	stdString = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return stdString;
}

System::String^ ConvertSTDStringToString(std::string& stdString) {
	System::String^ string = gcnew System::String(stdString.c_str());

	return string;
}

System::String^ ConvertCharToString(char* ch) {
	char* chr = new char();
	chr = ch;
	System::String^ string;
	for (int i = 0; chr[i] != '\0'; i++) {
		string += wchar_t(ch[i]);
	}

	return string;
}

char* ConvertStringToChar(System::String^ string) {
	using namespace Runtime::InteropServices;

	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}

std::ostream& operator<<(std::ostream& out, Users user) {
	//out << user.surnameNP << std::endl << user.surname << std::endl << user.name << std::endl << user.prozv << std::endl << user.cancelAmount << std::endl << user.birthday.day << ' ' << user.birthday.month << ' ' << user.birthday.year << std::endl << user.password << std::endl << user.recordsAmount << std::endl;
	out << user.surnameNP << std::endl << user.surname << std::endl << user.name << std::endl << user.prozv << std::endl << user.birthday.day << ' ' << user.birthday.month << ' ' << user.birthday.year << std::endl << user.password << std::endl;
	/*for (size_t i = 0; i < 30; i++) {
		out << user.ownNumsInQueues[i] << " | ";
	}*/
	//out << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Users* user) {
	char name[51]{};
	in.getline(name, 51, '\n');
	user->surnameNP = name;
	in.getline(name, 51, '\n');
	user->surname = name;
	in.getline(name, 51, '\n');
	user->name = name;
	in.getline(name, 51, '\n');
	user->prozv = name;

	//in >> user->cancelAmount >> user->birthday.day >> user->birthday.month >> user->birthday.year;
	in >> user->birthday.day >> user->birthday.month >> user->birthday.year;
	char pass[26]{};
	in.getline(pass, 26, '\n');
	in.getline(pass, 26, '\n');
	user->password = pass;

	/*in >> user->recordsAmount;
	for (size_t i = 0; i < 30; i++) {
		char chr{};
		in >> user->ownNumsInQueues[i] >> chr;
	}*/
	return in;
}
