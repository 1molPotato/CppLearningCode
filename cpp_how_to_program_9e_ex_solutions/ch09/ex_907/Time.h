#pragma once

class Time{
public:
	Time(int h = 0, int m = 0, int s = 0);//默认构造函数
	//set functions
	void setTime(int h, int m, int s);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	//get functions
	int getHour();//return hour
	int getMinute();//return minute
	int getSecond();//return second
	void tick();//秒数递增
	void printUniversal();
	void printStandard();
private:
	int hour;
	int minute;
	int second;
};