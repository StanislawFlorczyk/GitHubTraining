#include <string>
#include "Globals.hpp"
#include "FancyPrint.hpp"
int main (int argc, char* argv[])
{
	FancyPrint::print("Version: " + std::to_string(VERSION_MAJOR) + "." + std::to_string(VERSION_MINOR));
	return 0;
}