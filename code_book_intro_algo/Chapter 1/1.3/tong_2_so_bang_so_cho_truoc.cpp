#include<stdio.h>

int main(){
	int x = 17;
	int k,j = 0;
	int a[10] = {1,2,3,4,5,6,7,8,9};
	int sh1[10];
	int sh2[10];
	int t = x/2;
	for(int i = 0;i<9;i++){
		if(t>a[i]){
			sh1[k] = a[i];
			k++;
		}
		else{
			sh2[j] = a[i];
			j++;
		}
	}
	if(j == 0) printf("Ko ton tai bo so thoa man");
	else if(k == 0) printf("Ko ton tai");
	else{
		while(k>=0&&j>=0){
			if(a[k])
		}
	}
}
