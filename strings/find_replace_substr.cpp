#include <iostream>
#include <string>

std::string findAndReplaceSubStr(const std::string&, const std::string&, const std::string&);
std::string findAndReplaceSubStrAll(const std::string&, const std::string&, const std::string&);

int main_find_replace_substr() {
	std::string userEntry, subStr, replacementStr;

	do {
		std::cout << "Enter something: ";
		std::getline(std::cin, userEntry);

		if (userEntry.empty())
			continue;

		break;
	} while (true);

	// ensure substring's length is below that of the user's entry
	do {
		std::cout << "Enter substring: ";
		std::getline(std::cin, subStr);

		if (subStr.length() >= userEntry.length() || subStr.empty()) {
			std::cerr << "Substring must be lesser than the characters from the first entry\n\n";
			continue;
		}

		break;
	} while (true);

	// ensure the replacement string is the same length as the substring
	do {
		std::cout << "Enter replacement string: ";
		std::getline(std::cin, replacementStr);

		if (replacementStr.length() != subStr.length() || replacementStr.empty()) {
			std::cerr << "Replacement string must match the length of characters in substring\n\n";
			continue;
		}

		break;
	} while (true);

	std::cout << "Replaced one substring occurrence: " << findAndReplaceSubStr(userEntry, subStr, replacementStr) << '\n';
	std::cout << "Replaced all substring occurrence: " << findAndReplaceSubStrAll(userEntry, subStr, replacementStr) << '\n';

	return 0;
}

// this approach only replaces one occurrence in the string
std::string findAndReplaceSubStr(const std::string& pData, const std::string& pSubStr, const std::string& pRepStr) {
	std::string result = pData;
	// used to index the replacement string through each iteration
	size_t index = 0;
	size_t foundIndex = pData.find(pSubStr);

	if (foundIndex != std::string::npos) {
		// iterate based on the length of the substring, with
		// the starting index as the substring's position
		for (size_t i = foundIndex; i < (foundIndex + pSubStr.length()); i++) {
			result[i] = pRepStr[index];
			index++;
		}
	}

	return result;
}

std::string findAndReplaceSubStrAll(const std::string& pData, const std::string& pSubStr, const std::string& pRepStr) {
	std::string result = pData;
	// used to move the starting point for the find func
	size_t pos = 0;
	// used to index the repStr
	size_t index = 0;

	while ((pos = result.find(pSubStr, pos)) != std::string::npos) {
		// replace substr occurrence with repstr
		for (size_t i = pos; i < (pos + pSubStr.length()); i++) {
			result[i] = pRepStr[index++];
		}

		// update pos to prevent infinite loop
		pos += pSubStr.length();
		// reset index
		index = 0;
	}

	return result;
}


