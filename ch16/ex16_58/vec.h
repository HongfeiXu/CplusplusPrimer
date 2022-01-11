#pragma once

#include <memory>
#include <initializer_list>
#include <algorithm>
#include <string>
#include <iostream>

template<typename> class Vec;
template<typename T> std::ostream& operator<<(std::ostream&, const Vec<T>&);


template<typename T>
class Vec {
	friend std::ostream& operator<< <T>(std::ostream&, const Vec<T>&);
public:
	Vec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) { }
	Vec(std::initializer_list<T> il);
	Vec(const Vec& s);
	Vec(Vec&& s) noexcept;
	~Vec();
	Vec& operator=(const Vec& rhs);
	Vec& operator=(Vec&& rhs) noexcept;

	void push_back(const T& s);
	void push_back(T&& s) noexcept;

	template<typename... Args>
	void emplace_back(Args...);

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T* begin() const { return elements; }
	T* end() const { return first_free; }

	void reserve(size_t new_cap);
	void resize(size_t new_size, T& s);
	void resize(size_t new_size, T s);

private:
	void check_n_alloc();
	std::pair<T*, T*> alloc_n_copy(const T * b, const T * e);
	void free();
	void reallocate();
	void alloc_n_move(size_t new_cap);

private:
	std::allocator<T> alloc;
	T* elements;	// 分配的内存中的首个元素
	T* first_free;	// 指向最后一个实际元素之后的 位置
	T* cap;			// 指向分配的内存末尾之后的位置
};

template<typename T>
Vec<T>::Vec(std::initializer_list<T> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename T>
Vec<T>::Vec(const Vec& s)
{
	auto newdata = alloc_n_copy(s.elements, s.first_free);
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename T>
Vec<T>::Vec(Vec&& s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

template<typename T>
Vec<T>::~Vec()
{
	free();
}

template<typename T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	auto data = alloc_n_copy(rhs.elements, rhs.first_free);
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template<typename T>
Vec<T>& Vec<T>::operator=(Vec&& rhs) noexcept
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

template<typename T>
void Vec<T>::push_back(const T& s)
{
	check_n_alloc();
	alloc.construct(first_free++, s);
}

template<typename T>
void Vec<T>::push_back(T&& s) noexcept
{
	check_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

template<typename T>
template<typename... Args>
void Vec<T>::emplace_back(Args... args)
{
	check_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

template<typename T>
void Vec<T>::reserve(size_t new_cap)
{
	if (capacity() < new_cap)
	{
		alloc_n_move(new_cap);
	}
}

template<typename T>
void Vec<T>::resize(size_t new_size, T& s)
{
	if (new_size > size())
	{
		if (new_size > capacity())
		{
			reserve(2 * new_size);
			for (int i = size(); i != new_size; ++i)
			{
				alloc.construct(first_free++, s);
			}
		}
		else if (new_size < capacity())
		{
			while (first_free != elements + new_size)
			{
				alloc.destroy(--first_free);
			}
		}
	}
}

template<typename T>
void Vec<T>::resize(size_t new_size, T s)
{
	if (new_size > size())
	{
		if (new_size > capacity())
		{
			reserve(2 * new_size);
			for (int i = size(); i != new_size; ++i)
			{
				alloc.construct(first_free++, s);
			}
		}
		else if (new_size < capacity())
		{
			while (first_free != elements + new_size)
			{
				alloc.destroy(--first_free);
			}
		}
	}
}

template<typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e)
{
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

template<typename T>
void Vec<T>::free()
{
	if (elements)
	{
		std::for_each(elements, first_free, [this](const T& rhs) { alloc.destroy(&rhs); });
		alloc.deallocate(elements, cap - elements);
	}
}

template<typename T>
void Vec<T>::check_n_alloc()
{
	if (size() == capacity())
		reallocate();
}

template<typename T>
void Vec<T>::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}

template<typename T>
void Vec<T>::alloc_n_move(size_t new_cap)
{
	auto newdata = alloc.allocate(new_cap);

	// 移动元素
	auto last = std::uninitialized_copy(
		std::make_move_iterator(elements),
		std::make_move_iterator(first_free),
		newdata
	);
	free();
	elements = newdata;
	first_free = last;
	cap = elements + new_cap;
}

template<typename T>
std::ostream& operator<< (std::ostream& os, const Vec<T>& vec)
{
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		os << *it << " ";
	}
	return os;
}

void vec_test()
{
	Vec<std::string> vec;
	vec.push_back("hello");
	vec.push_back("world");
	vec.emplace_back(10, 'a');
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	Vec<int> veci;
	veci.resize(10, 1);

	std::cout << veci << std::endl;
}

/*

hello
world
aaaaaaaaaa
1 1 1 1 1 1 1 1 1 1

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 18548)已退出，代码为 0。
按任意键关闭此窗口. . .

*/