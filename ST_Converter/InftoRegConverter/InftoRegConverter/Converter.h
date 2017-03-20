#pragma once
#include <string>
#include <fstream>
class Converter
{
private:
	std::ifstream inputFile;
	std::ofstream outputFile;
	bool convertLine(std::string&, std::string&);
	void openInputFile(std::string&);
	void openOutputFile();
public:
	Converter(std::string&);
	~Converter();

	static inline void endFreeze(int i)
	{
		system("pause");
		exit(i);
	}
};

