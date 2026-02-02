#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

bool areAnagrams(const std::string&, const std::string&);
bool areAnagramsOptimizedWithMaps(const std::string&, const std::string&);
bool areAnagramsOptimizedWithoutMaps(std::string, std::string);
bool areAnagramsIgnoreCase(std::string s1, std::string s2);

int main_anagrams() {
	std::string entry1, entry2;

	std::cout << "=============== Anagram Checker Task ===============\n";
	std::cout << "Enter the first word: ";
	std::cin >> entry1;
	std::cout << "Enter the second word: ";
	std::cin >> entry2;

	if (areAnagramsIgnoreCase(entry1, entry2))
		std::cout << "Your entries qualified as Anagrams\n";
	else
		std::cout << "Your entries do not qualify as Anagrams\n";

	return 0;
}

bool areAnagrams(const std::string& s1, const std::string& s2)
{
	std::unordered_map<char, size_t> cacheForS1;
	std::unordered_map<char, size_t> cacheForS2;
	size_t offset = 0;

	// cannot be an anagram if the lengths vary
	if (s1.size() != s2.size())
		return false;

	for (const char& c : s1) {
		while ((offset = s2.find(c, offset)) != std::string::npos) {
			// this prevents the tracking process for s2 
			// from repeating when c is a reoccuring char
			if (cacheForS1[c] >= 1) {
				// increment offset to signify the loop at least ran
				offset = 1;
				break;
			}

			// record the char's presence with occurrence count in s2
			cacheForS2[c] += 1;
			// move offset to prevent endless looping
			offset += 1;
		}

		// check to see if offset is zero here implying the above while loop
		// couldn't run because the current char isn't present in s2
		if (offset == 0) {
			return false;
		}

		// record the char's presence with occurrence count in s1
		cacheForS1[c] += 1;

		// reset offset
		offset = 0;
	}

	return std::all_of(cacheForS1.begin(), cacheForS1.end(), [&](const auto& item) {
		return cacheForS2[item.first] == item.second;
	});
}
bool areAnagramsOptimizedWithMaps(const std::string& s1, const std::string& s2)
{
	if (s1.size() != s2.size())
		return false;

	std::unordered_map<char, size_t> count1;
	std::unordered_map<char, size_t> count2;

	for (const char& c : s1) {
		count1[c]++;
	}

	for (const char& c : s2) {
		count2[c]++;
	}

	// maps can be compared directly even if unordered
	return count1 == count2;
}

bool areAnagramsOptimizedWithoutMaps(std::string s1, std::string s2)
{
	if (s1.size() != s2.size())
		return false;

	// sorting here will arrange the characters using the current character representation format
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());

	return s1 == s2;
}

bool areAnagramsIgnoreCase(std::string s1, std::string s2)
{
	if (s1.size() != s2.size()) 
		return false;

	int (*toLower)(char) = [](char c) -> int { return std::tolower(static_cast<unsigned char>(c)); };

	// convert s1 characters to lower case
	std::transform(s1.begin(), s1.end(), s1.begin(), toLower);
	// convert s2 characters to lower case
	std::transform(s2.begin(), s2.end(), s2.begin(), toLower);

	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());

	return s1 == s2;
}

