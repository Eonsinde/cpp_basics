#include <iostream>
#include <sstream>
#include <string>


int main_sstream()
{
	std::cout << "====== Working with String Streams ======\n\n";

	// initializing the stream with a string literal
	std::stringstream ss{ "Hello world" };

	std::cout << ss.str() << '\n';

	// writing to the stream
	std::stringstream ss2;

	int xX = 10;
	char cC = 'D';
	double dD = 90.02;

	ss2 << xX << ' ' << cC << ' ' << dD << '\n';

	std::cout << ss2.str() << '\n';

	// outputing stream data to variables
	int x;
	char c;
	double d;

	std::stringstream ss3{ "123 A 456.78" };

	ss3 >> x >> c >> d;

	std::cout << "The int is: " << x << ", char is: " << c << ", and double is: " << d;

	return 0;
}