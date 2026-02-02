#include <iostream>
#include <string>

size_t countWords(const std::string&);
size_t countWordsOptimized(const std::string&);

int main_count_words() {
	std::string userEntry;

	do {
		std::cout << "Enter a sentence: ";
		std::getline(std::cin, userEntry);

		if (userEntry.empty()) {
			std::cerr << "You must enter something\n";
			continue;
		}

		break;
	} while (true);

	std::string test{ "  this is the   " };

	std::cout << test.find("i", 5) << '\n';

	std::cout << "The number of words in your entry(basic): " << countWords(userEntry) << '\n';
	std::cout << "The number of words in your entry(optimized): " << countWordsOptimized(userEntry) << '\n';

	return 0;
}

size_t countWords(const std::string& pEntry) {
	// letterCount to track the length of each word in the sentence through the iteration
	size_t numOfWords{}, letterCount {};

	for (size_t i = 0; i < pEntry.size(); i++) {
		if (pEntry[i] != ' ') {
			// this only ensures the last word is accounted for since the 
			// main else statement won't be reached. No need for continue 
			// after numOfWords++ since the loop ends there anyway
			if (i == pEntry.size() - 1 && !pEntry.ends_with(' ')) {
				numOfWords++;
			}

			letterCount++;
			continue;
		}
		else {
			if (letterCount > 0) {
				numOfWords++;
				letterCount = 0;
			}
		}
	}

	return numOfWords;
}

size_t countWordsOptimized(const std::string& sS) {
	size_t numOfWords{};
	bool inWord = false;

	for (char c : sS) {
		if (c == ' ') {
			inWord = false;
		}
		else {
			if (!inWord) {
				inWord = true;
				numOfWords++;
			}
		}
	}

	return numOfWords;
}