#include<stdio.h>

int empty_stack(int s[]){
	if(top[S] == 0) return true;
	return false;
}

void push(int S[], int x){
	top[S] = top[S] + 1;
	S[top[S]] = x;
}

int pop(int S[]){
	if(empty_stack) return -1; //error underflow
	else{
		int res = S[top[S]];
		top[S] -= 1;
		return res;
	}
}


int main(){
	
	
}
