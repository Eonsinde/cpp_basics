#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>
#include <exception>
#include <vector>
#include <string>

class CustomException : public std::exception
{
private:
	std::string message;

public:
	CustomException(std::string text): message{text} {}

	const char* what() const noexcept override
	{
		return message.c_str();
	}
};

inline void PrintIntVector(std::vector<int>& data) {
	for (size_t i{}; i < data.size(); i++) {
		std::cout << data.at(i);

		// to add spacing between els until the last el is reached
		if (i < data.size() - 1)
			std::cout << " ";
	}

	std::cout << "\n";
}

#endif