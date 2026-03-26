#include <iostream>
#include <vector>

// Defined externally and used to log vector details to console
void PrintIntVector(std::vector<int>& data);

void SelectionSort(std::vector<int>&);

int main() {
	std::cout << "==== Selection Sort ====\n";

	std::vector<int> numbers { 64, 25, 12, 22, 11 };

	std::cout << "\n\nBefore Sort: ";
	PrintIntVector(numbers);
	
	std::cout << "\nAfter Sort: ";
	SelectionSort(numbers);
	PrintIntVector(numbers);
}

void SelectionSort(std::vector<int>& data) {
	size_t n = data.size();

	// we do n - 1 to ensure the loop doesn't run for the last el in the array
	for (size_t i{}; i < n - 1; i++) {
		// assume the current pos holds the min el in the dataset
		int minIndex = i;

		for (size_t j = i + 1; j < n; j++) {
			// check to see if the els in the unsorted portion are lesser than the assumed min value
			if (data[j] < data[minIndex]) {
				// update the index reference to the minimum element
				minIndex = j;
			}
		}

		// after the minimum el is confirmed
		// swap it's pos with the current el: data[i], for the sorting operation
		int temp = data[i];
		data[i] = data[minIndex];
		data[minIndex] = temp;
	}
}