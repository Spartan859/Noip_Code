#include<iostream>
#include<algorithm>
#define N 200005
using namespace std;
int n,x[N],f[N],fd[N]; 
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	f[0]=x[0]; fd[0]=0;
	for(int i=1;i<n;i++){
		if(f[i-1]>0) f[i]=f[i-1]+x[i],fd[i]=fd[i-1]+1;
		else f[i]=x[i],fd[i]=0;
	}
	if(*max_element(f,f+n)>0)
	cout<<*max_element(f,f+n)<<' '<<max_element(f,f+n)-f-fd[max_element(f,f+n)-f]<<' '<<max_element(f,f+n)-f<<endl;
	else cout<<0<<endl; 
	return 0;
}
