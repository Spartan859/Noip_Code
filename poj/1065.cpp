#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;
int ans[100005]={0},cnt=0;
struct Machine
{
	int l, w;
}data[5010];
bool use[5010];
bool operator < (const Machine a, const Machine b)
{
	if(a.l == b.l) return a.w < b.w;
	return a.l < b.l;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(use, 0, sizeof(use));
		int n, count = 0;
		Machine last;
		cin>>n;
		for(int i = 0; i < n; ++i)
		{
			cin>>data[i].l>>data[i].w;
		}
		sort(data, data + n);
		for(int i = 0; i < n; ++i)
		{
			last.w = data[i].w; //记录新序列的开始
			if(!use[i])
			{
				for(int j = i + 1; j < n; j++)
				{
					if(last.w <= data[j].w && !use[j])
					{
						use[j] = 1;
						last.w = data[j].w;
					}
				}
				count++;
			}
		}
		ans[cnt]=count;
		cnt++;
	}
	for(int i=0;i<cnt;i++) cout<<ans[i]<<endl;
	return 0;
}
