#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fi first
#define se second
#define SZ(x) ((int)(x).size())

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

/* --------------- fast io --------------- */ // begin
namespace Fread{
const int SIZE=1<<20;
char buf[SIZE],*S,*T;
inline char getchar(){
	if(S==T){
		T=(S=buf)+fread(buf,1,SIZE,stdin);
		if(S==T)return EOF;
	}
	return *S++;
}
}//namespace Fread
namespace Fwrite{
const int SIZE=1<<20;
char buf[SIZE],*S=buf,*T=buf+SIZE;
inline void flush(){
	fwrite(buf,1,S-buf,stdout);
	S=buf;
}
inline void putchar(char c){
	*S++=c;
	if(S==T)flush();
}
struct _{
	~_(){flush();}
}__;
}//namespace Fwrite

#ifdef ONLINE_JUDGE
	#define getchar Fread::getchar
	#define putchar Fwrite::putchar
#endif

template<typename T>inline void read(T& x){
	x=0;int f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+(c-'0'),c=getchar();
	x*=f;
}
template<typename T>inline void write(T x,bool _enter=0,bool _space=0){
	if (!x)putchar('0');else{
		if(x<0)putchar('-'),x=-x;
		static char dig[41];
		int top=0;
		while(x)dig[++top]=(x%10)+'0',x/=10;
		while(top)putchar(dig[top--]);
	}
	if(_enter)putchar('\n');
	if(_space)putchar(' ');
}

namespace Fastio{
struct reader{
	template<typename T>reader& operator>>(T& x){::read(x);return *this;}
	reader& operator>>(char& c){
		c=getchar();
		while(c=='\n'||c==' ')c=getchar();
		return *this;
	}
	reader& operator>>(char* str){
		int len=0;
		char c=getchar();
		while(c=='\n'||c==' ')c=getchar();
		while(c!='\n'&&c!=' ')str[len++]=c,c=getchar();
		str[len]='\0';
		return *this;
	}
}cin;
const char endl='\n';
struct writer{
	template<typename T>writer& operator<<(T x){::write(x,0,0);return *this;}
	writer& operator<<(char c){putchar(c);return *this;}
	writer& operator<<(const char* str){
		int cur=0;
		while(str[cur])putchar(str[cur++]);
		return *this;
	}
}cout;
}//namespace Fastio
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl
/* --------------- fast io --------------- */ // end

const int MAXN=2e6;
int m,vals[MAXN+5],cnt_val;
struct Event{
	int op,t,x,y;
}ev[MAXN+5];

struct FenwickTree{
	int sz;
	int fire[MAXN+5],ice[MAXN+5],delta_fire;
	void modify_ice(int pos,int val){
		//后缀加 -> 单点加,查询时查前缀和
		for(int p=pos;p<=sz;p+=(p&(-p))){
			ice[p]+=val;
		}
	}
	void modify_fire(int pos,int val){
		//前缀加 -> 后缀减,总偏移量加
		delta_fire+=val;
		for(int p=pos+1;p<=sz;p+=(p&(-p))){
			fire[p]-=val;
		}
	}
	int query_min(int pos){//min(ice,fire)
		int ice_sum=0,fire_sum=delta_fire;
		for(int p=pos;p;p-=(p&(-p))){
			ice_sum+=ice[p];
			fire_sum+=fire[p];
		}
		return min(ice_sum,fire_sum);
	}
	int find1(){
		//最后一个ice-fire<0的位置
		int p=0,s=-delta_fire;
		for(int i=20;i>=0;--i){
			if(p+(1<<i)>sz)continue;
			int nxt=s+(ice[p+(1<<i)]-fire[p+(1<<i)]);
			if(nxt<0){
				s=nxt;
				p+=(1<<i);
			}
		}
		return p;
	}
	int find2(int goal_min){
		//最后一个min(ice,fire)=val的位置
		int p=0,ice_sum=0,fire_sum=delta_fire;
		for(int i=20;i>=0;--i){
			if(p+(1<<i)>sz)continue;
			int new_ice=ice_sum+ice[p+(1<<i)];
			int new_fire=fire_sum+fire[p+(1<<i)];
			if(new_ice<new_fire){
				ice_sum=new_ice;
				fire_sum=new_fire;
				p+=(1<<i);
			}
			else{
				assert(min(new_ice,new_fire)<=goal_min);
				if(min(new_ice,new_fire)==goal_min){
					ice_sum=new_ice;
					fire_sum=new_fire;
					p+=(1<<i);
				}
			}
		}
		return p;
	}
	void resize(int _sz){sz=_sz;}
	FenwickTree(){}
}T;

int main() {
	//freopen("icefire.in","r",stdin);
	//freopen("icefire.out","w",stdout);
	cin>>m; 
	for(int i=1;i<=m;++i){
		cin>>ev[i].op;
		if(ev[i].op==1){
			cin>>ev[i].t>>ev[i].x>>ev[i].y;
			vals[++cnt_val]=ev[i].x;
		}
		else{
			int j;cin>>j;
			ev[i].t=ev[j].t;
			ev[i].x=ev[j].x;
			ev[i].y=-ev[j].y;
		}
	}
	sort(vals+1,vals+cnt_val+1);
	cnt_val=unique(vals+1,vals+cnt_val+1)-(vals+1);
	for(int i=1;i<=m;++i){
		ev[i].x=lob(vals+1,vals+cnt_val+1,ev[i].x)-vals;
		//cout<<ev[i].x<<endl;
	}
	T.resize(cnt_val);
	for(int i=1;i<=m;++i){
		if(ev[i].t==0)
			T.modify_ice(ev[i].x,ev[i].y);
		else
			T.modify_fire(ev[i].x,ev[i].y);
		/*
		//暴力
		pii res=mk(-1,-1);
		for(int j=1;j<=cnt_val;++j){
			res=max(res,mk(T.query_min(j),j));
		}
		*/
		int p1=T.find1();
		pii res1=mk(-1,-1);
		if(p1>0){
			res1=mk(T.query_min(p1),p1);
		}
		pii res2=mk(-1,-1);
		if(p1<cnt_val){
			int goal_min=T.query_min(p1+1);
			int p2=T.find2(goal_min);
			//assert(p2>=p1+1);
			//assert(T.query_min(p2)==goal_min);
			//assert(p2==cnt_val||T.query_min(p2+1)<goal_min);
			res2=mk(goal_min,p2);
		}
		pii res=max(res1,res2);
		
		if(res.fi==0)
			cout<<"Peace"<<endl;
		else
			cout<<vals[res.se]<<" "<< res.fi*2<<endl;
	}
	return 0;
}
