#include <iostream>
#include <vector>

void PrintIntVector(std::vector<int>& data) {
	for (size_t i{}; i < data.size(); i++) {
		std::cout << data.at(i);

		// to add spacing between els until the last el is reached
		if (i < data.size() - 1)
			std::cout << " ";
	}

	std::cout << "\n";
}