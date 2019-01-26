#include<iostream>
using namespace std;
int a[1000];
int main(){
	int l,r,i,k,len=0;
	cin>>l>>r>>k;
	for(i=l;i<=r;i++){
		int x=i;
		while(x){
			if(x%10==k){
				a[len++]=i;
				break;
			}
			x/=10;
		}
	}
	for(i=0;i<len;i++)
	cout<<a[i]<<",";
	return 0;
}
