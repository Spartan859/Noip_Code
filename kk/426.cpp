#include<bits/stdc++.h>
#define N 50005
using namespace std;
int main(){
	int m,a,b,temp,j;
	cin>>m>>a>>b;
	int sni[N]={0},hg[N]={0};
	for(int i=0;i<a;i++){
		cin>>temp;
		sni[i]=m-temp;//sni����ʣ���������������ǹ��Ǯ 
	}
	for(int i=0;i<b;i++) cin>>hg[i];
	sort(hg,hg+b);//��ǹ�۸��������
	int ans=0;
	for(int i=0;i<a;i++){
		//for(j=0;j<b&&hg[j]<=sni[i];j++);
		ans+=upper_bound(hg,hg+b,sni[i])-hg;
    }
    cout<<ans<<endl;
	return 0;
}
