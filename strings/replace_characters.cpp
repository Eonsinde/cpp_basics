#include <iostream>
#include <string>

// every instance of oldChar in value will be replaced with the newChar
std::string replaceCharacters(const std::string&, char, char);

int main_replace_chars() {
	std::string userInput;
	char oldChar;
	char newChar;

	do {
		std::cout << "Enter anything: ";
		std::getline(std::cin, userInput);

		if (userInput.empty())
			continue;

		std::cout << "Enter the character you want to be replaced from the above entry: ";
		std::cin >> oldChar;

		std::cout << "Enter the new character you want to substitute: ";
		std::cin >> newChar;

		break;
	} while (true);

	std::cout << "User Entry: " << userInput << " -> " << oldChar << " -> " << newChar << '\n';

	std::cout << "The Modified String is: " << replaceCharacters(userInput, oldChar, newChar);

	return 0;
}

std::string replaceCharacters(const std::string& value, char target, char substitute)
{
	std::string results = value;

	for (size_t i = 0; i < value.size(); i++) {
		if (value[i] == target) {
			results[i] = substitute;
		}
	}

	return results;
}
