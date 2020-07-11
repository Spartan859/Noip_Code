#include<iostream>
#include<algorithm>
#define N 1005 
using namespace std;
int n,f[N],x[N];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>x[i];
	f[0]=1;
	for(int i=1;i<n;i++){
		f[i]=1;
		for(int j=0;j<i;j++)
			if(x[j]>x[i])f[i]=max(f[i],f[j]+1);
	}
	cout<<*max_element(f,f+n)<<endl; 
	return 0;
}
