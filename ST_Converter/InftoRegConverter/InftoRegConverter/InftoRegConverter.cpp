// InftoRegConverter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <atlstr.h>

#include "Converter.h"
using namespace std;

bool chackName(string);

int main(int argc, const char* argv[])
{
	cout << endl;
	if (argc != 2)
	{
		cout << "Bledna liczba parametrow" << endl;
		Converter::endFreeze(1);
	}
	string fileName = argv[1];
	if (!chackName(fileName))
	{
		Converter::endFreeze(2);
	}
	new Converter(fileName);
}
bool chackName(string fileName)
{
	fileName = fileName.substr(fileName.find_last_of("{"), fileName.find(".txt") + 4);
	cout << endl << "File Name" << fileName << endl;
	bool b = false;
	if ((fileName.find_first_of("}") - fileName.find_last_of("{")) != 37)
	{
		cout << "Nieprawidłowa Długość GUID-u = 36?: " << endl;
		return false;
	}
	b = false;
	if((fileName.find_first_of(".") - fileName.find_first_of("}") ) != 5)
	{
		cout << "Nieprawidłowa Długość (nr)" << endl;
		return false;
	}
	if (fileName.length() != 46) 
	{
		cout << "Nieprawidłowa Długość Nazwy" << endl;
		return false;
	}
	if (fileName.find(".txt") == string::npos)
	{
		cout << "Nieprawidłowe Rozszerzenie" << endl;
		return false;
	}
	string tmp = fileName.substr(fileName.find_last_of("{") + 1, fileName.find_first_of("}") - 1);
	if (tmp.find_first_of("-") != 8)
	{
		cout << "Nieprawidłowy format: Data1" << endl;
		return false;
	}
	tmp = tmp.substr(tmp.find_first_of("-") + 1, tmp.length());
	for (int i = 0; i < 3; i++)
	{
		if (tmp.find_first_of("-") != 4)
		{
			cout << "Nieprawidłowy format: Data" << i + 2 << endl;
			return false;
		}
		tmp = tmp.substr(tmp.find_first_of("-") + 1, tmp.length());
	}
	if (tmp.length() != 12)
	{
		cout << "Nieprawidłowy format: Data5" << endl;
		return false;
	}
	return true;
}

