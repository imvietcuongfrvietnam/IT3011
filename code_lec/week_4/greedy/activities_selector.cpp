#include<iostream>
#include<vector>
#define MAX 100
using namespace std;

int n = 11;

int s[MAX] = {0, 1, 3, 0, 5 ,3, 5, 6, 8, 8, 2, 12};
int f[MAX] = {0, 4, 5, 6 , 7, 8 ,9, 10,11,12,13,14};

vector<int> greedy_activities_selector(int n){
vector<int> A;
A.push_back(1);
int j = 1;
for(int i = 2;i<=n;i++){
    if(s[i]>=f[j]){A.push_back(i);
    j = i;}
}
return A;
}

int main(){
 vector<int> res = greedy_activities_selector(n);
for(int i : res){
    cout<<i<<" ";
}
return 0;
}
