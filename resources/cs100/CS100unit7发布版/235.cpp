#include<iostream>
using namespace std;
int a1,a2,a3,n,ans;
int main(){
	cin>>n;
	for(a1=0;a1<=n;a1++)
	for(a2=0;a2<=n;a2++)
	for(a3=0;a3<=n;a3++){
		//wrtie your code here
		if((a1+a2)%2==0&&(a2+a3)%3==0&&(a1+a2+a3)%5==0){
			ans=max(ans,a1+a2+a3);
		}
	}
	cout<<ans;
	return 0;
}
//先储存第一个条件，再判断下一个条件，筛选多的先选
 


