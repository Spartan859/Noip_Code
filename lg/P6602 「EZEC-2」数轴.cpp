#include<bits/stdc++.h>
using namespace std;
#define G() Cr=getchar()
int Xr;char Cr;
inline int rd(){
    Xr = 0, G();
    while(Cr < '0' || Cr > '9') G();
    while(Cr >= '0' && Cr <= '9') Xr = (Xr<<3) + (Xr<<1) + (Cr & 15), G();
    return Xr;
}
#define MAX_N 1000005
int n, m, k;
int ans[MAX_N];
int num[MAX_N], pos[MAX_N], cnt;
int l[MAX_N], r[MAX_N];
int ma = -1, s, t;
struct node{
	int x, a;
} e[MAX_N];
int x[MAX_N], a[MAX_N];
map<int,int>mp;

bool comp(node x,node y){
	return x.x < y.x;
}

int main(){
    n = rd(), m = rd(), k = rd();
    for(int i = 1; i <= n; i++) {
    	e[i].x = rd(), e[i].a = rd();
    	x[i] = e[i].x, a[i] = e[i].a;
	}
	e[n+1].x = -1;
	sort(e+1,e+2+n,comp);
	for(int i = 1; i <= n + 1; i++) {
		if(e[i].x != pos[cnt]) pos[++cnt] = e[i].x;
		mp[e[i].x] = cnt;
	}
	pos[cnt+1] = m + 1;
	for(int i = 1; i <= n; i++) num[mp[x[i]]] += a[i];
	for(int i = 1; i <= cnt; i++) {
		s -= num[i];
		while(s + num[t+1] <= k && t < cnt) t++, s += num[t];
		ma = max(ma, pos[t+1] - pos[i] - 2);
		l[i] = i - 1, r[i] = i + 1;
	}
	ans[n] = ma;
	for(int i = n; i >= 2; i--) {
		int p = mp[x[i]];
		num[p] -= a[i];
		if(!num[p]) r[l[p]] = r[p], l[r[p]] = l[p];
		t = p;
		int j = p;
		s = num[t];
		while(j > 1 && s <= k) j = l[j], s += num[j];
		for(j; j < p; j = r[j]) {
			s -= num[j];		
			while(s + num[r[t]] <= k && r[t] <= cnt) t = r[t], s += num[t];
			ma = max(ma, pos[r[t]] - pos[j] - 2);
		}
		ans[i-1] = ma;
	}
	for(int i = 1; i <= n; i++) printf("%d\n",ans[i]);
}
