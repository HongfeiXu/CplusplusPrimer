#pragma once

#include <memory>
#include <string>
#include <initializer_list>
#include <iostream>

class StrVec;
std::ostream& operator<< (std::ostream&, const StrVec&);


// 类 vector 类内存分配策略的简化实现。
class StrVec {
friend std::ostream& operator<< (std::ostream&, const StrVec&);

private:
    std::allocator<std::string> alloc;       // 分配元素，被添加元素的函数所使用

    std::string *elements;
    std::string *first_free;
    std::string *cap;

public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(std::initializer_list<std::string> il);
    StrVec(const StrVec &s);
	StrVec(StrVec &&s) noexcept;
	~StrVec();
	StrVec& operator= (const StrVec &rhs);
	StrVec& operator= (StrVec &&rhs) noexcept;
    StrVec& operator= (std::initializer_list<std::string>);
    std::string& operator[] (std::size_t n)
    {
        return elements[n];
    }
    const std::string& operator[] (std::size_t n) const
    {
        return elements[n];
    }

	void push_back(const std::string& s);
	void push_back(std::string&& s);		// 右值引用参数的 push_back

    template<typename... Args>
    void emplace_back(Args&&...);

	size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    void reserve(size_t new_cap);
    void resize(size_t new_size);
    void resize(size_t new_size, const std::string& s);

private:
    // 保证 StrVec 至少有容纳一个新元素的空间。如果没有空间添加新元素，chk_n_alloc 会调用 reallocate 在内存用完时为 StrVec 分配新内存。
    void chk_n_alloc();
    // 分配内存，拷贝一个给定范围中的元素
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string *b, const std::string *e);
    void free();
    void reallocate();
    // 将当前 StrVec 的内容移动到新分配的内存中（新分配的内存至少能容纳当前所有的元素），内存可以容纳 new_cap 个元素
    void alloc_n_move(size_t new_cap);
};

template<typename...Args>
void StrVec::emplace_back(Args&&...args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

void test_str_vec();
