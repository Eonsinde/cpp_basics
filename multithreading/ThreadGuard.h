#ifndef __THREADGUARD_H__
#define __THREADGUARD_H__

#include <thread>

class ThreadGuard {
private:
	std::thread& _mThreadInstance;

public:
	ThreadGuard(std::thread& t): _mThreadInstance(t) { }
	~ThreadGuard() {
		if (_mThreadInstance.joinable()) {
			// await thread completion on the calling thread
			_mThreadInstance.join();
		}
	}

	// prevent copy constr
	ThreadGuard(const ThreadGuard&) = delete;
	// prevent copy op
	ThreadGuard& operator=(const ThreadGuard&) = delete;
};

#endif