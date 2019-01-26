#include<iostream>
#include<algorithm>
#include<cmath>
#define ERR 0.000001
#define N 4005
using namespace std;
struct point{double pos; int tag;};//tag正负1代表左右端点 
bool cmp(const point&a,const point&b){
	return a.pos+ERR<b.pos||fabs(a.pos-b.pos)<ERR&&a.tag<b.tag;//pos从小到大（精确度！），tag从小到大（-1优先） 
}
point d[N];
int main(){
	int n,cnt=0,ans=0; double p;
	cin>>n;
	for(int i=0;i<n+n;i+=2){
		cin>>p;
		d[i].pos=p-55; d[i+1].pos=p+55;
		d[i].tag=1;
		d[i+1].tag=-1;
		//d[+1]就是一条线段！左+1，右-1 
		//本函数内为初始化阶段 
	}
	sort(d,d+n*2,cmp);
	//for(int i=0;i<n+n;i++) cout<<d[i].pos<<' '<<d[i].tag<<' '<<endl;
	for(int i=0;i<n+n;i++){
		cnt+=d[i].tag;
		ans=max(ans,cnt);
		//cnt计数器，求i端点上的重叠
		//此函数内为计数阶段 
	}
	cout<<ans<<endl;
	return 0;
}
