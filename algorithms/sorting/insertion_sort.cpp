#include <iostream>
#include <vector>
#include "../../utils.h"

void InsertionSort(std::vector<int>&);
void InsertionSortTest(std::vector<int>& data);

int main_insertsort() {
	std::cout << "==== Insertion Sort ====\n";

	std::vector<int> numbers{ 12, 11, 13, 5, 6 };
	std::vector<int> numbers2{ 25, 10, 1, 3, 8, 4 };

	std::cout << "\n\nUnsorted array: ";
	PrintIntVector(numbers);

	InsertionSortTest(numbers);

	std::cout << "\nSorted array: ";
	PrintIntVector(numbers);

	return 0;
}

void InsertionSort(std::vector<int>& data) {
	for (long long i = 1; i < data.size(); i++) {
		int key = data[i];
		// j references the index to the element before i
		long long j = i - 1;

		// iterate through the elements in the sorted part(left side)
		// and compare them against the key
		while (j >= 0 && data[j] > key) {
			// if the current element in the sorted potion is greater than key
			// move it forward by one index
			data[j + 1] = data[j];
			--j;
		}

		// move the key backward/leftward(sorted region) in data
		// this is where the insertion actually takes place as the key is inserted
		// into the correct position if need on the left side(sorted region)
		data[j + 1] = key;
	}
}

void InsertionSortTest(std::vector<int>& data) {
	for (long long i = 1; i < data.size(); i++) {
		int key = data[i];
		long long j = i - 1;

		while (j >= 0 && data[j] > key) {
			// move the element behind key forward
			data[j + 1] = data[j];
			j--;
		}
		
		data[j + 1] = key;
	}
}
