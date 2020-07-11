#include<bits/stdc++.h>

#define int long long

using namespace std;

int l,r,trg,pla;
int f[]={0,1,3,7,7,9}; //前5个要特判 
queue <int> q; 

inline void getque()
{
	int nownum,nowf;  // nownum : 现在处理到的数字，nowf: 现在f(nownum) 
	int jmp;  //一次跳跃的距离 
	int nowlas=2ll,nowlen=2ll,lasf;  // nowlas 现在这次 
	int lker=0;
	int lasnum=5ll;
	nowf=9ll;
	for(int i=1;i<=5;i++) if(l<=i&&r>=i) q.push(f[i]);
	nownum=5ll;
	if(r<=5) return ;
	while(nownum<=r)
	{
		while(nowlas>=0)
		{
			if(nowlas==0) jmp=1;
			else jmp=1ll<<(nowlen-nowlas);  //一定要加ll，不然会被认为是32位的位运算，让你TLE 60分 
			lasnum=nownum;
			nownum+=jmp;
			if(nownum==r) //注意相等的时候要特殊处理 
			{
				lasf=nowf;
				nowf+=1ll<<nowlas;
				if(nowlas==0) nowf++;
				break;
			}
			else if(nownum>r) break;
			lasf=nowf;
			nowf+=1ll<<nowlas;
			if(nowlas==0) nowf++;
			if(nowlas==1||nowlas==0) 
			{
				if(nownum>=l&&nownum<=r)   //符合条件才能放入队列里面 
				{
					q.push(nowf);
				}
			} 
			if(!lker&&nownum>l)  //这里并不能写else，尤其要注意。 
			{
				lker=1;
				if((nownum-l)&1ll) q.push(lasf);
			}
			nowlas--; 
		}
		if(nownum>=r) 
		{
			if(nownum==r) q.push(nowf);
			else if(nowlas>=1) if((nownum-r+1)&1ll) q.push(nowf); 
			else if(!lker) if((r-l+1)&1) q.push(nowf);  //注意判断的顺序； 
			break;
		}
		nowlen++;
		nowlas=nowlen;
	}
	return ;
}

signed main()
{
	ios::sync_with_stdio(false);
	register int i,j;
	cin>>l>>r;
	getque();
	int looker=q.front();
	q.pop();
	while(!q.empty())
	{
		int looker2=q.front();
		q.pop();
		looker^=looker2;
	}
	cout<<looker;
	return 0;
}
