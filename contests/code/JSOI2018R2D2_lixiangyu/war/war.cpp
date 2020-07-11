#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
struct nd{
    ll x,y;
    nd operator - (nd A){
		return (nd){x-A.x,y-A.y};
	}
    nd operator + (nd A){
		return (nd){x+A.x,y+A.y};
	}
    ll operator * (nd A)const{
		return x*A.y-y*A.x;
	}
    ll len() const{
		return x*x+y*y;
	}
}fwxl[N],PP1[N],PP2[N],s1[N],s2[N],bs;
bool cmp1(const nd &a,const nd &b){
	return a.y<b.y||(a.y==b.y&&a.x<b.x);
}
bool cmp2(const nd &a,const nd &b){
	return a*b>0||(a*b==0&&a.len()<b.len());
}
ll n,m,q,tot;
ll sta[N],top;
void tubao(nd *A,ll &n){
    sort(A+1,A+n+1,cmp1);
    bs=A[1];sta[top=1]=1;
    for(ll i=1;i<=n;i++) A[i]=A[i]-bs;
    sort(A+2,A+n+1,cmp2);
    for(ll i=2;i<=n;sta[++top]=i,i++)
        while(top>=2&&(A[i]-A[sta[top-1]])*(A[sta[top]]-A[sta[top-1]])>=0) top--;
    for(ll i=1;i<=top;i++) A[i]=A[sta[i]]+bs;
    n=top;A[n+1]=A[1];
}
void getfw(){
    for(ll i=1;i<n;i++) s1[i]=PP1[i+1]-PP1[i];
	s1[n]=PP1[1]-PP1[n];
    for(ll i=1;i<m;i++) s2[i]=PP2[i+1]-PP2[i];
	s2[m]=PP2[1]-PP2[m];
    tot=1;
    fwxl[1]=PP1[1]+PP2[1];
	///////////////////////
    ll p1=1,p2=1;
    while(p1<=n&&p2<=m){
    	tot++;
    	fwxl[tot]=fwxl[tot-1]+(s1[p1]*s2[p2]>=0?s1[p1++]:s2[p2++]);
	}
    while(p1<=n){
    	tot++;
    	fwxl[tot]=fwxl[tot-1]+s1[p1++];
	}
    while(p2<=m){
    	tot++;
		fwxl[tot]=fwxl[tot-1]+s2[p2++];
	}
}
inline ll infw(nd a){
    if(a*fwxl[1]>0||fwxl[tot]*a>0)
		return 0;
    ll ps=lower_bound(fwxl+1,fwxl+tot+1,a,cmp2)-fwxl-1;
    return (ll)((a-fwxl[ps])*(fwxl[ps%tot+1]-fwxl[ps])<=0);
}
int main(){
	freopen("war.in","r",stdin);
	freopen("war.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&q);
    for(ll i=1;i<=n;i++)
        scanf("%lld%lld",&PP1[i].x,&PP1[i].y);
    tubao(PP1,n);
    for(ll i=1;i<=m;i++){
        scanf("%lld%lld",&PP2[i].x,&PP2[i].y);
        PP2[i].x=-PP2[i].x;
		PP2[i].y=-PP2[i].y;
    }
    
    tubao(PP2,m);
    getfw();tubao(fwxl,tot);
    bs=fwxl[1];
	for(ll i=tot;i>=1;i--) fwxl[i]=fwxl[i]-fwxl[1];
	
    while(q--){
        scanf("%lld%lld",&fwxl[0].x,&fwxl[0].y);
        printf("%lld\n",infw(fwxl[0]-bs));
    }
    return 0;
}
