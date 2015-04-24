#include "Array.h"
#include <iostream>

int main()
{
	std::string str = "string";
	int ints[5] = { 1, 2, 3, 4, 5 };
	
	Array<int> intArray(ints, sizeof(ints)/sizeof(ints[0]));
	Array<char> charArray(&str[0], str.length());
	Array<char> char1 = charArray;

	intArray.Print();
	std::cout << std::endl << std::endl;
	charArray.Print();
	char1.Print();
}