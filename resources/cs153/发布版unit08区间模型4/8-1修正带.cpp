#include<iostream>
#include<algorithm>
#define N 2005
using namespace std;
struct point{int pos,tag;};//tag����1�������Ҷ˵� 
bool cmp(const point&a,const point&b){
	return a.pos<b.pos||a.pos==b.pos&&a.tag>b.tag;//pos��С����tag�Ӵ�С��+1���ȣ� 
}
point d[N];
int main(){
	int n,cnt=0,ans=0;
	cin>>n; 
	for(int i=0;i<n+n;i+=2){
		cin>>d[i].pos>>d[i+1].pos;
		d[i].tag=1;
		d[i+1].tag=-1;
		//d[+1]����һ���߶Σ���+1����-1 
		//��������Ϊ��ʼ���׶� 
	}
	sort(d,d+n*2,cmp);
	for(int i=0;i<n+n;i++){
		cnt+=d[i].tag;
		ans=max(ans,cnt);
		//cnt����������i�˵��ϵ��ص�
		//�˺�����Ϊ�����׶� 
	}
	cout<<ans<<endl;
	return 0;
}


