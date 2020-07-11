#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define N 100005
#define M 4
#define tot 1
using namespace std;

struct Matrix{
    int a[M][M];
    Matrix() {}
    Matrix(int val){
        memset(a,0,sizeof a);
        for(int i=0;i<=tot;i++)
            a[i][i]=val;
    }
    friend Matrix operator * (Matrix x,Matrix y){
        Matrix z(0);
        for(int i=0;i<=tot;i++)
            for(int j=0;j<=tot;j++)
                for(int k=0;k<=tot;k++)
                    (z.a[i][j]+=(ll)x.a[i][k]*y.a[k][j]%MOD)%=MOD;
        return z;
    }
}mat[N*8];

inline void update(int o) {
    mat[o] = mat[o << 1] * mat[o << 1 | 1];
}
void build(int o, int l, int r) {
    if (l == r) {
        mat[o].a[0][0]=1;mat[o].a[0][1]=1;
        mat[o].a[1][0]=1;mat[o].a[1][1]=0;
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    update(o);
}
void modify(int o, int l, int r, int p, int v) {
    if (l == r) {
        mat[o].a[0][0] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) modify(o << 1, l, mid, p, v);
    else modify(o << 1 | 1, mid + 1, r, p, v);
    update(o);
}
Matrix query(int o, int lb, int rb, int l, int r) {
    if (l <= lb && r >= rb) return mat[o];
    int mid = (lb + rb) >> 1;
    if (l <= mid && r > mid)
        return query(o << 1, lb, mid, l, r) * query(o << 1 | 1, mid + 1, rb, l, r);
    else {
        if (l <= mid) return query(o << 1, lb, mid, l, r);
        else return query(o << 1 | 1, mid + 1, rb, l, r);
    }
}

int n,k;
int x[N],y[N];
Matrix st(0);
int main(){
	//freopen("eruda.in","r",stdin);
	//freopen("eruda.out","w",stdout);
	st.a[0][0]=1;st.a[0][1]=1;
	scanf("%d%d",&n,&k);
	build(1,1,n);
	for(int i=1;i<=k;i++){
		scanf("%d%d",x+i,y+i);
		modify(1,1,n,x[i],y[i]);
		if(x[i]<=2) putchar('1'),putchar(' ');
		else{
			int ans=(st*query(1,1,n,3,x[i])).a[0][0];
			printf("%d ",ans);
		}
	}
	return 0;
}
