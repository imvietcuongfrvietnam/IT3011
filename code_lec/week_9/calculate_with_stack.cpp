#include<stack>
#include<iostream>

using namespace std;

inline charToInt(char s){
	return s-'0';
}
int calculateWithStack(string s){
	stack<char> oper;
	stack<char> toanhang;
	int k = s.length();
	for(int i = 0;i<k;i++){
		if(s[i] == '('){
			oper.push(s[i]);
		}
	}
}
int main(){
	
}
