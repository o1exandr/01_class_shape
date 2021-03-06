/*
Завдання 1.
Створити абстрактний базовий клас Shape, що містить:
o	чисті віртуальні функції print(), printShapeName() – без реалізації
o	віртуальні функції аrea(),volume(), що повертають нульове значення.

Клас Point успадковує реалізації аrea(),volume() від класу Shape(точка має нульову площу та об’єм).
Клас Circle  успадковує від класу Point реалізацію volume(),  але має власну реалізацію аrea().
Клас  Cylinder має власні реалізації функцій аrea()  та volume().

Створити масив(вектор)  фігур(вказівників на базовий клас). Викликати методи обчислення площі, об’єму та виведення для кожної фігури з масиву.

*/

#include "stdafx.h"
#include <iostream> 
#include <string>
#include <vector>

using namespace std;

const double PI = 3.14159265;

class Shape abstract
{
public:

	virtual void print() = 0;
	virtual void printShapeName() = 0;

	virtual double area()const
	{
		return 0;
	}

	virtual double volume()const
	{
		return 0;
	}
};

class Point : public Shape
{

public:

	void print() override
	{
		printShapeName();
		cout << "Area: " << area() << endl;
		cout << "Volume: " << volume() << endl << endl;
	}

	void printShapeName() override
	{
		cout << "Name: Point\n";
	}
};


class Circle : public Point
{
protected:

	double radius;

public:

	Circle() = default;

	Circle(double radius):radius(radius)
	{}

	double area()const override
	{
		return 2 * PI * radius;
	}

	void printShapeName() override
	{
		cout << "Name: Circle\n";
	}
};

class Cylinder : public Circle
{
protected:

	double radius;
	double height;

public:

	Cylinder(double radius = 1, double height = 1) :radius(radius), height(height)
	{}

	double area()const override
	{
		return 2 * PI * radius * (height + radius);
	}

	double volume()const override
	{
		double d = 2 * radius;
		return PI * (d * d / 4) * height;
	}

	void printShapeName() override
	{
		cout << "Name: Cylinder\n";
	}
};

int main()
{
	vector<Shape*> arr = { new Point(), new Circle(1), new Cylinder(2, 3) };
	for (size_t i = 0; i < arr.size(); ++i)
	{
		/*
		arr[i]->printShapeName();
		cout << "Area: " << arr[i]->area() << endl;
		cout << "Volume: " << arr[i]->volume() << endl << endl;
		*/
		arr[i]->print(); 
	}

	cout << endl;
	system("pause");
	return 0;
}