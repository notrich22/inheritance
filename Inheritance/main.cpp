#include<iostream>
#include<string>
using namespace std;

class Box
{
	double height, width, depth;
	string material;
public:
	Box(string material, double height, double width, double depth)
	{
		this->material = material;
		this->height = height;
		this->width = width;
		this->depth = depth;
		cout << "BConstructor:\t" << this << endl;
	}
	~Box()
	{
		cout << "BDestructor:\t" << this << endl;
	}
	void print()
	{
		cout << "Material:   " << material << endl;
		cout << "Dimensions: " << height << "x" << width << "x" << depth << endl;
		cout << "Volume:     " << height * width * depth << endl;
	}
};

class GiftBox :public Box
{
	string cover;
public:
	GiftBox(string material, double height, double width, double depth, string conver):
		Box(material, height, width, depth)
	{
		this->cover = cover;
		cout << "GBConstructor:\t" << this << endl;
	}
	~GiftBox()
	{
		cout << "GBDestructor:\t" << this << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Box box("Картон", 3, 4, 5);
	box.print();

	GiftBox gift_box("Cardboard", 3, 4, 5, "With roses");
	gift_box.print();
}

//"является" - "is a"
//кот является животным? - Класс Кот наследует свойства класса Животное
//кот является растением? - Нет, значит классы не наследуются, поскольку находятся в разных иерархиях.
//Мусоровоз является машиной? - Наследуется.
//Колесо является машиной? - Нет, не является, машина включает в себя колесо