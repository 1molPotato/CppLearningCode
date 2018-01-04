#include "Rectangle.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
class Point2D members definition
*/
Point2D::Point2D(){
	setCoord(0.0, 0.0);
}
Point2D::Point2D(double x, double y){
	setCoord(x, y);
}
//set functions
bool Point2D::setCoord(double x, double y){
	bool flag1 = setX(x);
	bool flag2 = setY(y);
	return flag1 && flag2;
}

bool Point2D::setX(double x){
	if(x <= 0 || x > 20) {
		coordX = 0.0;
		return false;
	}		
	else{
		coordX = x;
		return true;
	}
}

bool Point2D::setY(double y){
	if(y <= 0 || y > 20) {
		coordY = 0.0;
		return false;
	}		
	else{
		coordY = y;
		return true;
	}
}
//get functions
double Point2D::getX(){
	return coordX;
}
double Point2D::getY(){
	return coordY;
}

/*
class Rectangle members definition
*/
Rectangle::Rectangle(){
	//default constructor
	
}
Rectangle::Rectangle(double *coordinates){
	if(!setCorners(coordinates))
		cout << "invalidate point" << endl;
}
//set functions
bool Rectangle::setCorners(double *coordinates){
	bool flag = true;//return true if create rectangle successfully 
	double *p = coordinates;
	for(int i = 0; i < 4; ++i){
		double x = p[2 * i];
		double y = p[2 * i + 1];
		Point2D point;
		if(!point.setCoord(x, y))
			flag = false;
		corners[i] = point;
	}
	flag = isRectangle();
	return flag;
}
bool Rectangle::isRectangle(){
	bool flag = true;
	int i = 1;
	while(i < 4){
		int j = i % 4 + 1;
		int k = j % 4 + 1;
		double v1X = corners[i - 1].getX() - corners[j - 1].getX();//ʸ��v1��x
		double v1Y = corners[i - 1].getY() - corners[j - 1].getY();//ʸ��v1��y
		double v2X = corners[j - 1].getX() - corners[k - 1].getX();//ʸ��v2��x
		double v2Y = corners[j - 1].getY() - corners[k - 1].getY();//ʸ��v2��y
		if(0 != v1X * v2X + v1Y * v2Y)
			flag = false;//ֻ�������ڱ߾���ֱ���Ǿ���
		i++;
	}
	if(!flag)
		cout << "not rectangle" << endl;
	return flag;
}

bool Rectangle::isSquare() {
	if(!isRectangle())
		return false;//���Ǿ��αض�����������
	if(getLength() == getWidth())
		return true;
	else
		return false;
}

double Rectangle::getLength() {
	//����Ϊlength
	if(!isRectangle())
		return 0.0;//���Ǿ������˳�����
	double dist1 = sqrt(pow(corners[0].getX() - corners[1].getX(), 2)
		+ pow(corners[0].getY() - corners[1].getY(), 2));//����߳�
	double dist2 = sqrt(pow(corners[1].getX() - corners[2].getX(), 2)
		+ pow(corners[1].getY() - corners[2].getY(), 2));
	return dist1 > dist2?dist1:dist2;
}

double Rectangle::getWidth() {
	//�̱�Ϊwidth
	if(!isRectangle())
		return 0.0;//���Ǿ������˳�����
	double dist1 = sqrt(pow(corners[0].getX() - corners[1].getX(), 2)
		+ pow(corners[0].getY() - corners[1].getY(), 2));//����߳�
	double dist2 = sqrt(pow(corners[1].getX() - corners[2].getX(), 2)
		+ pow(corners[1].getY() - corners[2].getY(), 2));
	return dist1 < dist2?dist1:dist2;
}

double Rectangle::getPerimeter() {
	if(!isRectangle())
		return 0.0;//���Ǿ������˳�����
	return (getLength() + getWidth()) * 2;//�����ܳ�
}

double Rectangle::getArea() {
	if(!isRectangle())
		return 0.0;//���Ǿ������˳�����
	return getLength() * getWidth();//�������
}








