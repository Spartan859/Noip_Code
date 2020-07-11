#include<iostream>
#define R 4
#define N 10
using namespace std;
int cnt[R],x,i,j;
int main() {
	//cnt计数器数组清零 
	for(i=0;i<N;i++) {
		cin>>x;
		cnt[x]++;
	}
	for(i=1;i<R;i++)
		for(j=0;j<cnt[i];j++)
			cout<<i<<" ";
	return 0;
}
//2 3 1 1 2 3 3 2 2 2

