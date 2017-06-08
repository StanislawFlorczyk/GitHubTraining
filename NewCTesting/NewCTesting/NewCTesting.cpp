// NewCTesting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GenericContainer.h"
#include <iostream>

int main()
{
	GenericContainer<int> tenInts = GenericContainer<int>();
	tenInts.setElement(10,2);
	std::cout << tenInts.getElement(2);
	std::cout << std::endl;
    return 0;
}

