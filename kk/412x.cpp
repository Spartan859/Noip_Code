#include<iostream>
using namespace std;
int a[7],n,i,j,t,ans,s;
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t;
		a[t]++;
	}
	ans+=a[6];
	for(i=0;i<a[5];i++){
		ans++;
		a[1]=max(0,a[1]-11);
	}
	for(i=0;i<a[4];i++){
		ans++;
		if(a[2]>=5) a[2]-=5;
		if(a[2]<5){
			a[2]=0;
			a[1]=max(0,a[1]-(5-a[2])*4);
		}
	}
	for(i=0,s=1;i<a[3];i+=4,s=s%4+1){
		if(a[3]-i<4){ 
			for(j=0;j<4-s;j++){ 
			if(a[2]>0){
				a[2]--;
				a[1]=max(0,a[1]-5);
			}
			else a[1]=max(0,a[1]-9);} 
		}
		ans++;
	}
	for(i=0,s=0;i<a[2];i+=9,s%9+1){
		if(a[2]-i<9){
			for(j=0;j<(9-s);j++)a[1]=max(0,a[1]-4); 
		}
		ans++; 
	} 
	for(i=0;i<a[1];i+=36){
		ans++;
	}
	cout<<ans;
}
