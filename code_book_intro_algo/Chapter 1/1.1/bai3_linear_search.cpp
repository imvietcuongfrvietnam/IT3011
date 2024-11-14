#include<stdio.h>
#include<iostream>
#include<stdlib.h>
int main(){
	int v = 20;
	int key;
	int a[] = {1,2,3,4,5,6,7,8,9,10,20,12,4,3,1,54,31,12,13};
	for(int i = 0;i<19;i++){
		if(a[i] == v) {
		key = i;
		break;
	}
	}
	return 0;
	
}
