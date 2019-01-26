#include<bits/stdc++.h>
using namespace std;
int n=0,a[100005]={0},c[10001]={0}; int k=0;
void count_sort(int *a,int n,int k)  
{  
    int * c=new int[k+1];  
    int * b=new int[n+1];  
    int i;  
    for (i=1;i<=k;i++)  
    {  
        c[i]=c[i]+c[i-1];  
    }
    for (int j=n;j>=1;j--)  
    {  
        b[c[a[j]]]=a[j];  
        c[a[j]]--;  
    }  
    for(i=1;i<=n;i++)  
        a[i]=b[i];  
}  
int main(){
	int j=0,temp=0;
	
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    c[a[i]]++;
	}
	cin>>k;
	temp=*max_element(a,a+n)+1;
	
	if(k==1){cout<<temp-1<<endl; return 0;}
	
	
	count_sort(a,n,temp);
	cout<<"an:"<<' '<<a[n]<<endl;
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<endl;
	while(1){//iÃëÊý
	    c[a[n]]--;
		a[n]-=k-1;
		if(a[n]>0) c[a[n]]++;
		else c[0]++;
		if(a[n-1]>a[n]) count_sort(a,n,temp);
		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<endl;
		if(a[n]-j<=0) break;
	}
	cout<<j<<endl;
	return 0;
}
