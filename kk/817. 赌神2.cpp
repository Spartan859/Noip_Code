#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll M,D,N,ndd,rtd,tmp;
ll gm[55][2],vst[55];//0 needed 1 returned
bool ed;
int main(){
	scanf("%lld %lld %lld",&M,&D,&N);
	for(ll i=1;i<=M;i++){
		scanf("%lld",&ndd);
		rtd=ndd;
		for(ll j=1;j<D;j++){
			scanf("%lld",&tmp);
			rtd=max(rtd,tmp);
		}
		gm[i][0]=ndd;
		gm[i][1]=rtd;
	}
	for(ll i=1;i<=M;i++){
		ed=0;
		for(ll j=1;j<=M;j++){
			if(N>=gm[j][0]&&!vst[j]){
				vst[j]=1;
				N+=gm[j][1]-gm[j][0];
				break;
			}
			if(j==M) ed=1;
		}
		if(ed) break;
	}
	cout<<N<<endl;
	return 0;
}
