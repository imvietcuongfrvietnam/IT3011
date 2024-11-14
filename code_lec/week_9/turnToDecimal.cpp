#include<queue>
#include<iostream>

using namespace std;

int turnToDecimal(string s){
	int res = 0;
	queue<int> q;
	int k = s.length();
	for(int i = 0;i<k;i++){
		q.push(s[i] - '0');
	}
	while(!q.empty()){
		res = res*10+ q.front();
		q.pop();
	}
	return res;
}
int main(){
	cout<<turnToDecimal("777");
}
