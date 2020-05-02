#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAX_N=300005;
int n,Q;
char str[MAX_N];
int A[MAX_N];
int son[MAX_N][26];
int siz=1; 
int ans[MAX_N];
vector<int> tag[MAX_N];
void insert(const char str[],int t)
{
	int cur=0;
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(!son[cur][str[i]-'a'])son[cur][str[i]-'a']=siz++;
		cur=son[cur][str[i]-'a'];
	}
	tag[cur].push_back(t);
}
void unite(vector<int> &v1,vector<int> &v2)
{
	if(v1.size()<v2.size())swap(v1,v2);
	for(int i=0;i<v2.size();i++)
	{
		v1.insert(lower_bound(v1.begin(),v1.end(),v2[i]),v2[i]);
	}
}
vector<int> vec[MAX_N];
void dfs(int v)
{
	vec[v]=tag[v]; 
	for(int i=0;i<26;i++)
	{
		if(son[v][i])
		{
			dfs(son[v][i]);
			unite(vec[v],vec[son[v][i]]);
		}
	}
	for(int i=0;i<tag[v].size();i++)
	{
		int K=tag[v][i];
		if(A[K]-1<vec[v].size())ans[K]=vec[v][A[K]-1];
		else ans[K]=-1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		int len=strlen(str);
		reverse(str,str+len);
		insert(str,i);
	}
	for(int i=1;i<=n;i++)cin>>A[i];
	dfs(0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
	return 0;
}
