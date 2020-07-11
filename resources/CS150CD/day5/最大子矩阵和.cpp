#include<iostream>
using namespace std;
const int SIZE=100;
int matrix[SIZE+1][SIZE+1];
int rowsum[SIZE+1][SIZE+1];
//rowsum[i][j]记录前i行前j个数的和 
int m,n,i,j,first,last,area,ans;
int main(){
	cin>>m>>n;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			cin>>matrix[i][j];
	ans=matrix____(1)____;
	for(i=1;i<=m;i++)
		____(2)____;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			rowsum[i][j]=____(3)____;
	for(first=1;first<=n;first++)
		for(last=first;last<=n;last++){
			____(4)____;
			for(i=1;i<=m;i++) {
				area+=____(5)____;
				if(area>ans) ans=area;
				if(area<0) area=0;
			}
		}
	cout<<ans<<endl;
	return 0;
}
