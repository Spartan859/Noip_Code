#include <bits/stdc++.h>
using namespace std;
const int MAX_N=3005,MAX_M=200005;
int n,m;
int A[MAX_N],B[MAX_N];
bool is_prime[MAX_M];
void init(){
	static int len,data[MAX_N];
	cin>>len;
	for(int i=1;i<=len;i++)cin>>data[i];
	bool flag=false;
	for(int i=1;i<=len;i++)
	{
		if(data[i]==1 && flag==false)
		{
			A[++n]=data[i];
			flag=true;
		}
		if(data[i]>1 && data[i]%2==1)A[++n]=data[i];
		if(data[i]%2==0)B[++m]=data[i];
	}
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0]=is_prime[1]=false;
	int top=200000;
	for(int i=2;i<=top;i++)
	{
		if(!is_prime[i])continue;
		for(int j=i+i;j<=top;j+=i)is_prime[j]=false;
	}
}
vector<int> g[MAX_N];
int match[MAX_N];
bool used[MAX_N];
bool dfs(int v)
{
	used[v]=true;
	for(int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if(match[to]<0 || !used[match[to]] && dfs(match[to]))
		{
			match[to]=v;
			return true;
		}
	}
	return false;
}
int bipartite_matching()
{
	memset(match,-1,sizeof(match));
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		memset(used,false,sizeof(used));
		ret+=dfs(i);
	}
	return ret;
}
int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(is_prime[A[i]+B[j]])g[i].push_back(j);
		}
	}
	cout<<n+m-bipartite_matching()<<endl;
	return 0;
}
