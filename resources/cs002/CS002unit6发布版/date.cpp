#include<iostream>
using namespace std;
int i,y,m,d,ans;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	cin>>y>>m>>d;
	for(i=1;i<m;i++)
		ans+=a[i];
	ans+=d;
	if(y%4==0 && y%100!=0 || y%400==0)
		if(m>2) ans++;
	cout<<ans;
	return 0;
}
