#pragma once

/*

��ϰ 13.44����д��׼������ string ��ļ򻯰汾������Ϊ String�������Ӧ��������һ��Ĭ�Ϲ��캯����һ������ C ����ַ���ָ������Ĺ��캯����
ʹ�� allocator Ϊ��� String ����������ڴ�

��ϰ 13.47����������ϰ 13.44 �ж���� String �࣬Ϊ���Ŀ������캯��������ֵ��������һ����䣬��ÿ�κ���ִ��ʱ��ӡһ����Ϣ��

��ϰ 13.48������һ�� vector<String> �������϶�ε��� push_back��������ĳ��򣬲��۲� String �������˶��ٴΡ�

*/

#include <memory>
#include <cstring>      // strlen()
#include <utility>		// move
#include <iostream>
#include <iterator>
#include <algorithm>

class String {
private:
    char *elements;
    char *end;

    std::allocator<char> alloc;     // ����Ԫ��

public:
	String() : String("") { }       // Ĭ�Ϲ����ַ���ʱ���ַ���ռһ���ڴ浥Ԫ���洢 '\0'
    String(const char *s)
    {
		std::cout << "String::Constructor" << std::endl;
		auto newdata = alloc_n_copy(s, s + strlen(s) + 1);      // ���� strlen(s) + 1 ���ڴ浥Ԫ�����һ��������ſ��ַ� '\0'
        elements = newdata.first;
        end = newdata.second;
    }
    String(const String& s)
    {
		std::cout << "String::CopyConstructor" << std::endl;
		auto newdata = alloc_n_copy(s.elements, s.end);
        elements = newdata.first;
        end = newdata.second;
    }
	String(String &&s) noexcept 
		: elements(s.elements), end(s.end)
	{
		std::cout << "String::MoveConstructor" << std::endl;
		// �� s ����������״̬���������������������ǰ�ȫ��
		s.elements = s.end = nullptr;
	}
    String& operator= (const String& rhs)
    {
        auto newdata = alloc_n_copy(rhs.elements, rhs.end);
        free();
        elements = newdata.first;
        end = newdata.second;
        return *this;
    }
	String& operator= (String&& rhs) noexcept
	{
		if (this != &rhs)
		{
			free();
			elements = rhs.elements;
			end = rhs.end;
			// �� s ����������״̬���������������������ǰ�ȫ��
			rhs.elements = rhs.end = nullptr;
		}
		return *this;
	}
    ~String()
    {
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


/*

#include <iostream>
#include <vector>
#include <utility>
#include "String.h"

using namespace std;

int main()
{
	String str("Hello");
	String str2("World");

	String str3 = std::move(str);


	return 0;
}


String::MoveConstructor
�밴���������. . .

*/