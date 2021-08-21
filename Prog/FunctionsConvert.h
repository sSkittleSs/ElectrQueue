#pragma once
#include <string>
#include "Users.h"
using namespace System;

std::string& ConvertStringToSTDString(String^ string, std::string& stdString);
String^ ConvertSTDStringToString(std::string& stdString);
System::String^ ConvertCharToString(char* ch);
char* ConvertStringToChar(System::String^ string);
std::istream& ReadUser(std::istream&, Users&);
std::ostream& OutputUser(std::ostream&, Users&);

std::ostream& operator<<(std::ostream&, Users);

std::istream& operator>>(std::istream&, Users*);