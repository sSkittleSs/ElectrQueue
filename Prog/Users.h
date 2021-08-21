#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>

struct Date {
	size_t day;
	size_t month;
	size_t year;
};

struct Users {
	std::string surnameNP;
	std::string surname;
	std::string name;
	std::string prozv;
	std::string password;
	//size_t recordsAmount;
	//size_t ownNumsInQueues[30];
	Date birthday;
	//size_t cancelAmount;

	Users() {
		surnameNP = "";
		surname = "";
		name = "";
		prozv = "";
		password = "";
		/*recordsAmount = 0;
		for (size_t i = 0; i < 30; i++)
			ownNumsInQueues[i] = 0;*/
		birthday.day = 16;
		birthday.month = 02;
		birthday.year = 2000;
		//cancelAmount = 0;
	}
};

//std::ostream& operator<<(std::ostream& out, Users user) {
//	//out << user.surnameNP << std::endl << user.surname << std::endl << user.name << std::endl << user.prozv << std::endl << user.cancelAmount << std::endl << user.birthday.day << ' ' << user.birthday.month << ' ' << user.birthday.year << std::endl << user.password << std::endl << user.recordsAmount << std::endl;
//	out << user.surnameNP << std::endl << user.surname << std::endl << user.name << std::endl << user.prozv << std::endl << user.birthday.day << ' ' << user.birthday.month << ' ' << user.birthday.year << std::endl << user.password << std::endl;
//	/*for (size_t i = 0; i < 30; i++) {
//		out << user.ownNumsInQueues[i] << " | ";
//	}*/
//	//out << std::endl;
//
//	return out;
//}
//
//std::istream& operator>>(std::istream& in, Users* user) {
//	char name[51]{};
//	in.getline(name, 51, '\n');
//	user->surnameNP = name;
//	in.getline(name, 51, '\n');
//	user->surname = name;
//	in.getline(name, 51, '\n');
//	user->name = name;
//	in.getline(name, 51, '\n');
//	user->prozv = name;
//
//	//in >> user->cancelAmount >> user->birthday.day >> user->birthday.month >> user->birthday.year;
//	in >> user->birthday.day >> user->birthday.month >> user->birthday.year;
//	char pass[26]{};
//	in.getline(pass, 26, '\n');
//	in.getline(pass, 26, '\n');
//	user->password = pass;
//
//	/*in >> user->recordsAmount;
//	for (size_t i = 0; i < 30; i++) {
//		char chr{};
//		in >> user->ownNumsInQueues[i] >> chr;
//	}*/
//	return in;
//}