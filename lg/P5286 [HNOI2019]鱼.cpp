#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define RL Reg LL
#define Con const
#define CI Con int&
#define CL Con LL&
#define I inline
#define W while
#define N 1000
#define LL long long
#define DB long double
#define eps 1e-10
#define swap(x,y) (x^=y^=x^=y)
using namespace std;
int n,val[N+5][N+5];Con DB Pi=acos(-1); 
Tp I Ty gcd(Con Ty& x,Con Ty& y) {return y?gcd(y,x%y):x;}
struct Fr
{
	LL x,y;I Fr(CL a=0,CL b=1) {RL g=gcd(a,b);x=a/g,(y=b/g)<0&&(x=-x,y=-y);}
	I bool operator != (Con Fr& o) Con {return x^o.x||y^o.y;}
	I bool operator < (Con Fr& o) Con {return x^o.x?x<o.x:y<o.y;}
};
struct Line
{
	Fr Slope,Incre;I Line(Con Fr& s=Fr(),Con Fr& i=Fr()):Slope(s),Incre(i){}
	I bool operator < (Con Line& o) Con {return Slope!=o.Slope?Slope<o.Slope:Incre<o.Incre;}//用于区分
};
struct Point 
{
	#define Dot(A,B) (1LL*(A).x*(B).x+1LL*(A).y*(B).y)//点积
	#define Cro(A,B) (1LL*(A).x*(B).y-1LL*(A).y*(B).x)//叉积
	#define Len(A) Dot(A,A)
	int x,y;I Point(CI a=0,CI b=0):x(a),y(b){}
	I Point operator + (Con Point& o) Con {return Point(x+o.x,y+o.y);}//点相加
	I Point operator - (Con Point& o) Con {return Point(x-o.x,y-o.y);}//点相减
}p[N+5];
struct Data
{
	int pos;DB ang;I Data(CI p=0,Con DB& a=0):pos(p),ang(a){}
	I bool operator < (Con Data& o) Con {return ang<o.ang;}
}s[N<<1];
map<Line,int> pos;vector<int> v[N*N+5];map<LL,int> cnt;
int main()
{
	RI i,j,x,y,z,tot,Pc=0,H,T;RL ans=0;Line w;Point t;
	for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d%d",&x,&y),p[i]=Point(x,y);
	for(i=1;i<=n;++i) for(j=i+1;j<=n;++j)
	{
		if(p[i].y==p[j].y)
		{
			w=Line(Fr(1,0),Fr(p[i].x+p[j].x,2)),
			v[pos.count(w)?pos[w]:pos[w]=++Pc].push_back(p[i].y<<1);
			continue;
		}
		t=p[j]-p[i],w=Line(Fr(-t.x,t.y),Fr(Dot(t,p[i]+p[j]),2LL*t.y)),
		v[pos.count(w)?pos[w]:pos[w]=++Pc].push_back(p[i].x+p[j].x);
	}
	for(i=1;i<=Pc;++i) sort(v[i].begin(),v[i].end());
	for(i=1;i<=n;++i)//D 
	{
		for(tot=0,j=1;j<=n;++j) i^j&&(s[++tot]=Data(j,atan2(p[j].y-p[i].y,p[j].x-p[i].x)),0);//存下极角
		for(sort(s+1,s+n),j=1;j^n;++j) (s[j+n-1]=s[j]).ang+=2*Pi;
		for(cnt.clear(),tot=H=T=0,j=1;j^n;++j)
		{
			W(s[T+1].ang<s[j].ang+1.5*Pi-eps) ++T,tot+=cnt[Len(p[s[T].pos]-p[i])]++;
			W(s[H+1].ang<s[j].ang+0.5*Pi+eps) ++H,tot-=--cnt[Len(p[s[H].pos]-p[i])];
			val[s[j].pos][i]=tot;
		}
	}
	for(i=1;i<=n;++i) for(j=i+1;j<=n;++j)//枚举AD
	{
		p[i].x^p[j].x?(x=p[i].x,y=p[j].x):(x=p[i].y,y=p[j].y),x>y&&swap(x,y),t=p[i]-p[j],
		w=(p[i].x^p[j].x?Line(Fr(t.y,t.x),Fr(Cro(t,p[i]),t.x)):Line(Fr(1,0),Fr(p[i].x,1))),//求出解析式
		#define UB(x) upper_bound(v[z].begin(),v[z].end(),x)
		pos.count(w)&&(z=pos[w],ans+=(UB((y<<1)-1)-UB(x<<1))*(val[i][j]+val[j][i]));
	}return printf("%lld",ans<<2),0;
}
