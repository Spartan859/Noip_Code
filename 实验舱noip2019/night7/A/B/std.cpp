#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=1000010;
char s[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?o=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline bool check(int l,int r) {
    while(l<r)
	if(s[l++]!=s[r--]) return 0;
    return 1;
}
int main() {
    freopen("B.in","r",stdin);
    freopen("std.out","w",stdout);
    int n,j;
    cin>>n;
    scanf("%s",s);
    for(int i=0;i<n;i++) {
	for(j=0;j<=i;j++)
	    if(check(j,i)) break;
	printf("%d\n",i-j+1);
    }
    return 0;
}
