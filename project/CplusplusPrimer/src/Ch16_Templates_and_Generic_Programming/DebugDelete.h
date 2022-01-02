#pragma once

#include <iostream>

class DebugDelete {
public:
	DebugDelete() {}
	
	template<typename T> 
	void operator()(T* p) const
	{
		os << "deleting unique_ptr" << std::endl;
		delete p;
	}

private:
	std::ostream& os{ std::cerr };
};

void test()
{
	double* p = new double;
	DebugDelete d;
	d(p);
	int* ip = new int;
	DebugDelete()(ip);
}
