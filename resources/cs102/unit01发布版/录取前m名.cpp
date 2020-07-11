#include<iostream>
#define R 101
using namespace std;
int cnt[R],n,m,x,i,j;
int main() {
	cin>>n>>m;
	//cnt计数器数组清零 
	for(i=0;i<n;i++) {
		cin>>x;
		cnt[x]++;
	}
	for(i=R-1;i>=0&&m>0;m-=cnt[i--])
		for(j=0;j<cnt[i];j++)
			cout<<i<<" ";
	return 0;
}

