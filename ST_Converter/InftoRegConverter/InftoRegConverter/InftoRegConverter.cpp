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
		cout << "Nieprawid³owa D³ugoœæ GUID-u = 36?: " << endl;
		return false;
	}
	b = false;
	if((fileName.find_first_of(".") - fileName.find_first_of("}") ) != 5)
	{
		cout << "Nieprawid³owa D³ugoœæ (nr)" << endl;
		return false;
	}
	if (fileName.length() != 46) 
	{
		cout << "Nieprawid³owa D³ugoœæ Nazwy" << endl;
		return false;
	}
	if (fileName.find(".txt") == string::npos)
	{
		cout << "Nieprawid³owe Rozszerzenie" << endl;
		return false;
	}
	string tmp = fileName.substr(fileName.find_last_of("{") + 1, fileName.find_first_of("}") - 1);
	if (tmp.find_first_of("-") != 8)
	{
		cout << "Nieprawid³owy format: Data1" << endl;
		return false;
	}
	tmp = tmp.substr(tmp.find_first_of("-") + 1, tmp.length());
	for (int i = 0; i < 3; i++)
	{
		if (tmp.find_first_of("-") != 4)
		{
			cout << "Nieprawid³owy format: Data" << i + 2 << endl;
			return false;
		}
		tmp = tmp.substr(tmp.find_first_of("-") + 1, tmp.length());
	}
	if (tmp.length() != 12)
	{
		cout << "Nieprawid³owy format: Data5" << endl;
		return false;
	}
	return true;
}

