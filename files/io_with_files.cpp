#include <iostream>
#include <fstream>
#include <string>
#include <exception>

int main_fstream() {
	// reading from a file
	std::fstream lyricsFS{ "./assets/txts/lovely-lover.txt" };

	std::string line;

	while (std::getline(lyricsFS, line))
	{
		std::cout << line << '\n';
	}

	// creates new file(if needed), or overwrites existing file's data
	std::fstream dummyFile{ "./assets/txts/dummy.txt", std::ios::out };
	dummyFile << "1-This is the way it is meant to be played\n";
	dummyFile << "2-Nvidia does it just the right way\n";
	dummyFile << "3-AMD Radeon graphics but a mere fraction of Nvidia\n";

	// appending to a new file
	try {
		std::fstream dummyFile2{ "./assets/txts/dummy2.txt", std::ios::app };
		dummyFile2 << "\nWhen I say focused, I mean hyper, super, duper focused\n";
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}