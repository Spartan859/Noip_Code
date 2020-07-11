#include<iostream>
#define M 51
using namespace std;
long long yh[M][M],n,m,i,j;
int main(){
	cin>>n;
	yh[0][0]=1;
	cout<<yh[0][0]<<endl;
	for(i=1;i<=n;i++){
		yh[i][0]=1;
		cout<<yh[i][0];
		for(j=1;j<=i;j++){
			yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
			cout<<" "<<yh[i][j];
		}
		cout<<endl;
	}
	return 0;
}
