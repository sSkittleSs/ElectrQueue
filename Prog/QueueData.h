#pragma once
#include <string>
#include <iostream>

struct ownTime { // ��������� �������
	double hours;
	double minutes;
	//size_t second;

	bool operator==(ownTime& other) { return hours == other.hours && minutes == other.minutes; }
};

struct queueData { // ��������� ������ ��� ���� �������
	std::string surnameNP; // ������� �.�.
	size_t ownNumber; // ������ ����� � �������
	ownTime time; // ������� �����

	queueData() {
		surnameNP = "����� �� ������";
		ownNumber = 0;
		time.hours = 0;
		time.minutes = 0;
	}
	queueData(ownTime time, size_t ownNumber, std::string surnameNP) {
		this->surnameNP = surnameNP;
		this->ownNumber = ownNumber;
		this->time.hours = time.hours;
		this->time.minutes = time.minutes;
	}
	/*std::ostream& operator<<(std::ostream&, const queueData&);
	std::istream& operator>>(std::istream&, queueData&);*/
};

//std::ostream& operator<<(std::ostream& out, const queueData& data) {
//	out << data.ownNumber << " | " << data.time.hours << " : " << data.time.minutes << " | " << data.surnameNP;
//
//	return out;
//}
//
//std::istream& operator>>(std::istream& in, queueData& data) {
//	char tempChar;
//	in >> data.ownNumber >> tempChar >> data.time.hours >> tempChar >> data.time.minutes >> tempChar;// >> data.surnameNP;
//	char tempCharArr[60];
//	in.getline(tempCharArr, 60, '\n');
//	data.surnameNP = tempCharArr;
//
//	return in;
//}