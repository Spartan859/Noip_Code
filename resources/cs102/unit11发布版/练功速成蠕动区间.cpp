#include<iostream>
#define N 110
using namespace std;
int n,m,x[N];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>x[i];
	int sum=0,ans=n+1;
	int tail=0,head=0; 
	while(1){
		while(head<n&&sum<m) //ͷ���ƶ�
			sum+=x[head++];
		if(sum<m)break;	//��ֹ���� 
		ans=min(ans,head-tail);  //�������Ž� 
		sum-=x[tail++];  //β���ƶ�		
	}
	cout<<ans<<endl; 	
	return 0;
}

