#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=100005,INF=1e9,M=4,tot=1;
ll n,k;
ll val[N]; 
struct Matrix{
    ll a[M][M];
    Matrix() {}
    Matrix(ll val){
        memset(a,0,sizeof a);
        for(ll i=0;i<=tot;i++)
            a[i][i]=val;
    }
    void ms(){//È«²¿Ë¢³É-INF 
    	memset(a,128,sizeof(a));
	}
    friend Matrix operator * (Matrix x,Matrix y){
        Matrix z;
		z.ms();
        for(ll i=0;i<=tot;i++)
            for(ll j=0;j<=tot;j++)
                for(ll k=0;k<=tot;k++)
                    z.a[i][j]=max(z.a[i][j],x.a[i][k]+y.a[k][j]);
        return z;
    }
}mat[N*4];

inline void update(ll o) {
    mat[o] = mat[o << 1] * mat[o << 1 | 1];
}
void build(ll o, ll l, ll r) {
    if (l == r) {
        mat[o].a[0][0]=val[l];mat[o].a[0][1]=-INF;
        mat[o].a[1][0]=val[l];mat[o].a[1][1]=0;
        return;
    }
    ll mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    update(o);
}
void modify(ll o, ll l, ll r, ll p, ll v) {
    if (l == r) {
        mat[o].a[0][0] = mat[o].a[1][0]=v;
        return;
    }
    ll mid = (l + r) >> 1;
    if (p <= mid) modify(o << 1, l, mid, p, v);
    else modify(o << 1 | 1, mid + 1, r, p, v);
    update(o);
}
Matrix query(ll o, ll lb, ll rb, ll l, ll r) {
    if (l <= lb && r >= rb) return mat[o];
    ll mid = (lb + rb) >> 1;
    if (l <= mid && r > mid)
        return query(o << 1, lb, mid, l, r) * query(o << 1 | 1, mid + 1, rb, l, r);
    else {
        if (l <= mid) return query(o << 1, lb, mid, l, r);
        else return query(o << 1 | 1, mid + 1, rb, l, r);
    }
}
ll f[N];
Matrix st(0);
int main(){
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++) scanf("%lld",val+i);
	build(1,1,n);
	//st.a[1][0]=-INF;
	/*cout<<endl;
	for(ll i=1;i<=n;i++){
		printf("%lld ",(st*query(1,1,n,1,i)).a[0][0]);
	}*/
	for(ll i=1,x,y;i<=k;i++){
		scanf("%lld%lld",&x,&y);
		modify(1,1,n,x,y);
		printf("%lld ",(st*query(1,1,n,1,x)).a[0][0]);
	}
	return 0;
}

