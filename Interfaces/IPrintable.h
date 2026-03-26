#ifndef __IPRINTABLE_H__
#define __IPRINTABLE_H__

#include <ostream>

class IPrintable {
	friend std::ostream& operator<<(std::ostream& os, const IPrintable& obj);

public:
	IPrintable() = default;
	virtual ~IPrintable() = default;

protected:
	virtual void Print(std::ostream& os) const = 0;
};

#endif