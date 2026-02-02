#include <iostream>
#include <string>
#include <sstream>

std::string getLongestWord(const std::string&);

int main_longest_word() {
	std::string userEntry;

	std::cout << "Enter a sentence: ";
	std::getline(std::cin, userEntry);

	std::cout << "\n\nLongest word in the sentence is: " << getLongestWord(userEntry) << '\n';

	return 0;
}

std::string getLongestWord(const std::string& pSentence)
{
	std::istringstream iss(pSentence);
	// to hold the longest word found through the iteration
	std::string longest;
	// temporarily holds each word per iteration through the sentence
	std::string temp;

	while (iss >> temp) {
		if (temp.size() > longest.size()) {
			longest = temp;
		}
	}

	return longest;
}