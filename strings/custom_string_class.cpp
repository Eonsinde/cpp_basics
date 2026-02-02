#include <iostream>
#include <string>

class MyString {
	friend std::ostream& operator<<(std::ostream&, const MyString&);
private:
	char* _data;
	size_t _length;
	size_t _capacity;

	// helper: allocate new buffer and copy content
	void _allocate_and_copy(const char* src, size_t len) {
		// +1 for the null terminator
		_data = new char[len + 1];
		std::memcpy(_data, src, len);
		// append null terminator
		_data[len] = '\0';
		_length = len;
		_capacity = len;
	}

	void _reserve_impl(size_t newCapacity) {

	}

public:
	MyString() : _data{ nullptr }, _length{}, _capacity{} {}

	MyString(const char* v) {
		_allocate_and_copy(v, std::strlen(v));
	}

	MyString(MyString& other) {
		_allocate_and_copy(other._data, std::strlen(other._data));
	}

	MyString(MyString&& other) noexcept
		: _data{ other._data }, _length{ other._length }, _capacity{ other._capacity } {
		other._data = nullptr;
		other._length = 0;
		other._capacity = 0;
	}

	~MyString() {
		delete[] _data;
		_data = nullptr;
		_length = 0;
		_capacity = 0;
	}

	// getters
	size_t length() const { return _length; }

	// functions
	MyString subString(size_t startPos, size_t length) const {
		// prevent startPos from exceeding string's length
		if (startPos >= _length) {
			// TODO: throw exceptions here
			std::cerr << "startPos cannot be greater or equal to the string's length\n";
		}

		// if startPos is on the last element, length cannot be greater than one
		if (startPos == _length - 1 && length > 1) {
			// TODO: throw exceptions here
			std::cerr << "startPos is on the last index, hence length shouldn't exceed one";
		}

		// going with the manual approach for practice sake
		MyString result;
		
		result._data = new char[length+1];

		std::memcpy(result._data, _data, length);

		result._length = length;
		result._capacity = length;

		result._data[length] = '\0';

		return result;
	}

	// operators
	MyString& operator=(const MyString& other) {
		if (this == &other)
			return *this;

		// clear current data
		delete[] _data;
		// allocate new data
		_allocate_and_copy(other._data, std::strlen(other._data));
		return *this;
	}

	MyString& operator=(MyString&& other) noexcept {
		if (this == &other)
			return *this;

		_data = other._data;
		_length = other._length;
		_capacity = other._capacity;

		other._data = nullptr;
		other._length = other._capacity = 0;

		return *this;
	}

	bool operator==(const MyString& rhs) const {
		return std::strcmp(_data, rhs._data) == 0;
	}

	MyString operator+(const MyString& rhs) const {
		// total length without null terminator
		size_t newSize = _length + rhs._length;

		// create new string instance
		MyString result;

		// allocate memory
		result._data = new char[newSize + 1];
		result._length = newSize;
		result._capacity = newSize;

		// copy left part(this)
		std::memcpy(result._data, _data, _length);
		// copy right side(rhs)
		std::memcpy(result._data + _length, rhs._data, rhs._length);

		// append null terminator: result._data[newSize]
		*(result._data + newSize) = '\0';

		return result;
	}
};

int main_custom_string() {
	std::cout << std::boolalpha;

	std::string test{ "Hello" };

	std::cout << "substr of Hello starting from index 0, and reading three chars: " << test.substr(0, 3) << '\n';

	const char word[6]{ "Hello" };
	const char* word2{ "Hello" };
	const char* word3{ "Hello" };

	MyString test1{ "Hello" };
	MyString test2 = "Hello";
	const MyString test3("Jackal");
	MyString test4{ " there" };

	MyString test5 = test1 + test4;

	std::cout << "Substr(0, 2) of " << test << ": " << test3.subString(0, 2) << '\n';
	std::cout << test5.subString(0, 7) << '\n';

	if (test1 == test2) {
		std::cout << "Test1 matches the value it's compared against\n";
	}
	else {
		std::cout << "Test1 doesn\'t match the value compared against\n";
	}

	std::cout << test3 << '\n';

	return 0;
}

std::ostream& operator<<(std::ostream& os, const MyString& rhs)
{
	os << rhs._data;
	return os;
}
