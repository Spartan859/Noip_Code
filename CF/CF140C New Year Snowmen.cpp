#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n,r[N];
ll ans[N/3][3],cnt;
ll cntx[N];

struct snm{
	ll sz,num;
	bool operator < (const snm &a) const{
		return num<a.num;
	}
};
multiset<snm> s;
multiset<snm>::iterator it1,it2,it3;
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+n+1);
    for(ll i=1;i<=n;i++){
    	if(!cntx[i]){
    		cntx[i]++;
    		while(r[i]==r[i+1]) cntx[i]++,i++;
    		s.insert((snm){i,cntx[i]});
    		//cout<<i<<endl;
		}
	}
	//for(ll i=1;i<=n;i++) cout<<cntx[i]<<' ';
	//for(it=s.begin();it!=s.end();it++) cout<<(*it).sz<<' ';
	while(1){
		it1=s.begin();
		it2=s.begin();
		it3=s.begin();
		it2++;
		if(it2==s.end()) break;
		//cout<<(*it2).sz<<endl;
		it3++;it3++;
		if(it3==s.end()) break;
		snm tmp1,tmp2,tmp3;
		tmp1=*it1;tmp2=*it2;tmp3=*it3;
		//cout<<tmp1.sz<<' '<<tmp2.sz<<' '<<tmp3.sz<<endl;
		s.erase(s.begin());
		s.erase(s.begin());
		s.erase(s.begin());
		tmp1.num--;tmp2.num--;tmp3.num--;
		ans[++cnt][0]=tmp1.sz;
		ans[cnt][1]=tmp2.sz;
		ans[cnt][2]=tmp3.sz;
		if(tmp1.num) s.insert(tmp1);
		if(tmp2.num) s.insert(tmp2);
		if(tmp3.num) s.insert(tmp3);
	}
	cout<<cnt<<endl;
	for(ll i=1;i<=cnt;i++)
		cout<<r[ans[i][0]]<<' '<<r[ans[i][1]]<<' '<<r[ans[i][2]]<<endl;
	return 0;
}
