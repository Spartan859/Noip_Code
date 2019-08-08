#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=2000010;
int f[N],g[N];
char a[N],s[N];
inline void solve(int n) {
    int p=0,la=0;//p(id) p+la(mx)
    for(int i=1;i<=n;i++) {
		int t=(p+la>i?min(p+la-i,f[p+p-i]):1);
		while(i-t&&i+t<=n&&a[i-t]==a[i+t]) ++t;
		cout<<t<<endl;
		f[i]=t,g[i+t-2]=max(g[i+t-2],t-1);
		if(i+t>p+la) p=i,la=t;
    }
}
int main() {
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
    int n,m=0;
    scanf("%d%s",&n,s);
    a[++m]='#';
    for(int i=0;i<n;i++) a[++m]=s[i],a[++m]='#';
    solve(m);
    for(int i=m-1;i;i-=2) g[i]=max(g[i],g[i+2]-2);
    for(int i=2;i<=m;i+=2) printf("%d\n",g[i]);
    return 0;
}
