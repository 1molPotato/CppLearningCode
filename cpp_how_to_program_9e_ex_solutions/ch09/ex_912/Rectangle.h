#pragma once

class Point2D{
public:
	Point2D();//默认构造函数
	Point2D(double x, double y);
	//set functions
	bool setCoord(double x, double y);//set coord x, y and validate
	bool setX(double x);//set x and validate
	bool setY(double y);//set y and validate
	//get functions
	double getX();//return x
	double getY();//return y 
private:
	double coordX;
	double coordY;
};

class Rectangle{
public:
	Rectangle();//默认构造函数
	Rectangle(double *coordinates);
	//set functions
	bool setCorners(double *coordinates);//
	bool isRectangle();//validate rectangle
	bool isSquare();//validate square;
	//get(compute) functions
	double getLength();//compute length
	double getWidth();//compute width
	double getPerimeter();//compute perimeter
	double getArea();//comput area
private:
	Point2D corners[4];
};

