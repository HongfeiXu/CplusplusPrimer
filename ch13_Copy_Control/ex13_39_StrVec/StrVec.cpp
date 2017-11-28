#include "StrVec.h"
#include <algorithm>

StrVec::StrVec(const StrVec &s)
{
    // ���� alloc_n_copy ����ռ��������� s ��һ�����Ԫ��
    auto newdata = alloc_n_copy(s.elements, s.first_free);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec &s)
{
    // ���ͷ�����Ԫ��֮ǰ���� alloc_n_copy������������ȷ�����Ը�ֵ����
    auto data = alloc_n_copy(s.elements, s.first_free);
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();      // ȷ���пռ�������Ԫ��
    alloc.construct(first_free++, s);   // �� first_free ָ���Ԫ���й��� s �ĸ���
}

void StrVec::reserve(size_t new_cap)
{
    // ֻ�е���Ҫ���ڴ�ռ䳬����ǰ����ʱ�� reserve ���òŻ�ı� StrVec ������
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
    return { data, uninitialized_copy(b, e, data) };        // uninitialized_copy�� �ڸ���λ�ã�data������Ԫ�أ�����β��ָ��
}

void StrVec::free()
{
    // ���ܴ��ݸ� deallocate һ����ָ�룬��� elements Ϊ 0������ʲôҲ����
    if (elements)
    {
        // �������پ�Ԫ��
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
    auto newcapacity = size() ? 2 * size() : 1;     // ���䵱ǰ��С�������ڴ�ռ�
    alloc_n_move(newcapacity);
}

void StrVec::alloc_n_move(size_t new_cap) // ����ǰ StrVec �������ƶ����·�����ڴ��У��ڴ�������� new_cap ��Ԫ��
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;    // ָ���������е���һ������λ��
    auto elem = elements;   // ָ��������е���һ��Ԫ��

    // �����ݴӾ��ڴ��ƶ������ڴ�
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    // һ���ƶ���Ԫ�ؾ��ͷž��ڴ�ռ�
    free();     
    // �������ǵ����ݽṹ
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}
