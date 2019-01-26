#include<iostream>
using namespace std;
int a[100];
bool b[100];
int main(){
	int n,m,i,j,cnt=0;
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>a[i];
	for(j=1;j<=m;j++)
	for(i=0;i<n;i++)
	if(j%a[i]==0) b[j]=true;
	for(j=1;j<=m;j++)
	if(!b[j])
	cnt++;
	cout<<cnt;
	return 0;
}

