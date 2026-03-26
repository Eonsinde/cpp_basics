#include <iostream>
#include "Int32Array.h"

int main_runarr() {
	std::cout << "==== Working with arrays in C++ ====\n";

	int ages[] { 23, 45, 12, 67, 34 };

	std::cout << "\n\nThe second age is: " << *(ages + 1) << "\n";
	std::cout << "The size of the arr is: " << sizeof(ages) << " bytes\n";

	double numbers[] = { 3.14, 2.718, 1.618 };

	std::cout << "\n\nThe last element is: " << *(numbers + 2) << "\n";
	std::cout << "The size of the arr is: " << sizeof(numbers) << " bytes\n";

	Int32Array<5> arr1{ 10, 20, 30, 40, 50 };
	
	std::cout << arr1 << "\n";

	arr1.Append(60);

	std::cout << arr1 << "\n";

	arr1.Append(70);
	arr1.Append(80);

	std::cout << arr1 << "\n";

	Int32Array<8> arr2(12);

	std::cout << arr2 << "\n";

	return 0;
}