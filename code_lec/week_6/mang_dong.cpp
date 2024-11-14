#include<stdio.h>
#include<stdlib.h>

int main(){
	int i, n, *p;
	printf("Nhap so luong phan tu cua mang = ");
	scanf("%d", &n);
	
	p = (int*)malloc(sizeof(int) * n);
	
	if(p == NULL){
		printf("\nCap phat bo nho khong thanh cong");
		return 1;
	}
	
	for(int i = 0;i<n;i++){
		scanf("%d", p+i);
	}
	
	for(int i = n-1;i>=0;i--){
		printf("%d ",p[i]);
	}
	free(p);
	return 1;
}
