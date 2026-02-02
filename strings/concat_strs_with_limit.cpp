#include <iostream>
#include <string>
#include <cctype>

std::string concatStringLimit(const std::string&, const std::string&, size_t);
std::string concatStringLimitOptimized(const std::string&, const std::string&, size_t);

int main_concat_str_limit() {
	std::string string1, string2;
	size_t limit;

	std::cout << "Enter string 1: ";
	std::getline(std::cin, string1);
	std::cout << "Enter string 2: ";
	std::getline(std::cin, string2);
	std::cout << "Enter Limit/Length: ";
	std::cin >> limit;

	std::cout << "Result based on entry: " << concatStringLimit(string1, string2, limit) << '\n';
	std::cout << "Result based on entry(Optimized): " << concatStringLimitOptimized(string1, string2, limit) << '\n';

	return 0;
}

std::string concatStringLimit(const std::string& s1, const std::string& s2, size_t len)
{
	return (s1 + s2).substr(0, len);
}

std::string concatStringLimitOptimized(const std::string& s1, const std::string& s2, size_t maxLen)
{
	std::string result;
	result.reserve(s1.size() + s2.size());

	result = s1;
	result.append(s2, 0, maxLen > s1.size() ? maxLen - s1.size() : 0);

	return result;
}

