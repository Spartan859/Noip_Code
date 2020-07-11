#include<iostream>
#include<algorithm>
#define N 20
using namespace std;
int n,p[N];
void print(){
	for(int i=0;i<n-1;i++)cout<<p[i]<<" ";
	cout<<p[n-1]<<endl;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)p[i]=i+1;
	do{
		print();
	}while(next_permutation(p,p+n));
	return 0;
}



