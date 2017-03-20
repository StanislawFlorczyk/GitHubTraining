#include "Converter.h"
#include <iostream>
using namespace std;


Converter::Converter(string& fileName)
{
	openInputFile(fileName);
	openOutputFile();

	string line;
	outputFile << "Windows Registry Editor Version 5.00" << "\n\n";
	cout << "Creating CFD registry keys:" << endl;
	while (getline(inputFile, line))
	{
		cout << " Entry:     " << line << endl;
		if (!convertLine(fileName, line))
		{
			cout << endl << endl << "Blad w pliku" << endl;
			break;
		}
		cout << " Generated: " << line << endl;
		outputFile << line;
	}
	outputFile.close();
	endFreeze(3);
}

Converter::~Converter()
{
}

bool Converter::convertLine(string& hardwareKey, string& line)
{
	if (line.length() < 3)
	{
		line = "";
		return true;
	}
	if (line.find(";") != string::npos)
	{
		line = "";
		return true;
	}
	string hkr = "HKR,";
	string driverPath = "[HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\";
	cout << endl;
	driverPath.append(hardwareKey.substr(hardwareKey.find_last_of("\\") + 1, hardwareKey.find("}") - hardwareKey.find_last_of("\\")));
	driverPath.append("\\");
	driverPath.append(hardwareKey.substr(hardwareKey.find("}") + 1, 4));
	driverPath.append("\\");
	line = line.replace(line.find("HKR,"), hkr.length(), driverPath);
	
	string keyName, keyValue;
	size_t keyNameStart, keyNameEnd;
	if ((keyNameStart = line.find_first_of(",")) == string::npos)
	{
		return false;
	}
	keyNameStart++;
	if ((keyNameEnd = line.find_first_of(",", keyNameStart)) == string::npos)
	{
		return false;
	}
	keyName = line.substr(keyNameStart, keyNameEnd - keyNameStart);

	keyNameStart = keyNameEnd;
	if ((keyNameEnd = line.find_first_of(",", keyNameStart + 1)) == string::npos)
	{
		return false;
	}
	size_t eraseStart = keyNameStart + 1;
	size_t eraseLength = keyNameEnd - keyNameStart;
	keyValue = line[keyNameEnd + 1];
	line = line.erase(keyNameStart + 1, keyNameEnd - keyNameStart);
	line = line.append("\n");
	line = line.replace(line.find_first_of(","), 1, "]\n\"");
	int value;
	try 
	{
		value = stoi(keyValue);
	}
	catch (...)
	{
		cout << endl << "Blad Pozycji: " << endl;
		return false;
	}
	if (value >= 0 && value < 10)
	{
		line = line.replace(line.find_first_of(","), 1, "\"=dword:0000000");
	}
	else if (value >= 10 && value < 100)
	{
		line = line.replace(line.find_first_of(","), 1, "\"=dword:000000");
	}
	else
	{
		cout << endl << "Blad Pozycji" << endl;
		return false;
	}
	return true;
}
void Converter::openInputFile(string& fileName)
{
	cout << fileName << endl;
	inputFile.open(fileName, std::ifstream::in);
	if (!inputFile.is_open())
	{
		cout << "Nie mozna otworzyc pliku wejsciowego" << endl;
		endFreeze(3);
	}
}
void Converter::openOutputFile()
{
	outputFile.open("CFD_ReferenceInject.reg", std::ifstream::trunc);
	if (!outputFile.is_open())
	{
		cout << "Nie mozna otworzyc pliku wyjsciowego" << endl;
		endFreeze(3);
	}
}
