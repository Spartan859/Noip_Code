#include<iostream>
#define N 100005
using namespace std;
bool he[N]={1,1,0};  //ºÏÊıÅĞ¶Ï 
int m,n,a,b,p[N],s[N],cnt=0;  
int main(){  
	n=100000;
    for(int i=2;i<=n;i++){  
        if(!he[i]) p[cnt++]=i;  
        for(int j=0;j<cnt&&p[j]*i<=n;j++) {  
            he[p[j]*i]=1;   
            if(i%p[j]==0) break; 
        }  
    }  
    s[0]=s[1]=0;
    for(int i=2;i<=n;i++) s[i]=s[i-1]+(1-he[i]);
    cin>>m;
    for(int i=0;i<m;i++){
    	cin>>a>>b;
    	cout<<s[b]-s[a-1]<<" ";
    }
    return 0;
}  
