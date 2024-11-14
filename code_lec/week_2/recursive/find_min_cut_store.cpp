#include<stdio.h>
#include<cstdio>
//Cat giam cua hang
using namespace std;
int main(){
	int t;
	cin>>t;
	int s[4];
	int m[2];
	int j;
	while(t--){
		j = 0;
		m[0] = 0;
		m[1] = 0;
		for(int i = 0;i<4;i++){
			cin>>s[i];
			if(s[i]<0){
				for(int j = 0;j<2;j++){
					if(s[i]<m[j]) m[j] = s[i];
				}
			}
		}
		cout<<m[0] + m[1]<<endl;
		
	}
	return 0;
}
