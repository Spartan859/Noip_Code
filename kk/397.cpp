#include<iostream>
#include<algorithm>
#include<cmath>
#define ERR 0.000001
#define N 4005
using namespace std;
struct point{double pos; int tag;};//tag����1�������Ҷ˵� 
bool cmp(const point&a,const point&b){
	return a.pos+ERR<b.pos||fabs(a.pos-b.pos)<ERR&&a.tag<b.tag;//pos��С���󣨾�ȷ�ȣ�����tag��С����-1���ȣ� 
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
		//d[+1]����һ���߶Σ���+1����-1 
		//��������Ϊ��ʼ���׶� 
	}
	sort(d,d+n*2,cmp);
	//for(int i=0;i<n+n;i++) cout<<d[i].pos<<' '<<d[i].tag<<' '<<endl;
	for(int i=0;i<n+n;i++){
		cnt+=d[i].tag;
		ans=max(ans,cnt);
		//cnt����������i�˵��ϵ��ص�
		//�˺�����Ϊ�����׶� 
	}
	cout<<ans<<endl;
	return 0;
}
