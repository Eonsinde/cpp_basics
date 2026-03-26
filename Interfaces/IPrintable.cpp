#include "IPrintable.h"

std::ostream& operator<<(std::ostream& os, const IPrintable& obj)
{
	obj.Print(os);
	return os;
}

