#include<bits/stdc++.h>

#define int long long

using namespace std;

int l,r,trg,pla;
int f[]={0,1,3,7,7,9}; //ǰ5��Ҫ���� 
queue <int> q; 

inline void getque()
{
	int nownum,nowf;  // nownum : ���ڴ��������֣�nowf: ����f(nownum) 
	int jmp;  //һ����Ծ�ľ��� 
	int nowlas=2ll,nowlen=2ll,lasf;  // nowlas ������� 
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
			else jmp=1ll<<(nowlen-nowlas);  //һ��Ҫ��ll����Ȼ�ᱻ��Ϊ��32λ��λ���㣬����TLE 60�� 
			lasnum=nownum;
			nownum+=jmp;
			if(nownum==r) //ע����ȵ�ʱ��Ҫ���⴦�� 
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
				if(nownum>=l&&nownum<=r)   //�����������ܷ���������� 
				{
					q.push(nowf);
				}
			} 
			if(!lker&&nownum>l)  //���ﲢ����дelse������Ҫע�⡣ 
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
			else if(!lker) if((r-l+1)&1) q.push(nowf);  //ע���жϵ�˳�� 
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
