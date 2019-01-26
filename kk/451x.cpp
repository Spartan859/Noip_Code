#include<iostream>
#include<algorithm>
#define N 200005
using namespace std;
int n,x[N],fl[N],gl[N],fr[N],gr[N],ma,ans=-100005;
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	fl[0]=x[0];
	for(int i=1;i<n;i++)
		fl[i]=max(fl[i-1],0)+x[i];
	ma=-10005;
	for(int i=0;i<n;i++)
		gl[i]=ma=max(ma,fl[i]);
	fr[n-1]=x[n-1];
	for(int i=n-1;i>0;i--)
		fr[i]=max(fr[i+1],0)+x[i];
	ma=-10005;
	for(int i=n-1;i>=0;i--)
		gr[i]=ma=max(ma,fr[i]);
	for(int i=1;i<n-1;i++){
		if(gl[i-1]+gr[i+1]>ans)ans=gl[i-1]+gr[i+1];
	}
	cout<<ans<<endl;
	return 0;
}
