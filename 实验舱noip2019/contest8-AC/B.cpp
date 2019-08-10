#include<bits/stdc++.h>
#define md(x) ((x)>=n?((x)-n):(x))
#define N 1000005
#define ll long long
using namespace std;
namespace KMP{
	void GetNext(char* p,ll nxt[]){
		ll plen=strlen(p);
		nxt[0]=-1;
		ll j=0,k=-1;
		while(j<plen-1){
			if(k==-1||p[j]==p[k]){
				++k;++j;
				nxt[j]=k;
				if(p[j]==p[nxt[j]]) nxt[j]=nxt[nxt[j]];
			}else{
				k=nxt[k];
			}
		}
	}
	bool KMP(char* p,char* s){
		ll i=0,j=0;
		ll slen=strlen(s);
		ll plen=strlen(p);
		ll nxt[N*2]={0};
		GetNext(p,nxt);
		while(i<slen&&j<plen)
			if(j==-1||s[i]==p[j]) i++,j++;
			else j=nxt[j];
		if(j==plen) return 1;
		else return 0;
	}
}
namespace MINBSF{
	ll minbsf(char* s){
		ll n=strlen(s);
		ll i=0,j=1,k=0,t;
		while(i<n&&j<n&&k<n){
			t=s[md(i+k)]-s[md(j+k)];
			if(!t) k++;
			else{
				if(t>0) i+=k+1;
				else j+=k+1;
				if(i==j) j++;
				k=0;
			}
		}
		return i<j?i:j;
	}
}
char s[N*2],p[N*2];
ll n,T;
int main(){
	scanf("%lld%lld",&n,&T);
	scanf("%s%s",&s,&p);
	//if(KMP(p,s)) puts("YES");
	//else puts("NO");
	for(ll i=0;i<n;i++) s[i+n]=s[i];//»·²ðÁ´¸´ÖÆÒ»±é
	bool flag=KMP::KMP(p,s);
	if(flag) puts("TAK");
	else puts("NIE");
	if(flag&&T){
		ll pos=MINBSF::minbsf(p);
		for(ll i=pos;i<n;i++) cout<<p[i];
		for(ll i=0;i<pos;i++) cout<<p[i];
		puts("");
	}
	return 0;
}
