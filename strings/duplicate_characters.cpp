#include <iostream>
#include <string>
#include <unordered_set>

std::string removeDuplicateChars(const std::string&);
std::string removeDuplicatesCharsOptimized(const std::string&);

int main_dup_chars() {
	std::string userEntry;

	do {
		std::cout << "Enter a word: ";
		std::cin >> userEntry;

		if (userEntry.empty()) {
			std::cout << "\nYou must enter something valid\n";
			continue;
		}

		break;
	} while (true);

	std::string withoutDuplicates = removeDuplicateChars(userEntry);
	std::cout << "Leftover from `" << userEntry << "` after culling: " << (!withoutDuplicates.empty() ? withoutDuplicates : "none found") << '\n';

	std::string withoutDups = removeDuplicatesCharsOptimized(userEntry);
	std::cout << "Leftover from `" << userEntry << "` after culling: " << (!withoutDups.empty() ? withoutDups : "none found") << '\n';

	return 0;
}

std::string removeDuplicateChars(const std::string& sS)
{
	std::string result;
	std::unordered_set<char> seen;

	for (const char& c : sS) {
		// check c is not present in seen
		if (seen.find(c) == seen.end()) {
			// do this to track already encountered characters
			seen.insert(c);
			// write entry(c) to result
			result += c;
		}
	}

	return result;
}

std::string removeDuplicatesCharsOptimized(const std::string& sS)
{
	std::string result;
	result.reserve(sS.size());
	
	std::unordered_set<char> seen;

	for (const char& c : sS) {
		// second will be false when char is already present in the set
		if (seen.insert(c).second) {
			result += c;
		}
	}

	return result;
}
