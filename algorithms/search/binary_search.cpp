#include <iostream>
#include <vector>

size_t BinarySearchIterative(std::vector<int>&, int);
size_t BinarySearchRecursive(const std::vector<int>& data, const int& key, int, int);

int main_binarysearch() {
	std::cout << "====== Binary Search Algorithm ======\n";
	std::cout << "======   Iterative Solution    ======\n";

	std::vector<int> numbers{ 2, 10, 13, 17, 19, 50, 57, 64, 89, 91 };

	std::cout << "57 is present at index: " << BinarySearchIterative(numbers, 89) << '\n';
	std::cout << "50 is present at index: " << BinarySearchRecursive(numbers, 50, 0, numbers.size()-1) << '\n';

	return 0;
}

size_t BinarySearchIterative(std::vector<int>& data, int key) {
	int low = 0;
	int high = data.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (key == data[mid]) {
			// return the index at which the element was found
			return mid;
		}
		else if (key < data[mid]) {
			// The left side should become the next search space. Update the higher bound
			// and since mid has already being compared, do mid - 1 to go a step lower
			high = mid - 1;
		}
		else {
			// This automatically handles when key > data[mid], The right side should 
			// become the next search space by Updating the lower bound since mid has
			// already being compared, do mid + 1 to go a step higher
			low = mid + 1;
		}
	}

	// On failure to find key, return -1
	return -1;
}

size_t BinarySearchRecursive(const std::vector<int>& data, const int& key, int low, int high) {
	// base class
	if (low > high)
		return -1;

	int mid = low + (high - low) / 2;

	if (key == data[mid]) {
		// if key is found in the middle el of the active search space, return its index
		return mid;
	}
	else if (key < data[mid]) {
		// key is lesser than middle el, shift search space to the left
		high = mid - 1;
	}
	else {
		// key is greater than middle el, shift search space to the right
		low = mid + 1;
	}

	BinarySearchRecursive(data, key, low, high);
}
