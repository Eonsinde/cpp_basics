#include <iostream>
#include <string>
#include <set>
#include <cctype>

enum class CipherAction {
	ENCRYPT,
	DECRYPT
};

std::string encryptDecryptCipher(std::string, CipherAction = CipherAction::ENCRYPT, size_t = 3);
std::string encryptDecryptCipherOptimized(std::string, CipherAction = CipherAction::ENCRYPT, size_t=3);

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

	const std::string encryptedEntry = encryptDecryptCipherOptimized(userEntry);
	std::cout << "Your message has being encrypted: " << encryptedEntry << '\n';
	std::cout << "Your original message: " << encryptDecryptCipherOptimized(encryptedEntry, CipherAction::DECRYPT) << '\n';

	return 0;
}

std::string encryptDecryptCipher(std::string sS, CipherAction action, size_t shift)
{
	std::string result;
	result.reserve(sS.size());
	static std::set<char> alphabet{
		'a','b','c','d','e','f','g','h','i','j','k','l','m',
		'n','o','p','q','r','s','t','u','v','w','x','y','z'
	};
	std::set<char>::iterator foundPos;
	int overflowCount = 0;

	for (const char& c : sS) {
		if ((foundPos = alphabet.find(std::tolower(static_cast<unsigned char>(c)))) != alphabet.end()) {
			if (action == CipherAction::ENCRYPT) {
				// prevent overflow by checking the result after the shift operation
				overflowCount = (std::tolower(*foundPos) + shift) - 'z';

				if (overflowCount >= 1) {
					// handle the shift operation overflowing by having it continue from
					// the start point of the alphabet set. We do overflowCount - 1 for proper indexing
					result += static_cast<unsigned char>(*alphabet.begin() + (overflowCount - 1));
				}
				else {
					result += static_cast<unsigned char>(std::tolower(*foundPos) + shift);
				}
			}
			else {
				// decrypt operation
				// prevent overflow by checking the result after the shift operation
				overflowCount = (std::tolower(*foundPos) - shift) - 'a';

				if (overflowCount < 0) {
					// we do overflowCount + 1 to ensure we land in the right pos 
					// when reading from z. For example: when c is 'b'; 122(z) - (-2(overflowCount) + 1)
					result += static_cast<unsigned char>('z' + (overflowCount + 1));
				}
				else {
					result += static_cast<unsigned char>(std::tolower(*foundPos) - shift);
				}
			}  
		}
		else {
			result += c;
		}
	}

	return result;
}

std::string encryptDecryptCipherOptimized(std::string sS, CipherAction action, size_t shift)
{
	std::string result;
	result.reserve(sS.size());

	// Normalize shift (in case of a large value)
	shift %= 26;

	// Negative shift for decrypt
	int direction = (action == CipherAction::ENCRYPT) ? 1 : -1;
	int delta = static_cast<int>(shift) * direction;

	for (char c : sS) {
		unsigned char uc = static_cast<unsigned char>(c);
		char lower = std::tolower(uc);

		if (lower >= 'a' && lower <= 'z') {
			// lower - 'a': this tells us: 't' is the 19th letter in the alphabet (0-based: a=0, b=1, …, t=19)
			// say c is 't'(116): 116 - 'a' = 19. t is in the 19th position(NB: 0 index basis)
			// + delta: helps perform the shift operation, based on the action type
			// i.e 19 + 3 = 22(w). w is at 22nd position(also based on 0 index)
			// +26: this is the safety step — it makes sure even big negative shifts stay positive
			char shifted = 'a' + (lower - 'a' + delta + 26) % 26;

			// if c is uppercase, make sure to capitalize its shift
			result += std::isupper(uc) ? std::isupper(shifted) : shifted;
		}
		else {
			// non-letter unchanged
			result += c;
		}
	}

	return result;
}