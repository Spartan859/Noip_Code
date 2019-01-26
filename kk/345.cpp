#include<iostream>
using namespace std;
bool pss(int n)  
{  
    for (int i=2;i*i<=n; i++)  
        if (n%i==0)  
            return false;  
    return true;  
}
int ss(int x,int y)  
{
	int ans;
	if(x==1) x=2;
    for(int i=x;i<y;i++)
        if(pss(i)==1) ans++;
    return ans;
}
int main(){
	int m;
	cin>>m;
	int a[m+1],b[m+1];
	for(int i=0;i<m;i++) cin>>a[i]>>b[i];
	for(int i=0;i<m;i++) cout<<ss(a[i],b[i])<<' ';
	return 0;
}
