#include<iostream>
#include<stack>

bool checkSymbol(string s){
	int len = s.length();
	stack<char> st;
	for(int i = 0;i<len;i++){
		switch (s[i]) {
			case '(':
			case '{':
			case '[':
				st.push(s[i]);
				break;
			default:
				if(st.empty()) return false;
				char c = st.top();
				st.pop();
				if(c == '(' && s[i] == ')' ||
				   c == '{' && s[i] == '}' ||
				   c == '[' && s[i] == ']') break;
				return false;
	}
}
	return st.empty();
}

int main(){
	string s = "[[[[";
	cout<<checkSymbol(s);
}



