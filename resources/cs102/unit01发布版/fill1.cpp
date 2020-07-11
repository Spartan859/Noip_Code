#include<iostream>
#include<algorithm>
#define N 10
using namespace std;
int f[N];
int main() {
	fill(f,f+N,6);
	for(int i=0;i<N;i++)
		cout<<f[i]<<" ";
	cout<<"\n-----\n";
	fill(f,f+N,-1);
	for(int i=0;i<N;i++)
		cout<<f[i]<<" ";
	return 0;
}

