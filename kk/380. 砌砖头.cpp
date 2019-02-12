#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll HS=5999997;
ll hcnt,N,H,M,cnt,K;
struct tdat{ll N,H,M,rt;};
vector<tdat> hsh_mp[HS];
ll hsh(ll N,ll H,ll M){
	return ((N*H)%HS+(H*M)%HS+(N*M)%HS)*N%HS*131%HS;
}
bool find_hsh(ll N,ll H,ll M,ll &rt){
	ll h=hsh(N,H,M);
	for(ll i=0;i<hsh_mp[h].size();i++)
		if(hsh_mp[h][i].N==N&&hsh_mp[h][i].H==H&&hsh_mp[h][i].M==M){
			rt=hsh_mp[h][i].rt;
			return 1;
		}
	return 0;	
}
void insert_hsh(ll N,ll H,ll M,ll rt){
	hcnt++;hsh_mp[hsh(N,H,M)].push_back((tdat){N,H,M,rt});
}
ll F(ll N,ll H,ll M){
	ll rt;
	if(find_hsh(N,H,M,rt)) return rt;
	if(M<=0||N<M) return 0;
	if(H==1) return 1;
	rt=F(N-M,H-1,M-1)+F(N-M,H-1,M+1);
	insert_hsh(N,H,M,rt);
	return rt;
}
void print_way(ll k){
	ll cur=M,TN=N,tmp;
	printf("%lld",cur);
	for(ll i=1;i<H;i++){
		TN-=cur;
		tmp=F(TN,H-i,cur-1);
		if(tmp>=k) cur--;
		else{k-=tmp;cur++;}
		printf(" %lld",cur);
	}
	cout<<endl;
}
int main(){
	scanf("%lld %lld %lld %lld",&N,&H,&M,&K);
	cnt=F(N,H,M);
	printf("%lld\n",cnt);
	if(K<=cnt) print_way(K);
	return 0;
}
