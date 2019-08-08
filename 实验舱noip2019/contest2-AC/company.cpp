#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inf 1000000000
using namespace std;
int read()
{
    int f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int N,M,Q,root,start;
int opt[100005],x[100005],y[100005];//cmd
int ls[200005],rs[200005],d[200005],A[100005];//leftson rightson 为找根  运行的指令 
int tag[200005],ans[200005]; 
bool zero[200005],mul[200005],add[200005];//
void dp(int x)
{
	if(!ls[x])return;
	dp(ls[x]);dp(rs[x]);
	mul[x]|=(mul[ls[x]]|mul[rs[x]]); 
	zero[x]|=(zero[ls[x]]|zero[rs[x]]);//以x为根的子树中有木有*0的 
	add[x]|=(add[ls[x]]|add[rs[x]]); 
}
void pushdown(int x)
{
	int l=ls[x],r=rs[x];
	tag[l]+=tag[x];
	tag[r]+=tag[x];
	tag[x]=0;
}
void solve(int k)
{
	if(!ls[k])
	{
		if(opt[k]==1)ans[x[k]]+=tag[k]*y[k];
		else if(tag[k])
			for(int i=1;i<=Q;i++)
				ans[i]*=x[k];
		tag[k]=0;
		return;
	}
	pushdown(k);
	solve(ls[k]);solve(rs[k]);
}
int main()
{
	N=read();M=read();Q=read();
	for(int i=1;i<=N;i++)
	{
		opt[i]=read();
		if(opt[i]==1)
		{
			x[i]=read(),y[i]=read();
			if(y[i])add[i]=1;
		}
		else 
		{
			x[i]=read();
			if(x[i]==1)opt[i]=1;
			else 
			{
				mul[i]=1;
				if(x[i]==0)zero[i]=1;
			}
		}
	}
	for(int i=N+1;i<2*N;i++)
	{
		ls[i]=read(),rs[i]=read();
		d[ls[i]]++;d[rs[i]]++;
	}
	for(int i=N+1;i<2*N;i++)
		if(!d[i])root=i;
	dp(root);
	for(int i=1;i<=M;i++)A[i]=read();
	start=1;
	for(int i=1;i<=M;i++)
		if(zero[A[i]])start=i;
	bool flag=0;
	for(int i=start;i<=M;i++)
	{
		if(zero[A[i]]){
			solve(A[i]);
			for(int i=1;i<=Q;i++) if(ans[i]>0){
				flag=1;break;
			}
			continue;
		}
		
		if(add[A[i]])
		{
			flag=1;
		}
		
		if(mul[A[i]])
		{
			if(!flag) continue; //还是0，没必要乘 
			solve(root);
			tag[A[i]]=1;
			solve(A[i]);
		}
		else tag[A[i]]++;
	}
	solve(root);
	for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
	return 0;
}
