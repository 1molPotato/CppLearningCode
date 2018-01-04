#include "Time.h"

#include <iostream>
#include <iomanip>

using namespace std;

Time::Time(int h, int m, int s){
	setTime(h, m, s);//validate and set  time
}

void Time::setTime(int h, int m, int s){
	setHour(h);
	setMinute(m);
	setSecond(s);
}

void Time::setHour(int h){
	if(0 <= h && h < 24)
		hour = h;
	else
		hour = 0; 
}

void Time::setMinute(int m){
	minute = (m >=0 && m < 60) ? m : 0;//validate minute
}

void Time::setSecond(int s){
	second = (s >=0 && s < 60) ? s : 0;//validate minute
}

int Time::getHour(){
	return hour;
}

int Time::getMinute(){
	return minute;
}

int Time::getSecond(){
	return second;
}

void Time::tick(){
	setSecond(getSecond() + 1);
	if(0 == getSecond()){
		setMinute(getMinute() + 1);
		if(0 == getMinute())
			setHour(getHour()+ 1);
	}	
}

void Time::printUniversal(){
	cout << setfill('0') << setw(2) << getHour() << ":"
	<< setw(2) << getMinute() << ":" << setw(2) 
	<< getSecond() << endl;
}

//print time as hh:mm:ss am or pm
void Time::printStandard(){
	cout << setfill('0') << setw(2) << ((getHour() == 12 
	|| 0 == getHour()) ? 12 : getHour() % 12) << ":"
	<< setw(2) << getMinute() << ":" << setw(2) 
	<< getSecond() << (getHour() < 12 ? "am" : "pm") << endl;
}



