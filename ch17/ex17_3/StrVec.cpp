#include "StrVec.h"
#include <algorithm>
#include <iostream>

StrVec::StrVec(std::initializer_list<std::string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &s)
{
    // 调用 alloc_n_copy 分配空间以容纳与 s 中一样多的元素
    auto newdata = alloc_n_copy(s.elements, s.first_free);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept		// 移动构造函数
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	//std::cout << "StrVec::MoveConstructor" << std::endl;
	// 令 s 进入这样的状态——对其运行析构函数是安全的
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	// 在释放已有元素之前调用 alloc_n_copy，这样可以正确处理自赋值问题
	auto data = alloc_n_copy(rhs.elements, rhs.first_free);
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
	//std::cout << "StrVec::MoveAssignmentOperator" << std::endl;
	// 直接检测自我赋值
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;

		// 将 rhs 至于可析构状态
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

void StrVec::push_back(const std::string& s)
{
	//std::cout << "push_back(const string&)" << std::endl;
    chk_n_alloc();      // 确保有空间容纳新元素
    alloc.construct(first_free++, s);   // 在 first_free 指向的元素中构造 s 的副本
}

void StrVec::push_back(std::string&& s)
{
	//std::cout << "push_back(string&&)" << std::endl;
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

void StrVec::reserve(size_t new_cap)
{
    // 只有当需要的内存空间超过当前容量时， reserve 调用才会改变 StrVec 的容量
    if (capacity() < new_cap)
        alloc_n_move(new_cap);
}

void StrVec::resize(size_t new_size)
{
    resize(new_size, std::string());
}

void StrVec::resize(size_t new_size, const std::string& s)
{
    if (new_size > size())
    {
        if (new_size > capacity())
            reserve(2 * new_size);
        for (int i = size(); i != new_size; ++i)
            alloc.construct(first_free++, s);
    }
    else if (new_size < size())
    {
        while (first_free != elements + new_size)
            alloc.destroy(--first_free);
    }
}

void StrVec::chk_n_alloc()
{
    if (size() == capacity())
        reallocate();
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return { data, std::uninitialized_copy(b, e, data) };        // uninitialized_copy， 在给定位置（data）构造元素，返回尾后指针
}

void StrVec::free()
{
    // 不能传递给 deallocate 一个空指针，如果 elements 为 0，则函数什么也不做
    if (elements)
    {
        // 逆序销毁旧元素
        //for (auto p = first_free; p != elements; )
        //    alloc.destroy(--p);

        // use for_each and lamdba instead 

        /*
        @Mooophy:
        Compared to the old one, it doesn't need to worry about the order and decrement.
        So more straightforward and handy. 
        The only thing to do for using this approach is to add "&" to build the pointers to string pointers.
        */
        std::for_each(elements, first_free, [this](const std::string& rhs) { alloc.destroy(&rhs); });

        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;     // 分配当前大小两倍的内存空间
    alloc_n_move(newcapacity);
}

void StrVec::alloc_n_move(size_t new_cap) // 将当前 StrVec 的内容移动到新分配的内存中，内存可以容纳 new_cap 个元素
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;    // 指向新数组中的下一个空闲位置
    auto elem = elements;   // 指向旧数组中的下一个元素

    //// 将数据从旧内存移动到新内存
    //for (size_t i = 0; i != size(); ++i)
    //    alloc.construct(dest++, std::move(*elem++));
    //// 一旦移动完元素就释放旧内存空间
    //free();     
    //// 更新我们的数据结构
    //elements = newdata;
    //first_free = dest;
    //cap = elements + new_cap;

	// 使用 uninitialized_copy 和 move iterator 
	// 将数据从旧内存移动到新内存
	auto last = std::uninitialized_copy(std::make_move_iterator(elements), 
										std::make_move_iterator(first_free),
										newdata);
	free();
	elements = newdata;
	first_free = last;
	cap = elements + new_cap;
}
