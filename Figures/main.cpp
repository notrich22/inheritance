#define _USE_MATH_DEFINES
#include <iostream>
#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;

namespace Geometry
{
	//typedef unsigned int color;
	enum Color
	{
		console_black = 0x00,
		console_white = 0xFF,//0xFFFFFF00,
		console_red = 0xCC,//0xFF000000,
		console_green = 0xAA,//0x00FF0000,
		console_blue = 0x99,//0x0000FF00
		default_console_color = 0x07,

		black = 0x00000000,
		red = 0x000000FF,
		green = 0x0000AA00,
		yellow = 0x0000FFFF,
		blue = 0x00FF0000,
		grey = 0x00555555,
		white = 0x00FFFFFF,
	};
	class Shape {
		//unsigned int color;
	protected:
		Color color;
	public:
		Shape(Color color) :color(color) {}
		virtual ~Shape() {}
		virtual double area() const = 0;
		virtual double perimeter()const = 0;
		virtual void draw() const = 0;

		virtual void info()const = 0;
	};

	class Square : public Shape {
		double side;
	public:
		double get_side() const {
			return side;
		}
		double set_side(double side) {
			if (side <= 0)side = 1;
			this->side = side;
			return this->side;
		}
		Square(Color color, double side) :Shape(color)//, side(set_side(side)) 
		{
			set_side(side);
		}
		~Square() {}
		double area() const {
			return pow(side, 2);
		}
		double perimeter() const {
			return side * 4;
		}
		void draw() const {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++) {
				for (int j = 0; j < side; j++) {
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::default_console_color);
		}

		void info()const {
			cout << "\tSquare: \n";
			cout << "   Side length: " << side << endl;
			cout << "   Area: " << this->area() << endl;
			cout << "   Perimeter: " << this->perimeter() << endl;
		}
	};

	class Rectangle :public Shape {
		double length;
		double width;
	public:
		double get_length()const {
			return length;
		}
		double get_width()const {
			return width;
		}
		void set_length(double length) {
			if (length <= 0)this->length = 1;
			else this->length = length;
		}
		void set_width(double width) {
			if (width <= 0)this->width = 1;
			else this->width = width;
		}
		Rectangle(Color color, double length, double width) : Shape(color) {
			set_length(length);
			set_width(width);
		}
		~Rectangle() {}
		double area()const {
			return length * width;
		}
		double perimeter()const {
			return 2 * (length + width);
		}
		void draw()const {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < width; i++) {
				for (int j = 0; j < length; j++) {
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::default_console_color);
		}
		void info()const {
			cout << "\tRectangle: \n";
			cout << "   Side length: " << length << "x" << width << endl;
			cout << "   Area: " << this->area() << endl;
			cout << "   Perimeter: " << this->perimeter() << endl;
		}
	};

	class Circle :public Shape 
	{
		UINT start_x;
		UINT start_y;
		double radius;
	public:
		double get_radius()const
		{
			return radius;
		}
		double get_diameter()const
		{
			return radius * 2;
		}
		void set_radius(double radius)
		{
			if (radius <= 0)radius = 1;
			this->radius = radius;
		}
		void set_start_x(UINT x)
		{
			if (x >= 1000)x = 1000;
			start_x = x;
		}
		void set_start_y(UINT y)
		{
			if (y >= 700)y = 700;
			start_y = y;
		}
		Circle(Color color, double radius, UINT start_x = 0, UINT start_y = 0) :Shape(color)
		{
			set_radius(radius);
			set_start_x(start_x);
			set_start_y(start_y);
		}
		~Circle() {}

		double area()const
		{
			return M_PI * pow(radius, 2);
		}
		double perimeter()const
		{
			return 2 * M_PI * radius;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);

			HBRUSH hBrush = CreateSolidBrush(black);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << "Circle:\n";
			cout << "Radius:  " << radius << endl;
			cout << "Area: " << area() << endl;
			cout << "Perimeter:" << perimeter() << endl;
			draw();
		}
	};

	class Triangle :public Shape
	{
	public:
		Triangle(Color color) : Shape(color) {}
		~Triangle() {}
	};

	class EquiltateralTriangle :public Triangle
	{
		UINT start_x;
		UINT start_y;
		double side;
	public:
		double get_side()const {
			return side;
		}
		void set_side(double side) {
			if (side <= 0)side = 1;
			this->side = side;
		}
		void set_start_x(UINT x)
		{
			if (x >= 1000)x = 1000;
			start_x = x;
		}
		double get_height()const
		{
			return side * pow(3, .5) / 2;
		}
		void set_start_y(UINT y)
		{
			if (y >= 700)y = 700;
			start_y = y;
		}
		EquiltateralTriangle(Color color, double side) : Triangle(color){
			set_side(side);
		}
		~EquiltateralTriangle() {}

		double area()const {
			return side * side * pow(3, 0.5) / 4;
		}
		double perimeter()const {
			return side * 3;
		}
		void draw()const {
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HBRUSH hBrush = CreateSolidBrush(color);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);

			SelectObject(hdc, hBrush);
			SelectObject(hdc, hPen);

			POINT points[] =
			{
				{start_x, start_y + side},
				{start_x + side, start_y + side},
				{start_x + side / 2, start_y + side - get_height()}
			};

			Polygon(hdc, points, sizeof(points) / sizeof(POINT));

			/*POINT points[] =
			{
				{200, 100},
				{300, 10},
				{400, 100}
			};
			Polygon(hdc, points, sizeof(points) / sizeof(POINT));*/

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const {
			cout << "Equiltateral Triangle:\n";
			cout << "Side:     " << side << endl;
			cout << "Area:     " << area() << endl;
			cout << "Perimeter:" << perimeter() << endl;
			draw();
		}
	};
}
int main() {
	setlocale(LC_ALL, "ru");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer = { 80,50 };
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN, &buffer);

	Geometry::Square square(Geometry::Color::console_red, 12);
	square.draw();
	square.info();

	Geometry::Rectangle rect(Geometry::Color::console_green, 8, 4);
	rect.draw();
	rect.info();

	Geometry::Circle circ(Geometry::Color::yellow, 100, 300, 100);
	circ.draw();
	circ.info();
	Geometry::EquiltateralTriangle equil_triangle(Geometry::Color::green, 50);
	equil_triangle.info();
}