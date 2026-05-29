#include <iostream>
#include <vector>
#include "../../utils.h"

void SelectionSort(std::vector<int>&);
void SelectionSortTest(std::vector<int>& data);

int main_selectionsort() {
	std::cout << "==== Selection Sort ====\n";

	std::vector<int> numbers { 64, 25, 12, 22, 11 };

	std::cout << "\n\nBefore Sort: ";
	PrintIntVector(numbers);
	
	std::cout << "\nAfter Sort: ";
	SelectionSortTest(numbers);
	PrintIntVector(numbers);
	
	return 0;
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

void SelectionSortTest(std::vector<int>& data) {
	for (long long i{}; i < data.size()-1; i++) {
		// min index is the reference to the smallest element in the array
		long long minIndex = i;

		for (long long j{ i + 1 }; j < data.size(); j++) {
			if (data[j] < data[minIndex]) {
				// update min index
				minIndex = j;
			}
		}

		// swap the smallest element(using minIndex) with the current elemnt(data[i])
		int temp = data[i];
		data[i] = data[minIndex];
		data[minIndex] = temp;
	}
}