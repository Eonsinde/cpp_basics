#include <iostream>
#include <vector>

size_t LinearSearch(const std::vector<int>& vec, int x);

int main_ls() {
	std::cout << "==== Linear Search Algorithm ====\n";

	int userQuery;
	std::vector<int> numbers { 12, 30, 50, 66, 42, 90, 11, 45 };

	std::cout << "Enter a number to search for: ";
	std::cin >> userQuery;

	size_t pos = LinearSearch(numbers, userQuery);

	if (pos != -1) {
		std::cout << '`' << userQuery << '`' << " is present at " << pos << " in the array\n";
	}
	else {
		std::cout << '`' << userQuery << '`' << " is not present in the array\n";
	}

	return 0;
}

size_t LinearSearch(const std::vector<int>& vec, int x) {
	for (int i{}; i < vec.size(); i++) {
		if (vec[i] == x) {
			return i;
		}
	}

	// not found
	return -1;
}