#pragma once

/*

��ϰ 13.44����д��׼������ string ��ļ򻯰汾������Ϊ String�������Ӧ��������һ��Ĭ�Ϲ��캯����һ������ C ����ַ���ָ������Ĺ��캯����
ʹ�� allocator Ϊ��� String ����������ڴ�

��ϰ 13.47����������ϰ 13.44 �ж���� String �࣬Ϊ���Ŀ������캯��������ֵ��������һ����䣬��ÿ�κ���ִ��ʱ��ӡһ����Ϣ��

��ϰ 13.48������һ�� vector<String> �������϶�ε��� push_back��������ĳ��򣬲��۲� String �������˶��ٴΡ�

��ϰ 13.50������� String ����ƶ���������Ӵ�ӡ��䣬����������13.6.1�ڵ���ϰ13.48�еĳ�����ʹ����һ��vector���۲�ʲôʱ�����⿽����

��ϰ14.7������13.5�ڵ���ϰ��������д��һ��String�࣬Ϊ������һ������������

��ϰ14.16��Ϊ��� StrBlob �ࡢStrBlobPtr �ࡢStrVec ��� String ��ֱ������������Ͳ�����������

��ϰ14.18��Ϊ��� StrBlob �ࡢStrBlobPtr �ࡢStrVec ��� String ��ֱ����ϵ�������

*/

#include <memory>
#include <cstring>      // strlen()
#include <utility>		// move
#include <iostream>
#include <iterator>
#include <algorithm>

class String {
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	friend bool operator<(const String&, const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator<=(const String&, const String&);
	friend bool operator>=(const String&, const String&);
public:
	String() : String("") { }       // Ĭ�Ϲ����ַ���ʱ���ַ���ռһ���ڴ浥Ԫ���洢 '\0'
	String(const char* s)
	{
		std::cout << "String::Constructor" << std::endl;
		auto newdata = alloc_n_copy(s, s + strlen(s) + 1);      // ���� strlen(s) + 1 ���ڴ浥Ԫ�����һ��������ſ��ַ� '\0'
		elements = newdata.first;
		end_elem = newdata.second;
	}
	String(const String& s)
	{
		std::cout << "String::CopyConstructor" << std::endl;
		auto newdata = alloc_n_copy(s.elements, s.end_elem);
		elements = newdata.first;
		end_elem = newdata.second;
	}
	String(String&& s) noexcept
		: elements(s.elements), end_elem(s.end_elem)
	{
		std::cout << "String::MoveConstructor" << std::endl;
		// �� s ����������״̬���������������������ǰ�ȫ��
		s.elements = s.end_elem = nullptr;
	}
	String& operator= (const String& rhs)
	{
		auto newdata = alloc_n_copy(rhs.elements, rhs.end_elem);
		free();
		elements = newdata.first;
		end_elem = newdata.second;
		return *this;
	}
	String& operator= (String&& rhs) noexcept
	{
		if (this != &rhs)
		{
			free();
			elements = rhs.elements;
			end_elem = rhs.end_elem;
			// �� s ����������״̬���������������������ǰ�ȫ��
			rhs.elements = rhs.end_elem = nullptr;
		}
		return *this;
	}
	char& operator[] (std::size_t n)
	{
		return elements[n];
	}
	const char& operator[] (std::size_t n) const
	{
		return elements[n];
	}
	~String()
	{
		free();
	}

	char* begin() const { return elements; }
	char* end() const { return end_elem; }

	const char* c_str() const { return elements; }
	size_t size() const { return end_elem - elements; }
	size_t length() const { return end_elem - elements - 1; }    // ���һ��λ��������ſ��ַ� '\0'
private:
	std::pair<char*, char*> alloc_n_copy(const char* b, const char* e)
	{
		auto data = alloc.allocate(e - b);
		return { data, std::uninitialized_copy(b, e, data) };
	}
	void free()
	{
		if (elements)
		{
			std::for_each(elements, end_elem, [this](char& c) { alloc.destroy(&c); });
			alloc.deallocate(elements, end_elem - elements);
		}
	}

private:
	char* elements;
	char* end_elem;
	std::allocator<char> alloc;     // ����Ԫ��
};

std::ostream& operator<<(std::ostream& out, const String& s);
bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
bool operator<(const String&, const String&);
bool operator>(const String&, const String&);
bool operator<=(const String&, const String&);
bool operator>=(const String&, const String&);

void test_string();
