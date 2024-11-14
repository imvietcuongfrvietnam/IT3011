#include<iostream>
#include<queue>
#include<stack>
using namespace std;

bool isPalindrome(string s){
	queue<char> qchar;
	stack<char> schar;
	int len = s.length();
	for(int i = 0;i<len;i++){
		qchar.push(s[i]);
		schar.push(s[i]);
	}
	while(!qchar.empty() || !schar.empty()){
		if(qchar.front() != schar.top()){
			return false;
		}
		qchar.pop();
		schar.pop();
	}
	return qchar.empty() && schar.empty();
}
string upper(string s){
	char res[s.length()];
	for(int i = 0;i<s.length();i++){
		res[i] = toupper(s[i]);
	}
	return res;
}
int main(){
	string s = "RADAR";
	cout<<isPalindrome(s)<<"\n"<<isPalindrome(upper("Able was I ere I saw Elba"));
}
