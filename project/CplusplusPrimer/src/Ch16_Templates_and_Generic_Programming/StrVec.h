#pragma once

#include <memory>
#include <string>
#include <initializer_list>
#include <iostream>

class StrVec;
std::ostream& operator<< (std::ostream&, const StrVec&);


// �� vector ���ڴ������Եļ�ʵ�֡�
class StrVec {
friend std::ostream& operator<< (std::ostream&, const StrVec&);

private:
    std::allocator<std::string> alloc;       // ����Ԫ�أ������Ԫ�صĺ�����ʹ��

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
	void push_back(std::string&& s);		// ��ֵ���ò����� push_back

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
    // ��֤ StrVec ����������һ����Ԫ�صĿռ䡣���û�пռ������Ԫ�أ�chk_n_alloc ����� reallocate ���ڴ�����ʱΪ StrVec �������ڴ档
    void chk_n_alloc();
    // �����ڴ棬����һ��������Χ�е�Ԫ��
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string *b, const std::string *e);
    void free();
    void reallocate();
    // ����ǰ StrVec �������ƶ����·�����ڴ��У��·�����ڴ����������ɵ�ǰ���е�Ԫ�أ����ڴ�������� new_cap ��Ԫ��
    void alloc_n_move(size_t new_cap);
};

template<typename...Args>
void StrVec::emplace_back(Args&&...args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

void test_str_vec();
