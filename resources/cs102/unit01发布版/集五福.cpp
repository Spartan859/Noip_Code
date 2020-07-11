#include<iostream>
#define R 6
using namespace std;
int cnt[R],n,x;
int main() {
	cin>>n;
	//cnt计数器数组清零 
	for(int i=0;i<n;i++) {
		cin>>x;
		cnt[x]++;
	}
	int ans=cnt[1];
	for(int i=1;i<R;i++)
		ans=min(ans,cnt[i]);
	cout<<ans<<endl;
	return 0;
}

