#pragma once

/*

��ϰ 13.44����д��׼������ string ��ļ򻯰汾������Ϊ String�������Ӧ��������һ��Ĭ�Ϲ��캯����һ������ C ����ַ���ָ������Ĺ��캯����
ʹ�� allocator Ϊ��� String ����������ڴ�

��ϰ 13.47����������ϰ 13.44 �ж���� String �࣬Ϊ���Ŀ������캯��������ֵ��������һ����䣬��ÿ�κ���ִ��ʱ��ӡһ����Ϣ��

��ϰ 13.48������һ�� vector<String> �������϶�ε��� push_back��������ĳ��򣬲��۲� String �������˶��ٴΡ�

*/

#include <memory>
#include <cstring>      // strlen()
#include <utility>
#include <iostream>
#include <iterator>
#include <algorithm>

class String {
private:
    char *elements;
    char *end;

    std::allocator<char> alloc;     // ����Ԫ��

public:
	String() : String("") { std::cout << "run Default Constructor" << std::endl; }       // Ĭ�Ϲ����ַ���ʱ���ַ���ռһ���ڴ浥Ԫ���洢 '\0'
    String(const char *s)
    {
		std::cout << "run Constructor" << " s: " << s << std::endl;
        auto newdata = alloc_n_copy(s, s + strlen(s) + 1);      // ���� strlen(s) + 1 ���ڴ浥Ԫ�����һ��������ſ��ַ� '\0'
        elements = newdata.first;
        end = newdata.second;
    }
    String(const String& rhs)
    {
		std::cout << "run Copy Constructor" << " rhs: " << rhs.c_str() << std::endl;
		auto newdata = alloc_n_copy(rhs.elements, rhs.end);
        elements = newdata.first;
        end = newdata.second;
    }
    String& operator= (const String& rhs)
    {
		std::cout << "run Copy Assignment Operator" << std::endl;
        auto newdata = alloc_n_copy(rhs.elements, rhs.end);
        free();
        elements = newdata.first;
        end = newdata.second;
        return *this;
    }
    ~String()
    {
		std::cout << "run Desturctor" << " c_str(): " << c_str() << std::endl;
        free();
    }

    const char* c_str() const { return elements; }
    size_t size() const { return end - elements; }      
    size_t length() const { return end - elements - 1; }    // ���һ��λ��������ſ��ַ� '\0'
private:
    std::pair<char*, char*> alloc_n_copy(const char *b, const char *e)
    {
        auto data = alloc.allocate(e - b);
        return { data, std::uninitialized_copy(b, e, data) };
    }
    void free()
    {
        if (elements)
        {
            std::for_each(elements, end, [this](char& c) { alloc.destroy(&c); });
            alloc.deallocate(elements, end - elements);
        }
    }
};
