#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,L,K,id[10],y[105][1005],ans,tmp,cpy[105][1005];
bool okk=1;
ll _find(ll y){
	return id[y]==y?y:id[y]=_find(id[y]);
}
string x[105];
void dfs(ll a,ll b){
	ll fi=0,fj=0;
	K--;
	ll fa=_find(a),fb=_find(b);
	id[fa]=fb;
	if(K==0){
		for(ll i=1;i<=n;i++)
			for(ll j=0;j<L;j++) cpy[i][j]=y[i][j];
		for(ll i=1;i<=n;i++)
			for(ll j=0;j<L;j++)
				cpy[i][j]=_find(cpy[i][j]);
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++){
				for(ll k=0;k<L;k++) if(cpy[i][k]!=cpy[j][k]){okk=0;break;} 
				if(okk) tmp++;
				okk=1;
			}
		ans=max(ans,tmp);
		tmp=0;		
	}
	else{
		for(ll i=1;i<=8;i++)
			for(ll j=i+1;j<=8;j++){
				fi=_find(i);fj=_find(j);
				if(fi!=fj) dfs(i,j);
			}
	}
	
	K++;
	id[fa]=fa;
}
int main(){
	//freopen
	cin>>n>>L>>K;
	for(ll i=1;i<=n;i++){
		cin>>x[i];
		for(ll j=0;j<L;j++) y[i][j]=x[i][j]-'a'+1;
	}
	for(ll i=1;i<=8;i++) id[i]=i;
	for(ll i=1;i<=8;i++)
		for(ll j=i+1;j<=8;j++) dfs(i,j);
	cout<<ans<<endl;
	return 0;
}
