#include<bits/stdc++.h>
#define N 100005
using namespace std;
long long x[N]={0},n=0;
bool OK(int m){
	long long lb=0;
	for(int i=0;i<n;i++){
		lb+=lower_bound(x+i+1,x+n,x[i]+m)-x-i-1;//�ڴ�i+1���n���в��ң�С�� ����x[i]��Ϊm�������� �м��� 
	}
	if(ceil(n*(n-1)/4.)>lb) return 1;//С�����ĸ��������� ��λ  ��Ϊ��ѡ�ˣ�l=mid+1������ 
	else if(ceil(n*(n-1)/4.)<=lb) return 0;//x����  r=mid-1������ 
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	
	sort(x,x+n);//����
	
	long long l=0,r=x[n-1]-x[0],ans=r;//rΪ����ֵ 
	while(l<=r){
		int mid=l+(r-l)/2;
		if(OK(mid)==0) r=mid-1;
		else if(OK(mid)==1) ans=mid,l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
