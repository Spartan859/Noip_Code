#include <bits/stdc++.h>
#define FOR(i,b,c) for(i=b;i<=c;i++)
using namespace std;
int n,k,a[222];
int f[222][222][222];
int ss(int l,int r,int x){
    int as=0,i;
    if(f[l][r][x]!=-1)return f[l][r][x];
    if(l>r)return 0;//����ѹ�ͷ�ˣ��ͷ��� 
    if(l==r)return k-x-1;//���ұ߽���ȵ�ʱ�򣬷��� ���������ȥ��ǰ���� 
    as=x+1<k?ss(l,r,x+1)+1:ss(l+1,r,0);//���������ͽ���ö�� 
    FOR(i,l+1,r)if(a[i]==a[l])
    as=as<ss(l+1,i-1,0)+ss(i,r,k<x+2?k-1:x+1)?as:ss(l+1,i-1,0)+ss(i,r,k<x+2?k-1:x+1);
    //״̬ת�Ʒ���
    f[l][r][x]=as;//������ý����˰� 
    return as;
}
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)cin>>a[i];
	memset(f,-1,sizeof(f));
	cout<<ss(1,n,0);
	return 0;
}
