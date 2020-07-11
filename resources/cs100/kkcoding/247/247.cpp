#include<iostream>  
#include<algorithm>  
#include<cmath>  
#include<cstring>  
#include<cstdio>  
using namespace std;  
int pri[100005],cnt=0,n,m,a[205],ans[205],tot=0;  
void pre(int x)  
{  
    for(int i=1;i*i<=x;i++)  
    {  
        if(x%i==0)  
        {  
            pri[++cnt]=i;  
            if(x!=i*i)pri[++cnt]=x/i;  
        }  
    }  
}  
int main(){  
    cin>>n>>m;  
    for(int i=1;i<=m;i++)  
    {  
        cin>>a[i];  
        pre(a[i]);  
    }  
    pri[++cnt]=0x7fffffff;  
    sort(pri+1,pri+cnt+1);  
    int t=1;  
    for(int i=1;i<cnt;i++)  
    {  
        if(pri[i]>=n)break;  
        if(pri[i]==pri[i+1])t++;  
        else   
        {  
            ans[t]++;  
            t=1;  
            tot++;  
        }  
    }  
    cout<<n-tot<<endl;;  
    for(int i=1;i<=m;i++)cout<<ans[i]<<endl;  
    return 0;  
}
