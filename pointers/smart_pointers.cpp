#include <iostream>
#include <memory>
#include <string>

class MessageBuilder
{
	friend std::ostream& operator<<(std::ostream&, const MessageBuilder&);

private:
	std::string message;

public:
	MessageBuilder(): message() {}
	MessageBuilder(const std::string msg): message(msg) {}

	const char* GenerateMessage() const
	{
		return message.c_str();
	}
};

int main_smartptrs() {
	// unique pointers
	std::unique_ptr<std::string> strPtr(new std::string("Hello world"));

	std::cout << *strPtr << '\n';

	std::unique_ptr<MessageBuilder> testPtr = std::make_unique<MessageBuilder>();

	testPtr->GenerateMessage();

	// shared pointers
	std::shared_ptr<MessageBuilder> testSharedPtr{ new MessageBuilder("This is the way it is meant to be played")};
	std::shared_ptr<MessageBuilder> testSharedPtr2{ testSharedPtr };
	std::shared_ptr<MessageBuilder> testSharedPtr3{ testSharedPtr };

	std::cout << "\n\nThe pointers sharing the MessageBuilder instance:\n";
	std::cout << "Shared Ptr 1: " << testSharedPtr << '\n';
	std::cout << "Shared Ptr 2: " << testSharedPtr << '\n';
	std::cout << "Shared Ptr 3: " << testSharedPtr << '\n';

	std::cout << "\n\nThe Object being pointed to:\n";

	std::cout << "Shared Ptr 1: " << *testSharedPtr << '\n';
	std::cout << "Shared Ptr 2: " << *testSharedPtr2 << '\n';
	std::cout << "Shared Ptr 3: " << *testSharedPtr3 << '\n';


	return 0;
}

std::ostream& operator<<(std::ostream& os, const MessageBuilder& rhsObj)
{
	os << rhsObj.GenerateMessage();
	return os;
}
