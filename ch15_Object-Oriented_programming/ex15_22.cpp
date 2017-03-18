/*
练习 15.21：从下面这些一般性抽象概念中任选一个，将其对应的一组类型组织成一个继承体系。
(b) 图形基元 （如方格、圆、球、圆锥）
练习 15.22：对于你在上一题中选择的类，为其添加合适的虚函数及共有成员和受保护的成员。
*/

#include <iostream>
#include <string>
#include <utility>

// just for 2D shape
class Shape
{
public:
	Shape() = default;
	Shape(const std::string &name_) :
		name(name_) { }
	virtual ~Shape() = default;

	virtual double area() const = 0;
	virtual double perimeter() const = 0;


private:
	std::string name;
};

// Rectangle Class, has length and width
class Rectangle : public Shape
{
public:
	Rectangle() = default;
	Rectangle(const std::string name_, double length_, double width_) :
		Shape(name_), length(length_), width(width_) { }
	~Rectangle() = default;

	double area() const override { return length * width; }
	double perimeter() const override { return 2 * (length + width); }

private:
	double length = 0;
	double width = 0;
};

// Square Class, has len
class Square : public Rectangle
{
public:
	Square() = default;
	Square(const std::string &name_, double len) :
		Rectangle(name_, len, len) { }

private:
	double len = 0;
};

int main()
{
	Rectangle rec(std::string("Rectangle"), 2, 3);
	std::cout << rec.area() << std::endl;

	Square squ(std::string("Square"), 2);
	std::cout << squ.area() << std::endl;
	

	return 0;
}