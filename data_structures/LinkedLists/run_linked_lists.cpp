#include <iostream>

#include "DoublyLinkedList.h"


int main()
{
	std::cout << "====== Doubly Linked List ======\n\n";

	Learning::DoublyLinkedList<int> testList;

	testList.Append(10);
	testList.Append(15);
	testList.Append(20);
	testList.Append(25);
	testList.Append(30);

	int foundIndex = testList.Find(10);

	if (foundIndex >= 0) {
		std::cout << "Item found at index: " << foundIndex << '\n';
	}
	else {
		std::cout << "Item not found in list, hence: " << foundIndex << '\n';
	}

	return 0;
}