#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+1;
ll n,sz;
struct node{
	ll l,r; char c;
}tr[N*32];

void buildtr(ll &rt,ll l,ll r){
	rt=++sz;
	if(l==r) return;
	ll mid=l+r>>1;
	buildtr(tr[rt].l)
}
int main(){

}

