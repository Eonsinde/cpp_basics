#include <iostream>
#include <string>
#include <set>
#include <cctype>

enum class CipherAction {
	ENCRYPT,
	DECRYPT
};

std::string encryptDecryptCipher(std::string, CipherAction = CipherAction::ENCRYPT, size_t=3);
std::string encryptDecryptCipherOptimized(std::string, size_t=3);

int main() {
	std::string userEntry;

	do {
		std::cout << "Enter a message: ";
		std::getline(std::cin, userEntry);

		if (userEntry.empty()) {
			std::cout << "Enter a valid entry\n";
			continue;
		}

		break;
	} while (true);

	const std::string encryptedEntry = encryptDecryptCipher(userEntry);
	std::cout << "Your message has being encrypted: " << encryptedEntry << '\n';
	std::cout << "Your original message: " << encryptDecryptCipher(encryptedEntry, CipherAction::DECRYPT) << '\n';

	return 0;
}

std::string encryptDecryptCipher(std::string sS, CipherAction action, size_t shift)
{
	std::string result;
	std::set<char> alphabet{
		'a','b','c','d','e','f','g','h','i','j','k','l','m',
		'n','o','p','q','r','s','t','u','v','w','x','y','z'
	};
	std::set<char>::iterator foundPos;

	for (const char& c : sS) {
		if ((foundPos = alphabet.find(std::tolower(static_cast<unsigned char>(c)))) != alphabet.end()) {
			if (action == CipherAction::ENCRYPT) {
				// prevent overflow by checking the result after the shift operation
				result += static_cast<unsigned char>((*foundPos) + shift);
			}
			else {
				// prevent overflow by checking the result after the shift operation
				result += static_cast<unsigned char>((*foundPos) - shift);
			}
		}
		else {
			result += c;
		}
	}

	return result;
}