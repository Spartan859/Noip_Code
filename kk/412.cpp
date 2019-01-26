#include<bits/stdc++.h>
#define R 7
using namespace std;
int main(){
	int n,cnt[R]={0},temp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		cnt[temp]++;
	}
	int ans=0;
	for(int i=1;i<=6;i++){
		temp=36/i/i;
		//cout<<temp<<endl;
		//cout<<cnt[i]<<endl;
		ans+=cnt[i]/temp;
		cnt[i]=cnt[i]%temp;
	}
	//for(int i=0;i<=6;i++) cout<<cnt[i]<<endl;
	cout<<ans<<endl;
	while(1){
		if(cnt[5]>=1&&cnt[1]>=11){
			cnt[5]-=1;
			cnt[1]-=11;
			ans++;
		}
		else if(cnt[5]>=1){
			cnt[1]=0;
			cnt[5]-=1;
			ans++;
		}
		else break;
	}
	while(cnt[4]>=1){
		if(cnt[2]>=5){
			cnt[4]-=1;
			cnt[2]-=5;
			ans++;
		}
		if(cnt[4]==0) break;
		if(cnt[1]>=20){
			cnt[4]-=1;
			cnt[1]-=20;
			ans++;
		}
		if(cnt[4]==0) break;
		if(cnt[2]*4<=20){
			cnt[4]-=1;
			cnt[2]=0;
			cnt[1]-=20-cnt[2]*4;
			ans++;
		}
	}
	if(cnt[3]=1){
		cnt[3]-=1;
		cnt[2]-=5;
		cnt[1]-=7;
		ans++;
	}
	else if(cnt[3]=2){
		cnt[3]-=2;
		cnt[2]-=3;
		cnt[1]-=6;
	}
	else if(cnt[3]=3){
		cnt[3]-=3;
		cnt[2]-=1;
		cnt[1]-=5;
	}
    if(cnt[2]>0){
	    cnt[2]=0;
	    cnt[1]-=36-cnt[2]*4;
	    ans++;
	}
	if(cnt[1]>0){
		cnt[1]=0;
		ans++;
	}
	cout<<ans;
	return 0;
}
