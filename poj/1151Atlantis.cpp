#include <cstdio>
#include <algorithm>
using namespace std;
#define db double
#define maxn 1010

int T,n,t=0,tt; db Y[maxn];
struct edge{db x,y1,y2;int type;}a[maxn];
bool cmp(edge x,edge y){return x.x<y.x;}
struct node{
	db l,r,z;int cover;node *zuo,*you;
	node(int x,int y):l(Y[x]),r(Y[y]),cover(0),z(0){
		if(y-x>1)zuo=new node(x,x+y>>1),you=new node(x+y>>1,y);
		else zuo=you=NULL;
	}
	void pushup(){
		if(cover)z=r-l;else if(!zuo)z=0;
		else z=zuo->z+you->z;
	}
	void change(db x,db y,int z)
	{
		if(l==x&&r==y){cover+=z;pushup();return;}
		if(y<=zuo->r)zuo->change(x,y,z);
		else if(x>=you->l)you->change(x,y,z);
		else zuo->change(x,zuo->r,z),you->change(you->l,y,z);
		pushup();
	}
}*root;

int main()
{
	while(scanf("%d",&n),n!=0)
	{
		T++;t=0;for(int i=1;i<=n;i++)
		{
			db x,y,xx,yy;
			scanf("%lf %lf %lf %lf",&x,&y,&xx,&yy);
			a[++t]=(edge){x,y,yy,1}; Y[t]=y;
			a[++t]=(edge){xx,y,yy,-1}; Y[t]=yy;
		}
		sort(a+1,a+t+1,cmp);sort(Y+1,Y+t+1);
		tt=unique(Y+1,Y+t+1)-(Y+1);root=new node(1,tt);
		db ans=0;for(int i=1;i<=t;i++){
			ans+=(a[i].x-a[i-1].x)*root->z;
			root->change(a[i].y1,a[i].y2,a[i].type);
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n",T,ans);
	}
}
