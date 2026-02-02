#include <iostream>
#include <string>
#include <cctype>

std::string capitalize(const std::string&);
std::string capitalizeOptimized(const std::string&);

int main_capitalize() {
	std::string userEntry;

	do {
		std::cout << "Enter a sentence you want capitalized: ";
		std::getline(std::cin, userEntry);

		if (userEntry.empty()) {
			std::cout << "You must enter a/some word(s)\n";
			continue;
		}

		break;
	} while (true);

	std::cout << "The capitalized output is: " << capitalizeOptimized(userEntry) << '\n';

	return 0;
}

std::string capitalize(const std::string& sS) {
	std::string results = sS;
	bool inWord = false;

	for (size_t i = 0; i < results.size(); i++) {
		if (results[i] == ' ') {
			inWord = false;
		}
		else {
			if (!inWord) {
				// ensure the letter beginning a word is actually an alphabet
				if (std::isalpha(static_cast<unsigned char>(results[i]))) {
					results[i] = std::toupper(static_cast<unsigned char>(results[i]));
				}

				inWord = true;
			}
		}
	}

	return results;
}

// a more optimized approach to capitalizing a string
std::string capitalizeOptimized(const std::string& sS) {
	std::string results = sS;
	bool newWord = false;

	for (char& c : results) {
		if (c == ' ') {
			newWord = false;
		}
		else {
			if (!newWord) {
				if (std::isalpha(static_cast<unsigned char>(c))) {
					c = std::toupper(static_cast<unsigned char>(c));
				}

				newWord = true;
			}
		}
	}

	return results;
}