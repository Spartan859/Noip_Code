#include<iostream>
using namespace std;
int a[4][4];
int main(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++) cin>>a[i][j];
	}
	cout<<a[0][0]+a[1][1]+a[2][2]+a[3][3]+a[0][3]+a[1][2]+a[2][1]+a[3][0];
	return 0;
}
