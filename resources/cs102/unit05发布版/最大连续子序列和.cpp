#include<iostream>
#include<algorithm>
#define N 100005
using namespace std;
int n,x[N],f[N];
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	f[0]=x[0];
	for(int i=1;i<n;i++)
		f[i]=max(f[i-1],0)+x[i];
	cout<<*max_element(f,f+n)<<endl;
	return 0;
}
