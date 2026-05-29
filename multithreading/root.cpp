#include <iostream>
#include <thread>
#include <string>
#include "./ThreadGuard.h"
#include "../utils.h"

// examples
// WaitingForThread: demonstrates using .join to await a thread's completion in the caller thread
void WaitingForThread();
// ExceptionHandling(case 1): demonstrates how to safe guard a thread if an exception is throw
void ExceptionHandling();
// ExceptionHandling(case 2): demonstrates how to safe guard a thread if an exception is throw
void ExceptionHandling2();

// using member function for the execution funciton of a thread
class X
{
	static size_t instancesCount;
public:
	X() { ++instancesCount; }

	void DoLengthyWork() {
		std::cout << instancesCount << " instance(s) of X created\n";
		std::cout << this << " is Doing Some Lengthy Work\n";
	}
};

size_t X::instancesCount = 0;

void MemberFunctionUsage();


int main_thread()
{
	WaitingForThread();
	
	//ExceptionHandling();

	//ExceptionHandling2();

	MemberFunctionUsage();

	return 0;
}

void WaitingForThread()
{
	// thread is created here
	std::thread testThread([]() { std::cout << "WaitingForThread::testThread is executing\n"; });
	// call join to cause calling thread to wait for the completion of testThread
	testThread.join();
}

void ExceptionHandling()
{
	// this function assumes you need the testThread to complete its execution at some point

	// some local variable
	int number{ 12 };

	std::thread testThread([&]() { std::cout << "Doing something to local variable number(" << number << ")\n"; });
	ThreadGuard tguard(testThread);

	// this will cause the program to break. We'll assume testThread hasn't finished running
	// which will cause tguard to ensure the thread is completed before its termination
	throw CustomException("CustomException::Something went wrong");
}

void ExceptionHandling2()
{
	// this function amuses you need the testThread to complete its execution at some point

	std::thread testThread([]() { std::cout << "ExceptionHandling2::Test Thread is doing something\n"; });

	try {
		// do something random
		std::cout << "Processing data...\n\n";

		// say an exception gets thrown processing the data
		throw CustomException("CustomException::Something went wrong");
	}
	catch (std::exception& e) {
		// do this when handling the exception
		testThread.join();

		std::cout << e.what() << "\n";
	}

	// in case no exception is thrown, ensure test thread finishes execution
	testThread.join();
}

void MemberFunctionUsage()
{
	X xInstance;

	std::thread testThread(&X::DoLengthyWork, xInstance);
	testThread.join();
}
