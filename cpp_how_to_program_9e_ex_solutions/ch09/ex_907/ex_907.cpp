#include "Time.h"

int main(){
	Time t;
	t.setTime(11, 59, 57);
	for(int i = 0; i < 60; ++i){
		t.printStandard();
		t.tick();
	}	
	return 0;
}