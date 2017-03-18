template <typename T>
class Array2D
{
private:
	T* data;
	std::size_t d1, d2;
public:
	Array2D(std::size_t d1_, std::size_t d2_) : data(new T[d1_ * d2_]), d1(d1_), d2(d2_) { }
	Array2D(const Array2D& src) : data(new T[src.d1 * src.d2]), d1(src.d1), d2(src.d2)
	{
		std::copy(src.data, src.data + d1 * d2, data);
	}
	~Array2D() { delete[] data; }
	Array2D& operator =(const Array2D& src) = delete;
	T* operator [](std::size_t index) noexcept { return data + d2 * index; }
};

/*

Example:

#include "Array2D.h"
#include <iostream>

int main()
{
	int x, y;
	std::cin >> x >> y;
	Array2D<int> arr(x, y);
	arr[1][2] = 3;
	std::cout << arr[1][2] << std::endl;

	return 0;
}


*/