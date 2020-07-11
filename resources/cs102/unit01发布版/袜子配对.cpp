#include<iostream>
#define A 30
#define B 50
#define R 21
using namespace std;
int cnt[R],n,x,ans=0;
int main() {
	cin>>n;
	//cnt计数器数组清零 
	for(int i=0;i<n;i++) {
		cin>>x;
		cnt[x-A]++;
	}
	for(int i=0;i<R;i++)
		ans+=cnt[i]/2;
	cout<<ans<<endl;
	return 0;
}

