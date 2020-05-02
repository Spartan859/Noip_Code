#include<bits/stdc++.h>
using namespace std;
void swp(int *a,int *b){
	int *k;
	k=a,a=b,b=k;
}
int main(){
	int a=3,b=6,*x=&a,*y=&b;
	swp(x,y);
	cout<<a<<','<<b<<endl;
}
