#include <iostream>
#include <string>
#include <memory>

class Animal {
public:
	Animal() = default;
	virtual ~Animal() = default;

	virtual void Speak() { std::cout << "Animal is speaking\n"; }
	virtual void Move() { std::cout << "Animal is moving\n"; }
};

class Dog : public Animal {
public:
	Dog() = default;
	virtual ~Dog() = default;

	virtual void Speak() override { std::cout << "Whoof Whoof!\n"; }

	void WagTail() const { std::cout << "Wagging Tail😄\n"; }
};

int main_polymorphism() {
	// with raw pointers
	Animal* animal1 = new Dog();
	Animal* animal2 = new Dog();

	// with unique pointers
	std::unique_ptr<Animal> animal3 = std::make_unique<Dog>();
	std::unique_ptr<Animal> animal4 = std::make_unique<Dog>();

	animal1->Speak();
	animal1->Move();

	Dog* actualDog2 = dynamic_cast<Dog*>(animal2);

	actualDog2->WagTail();

	Dog dog1 = Dog();

	dog1.Move();

	return 0;
}