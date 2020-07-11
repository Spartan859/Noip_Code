#include<iostream>
using namespace std;
int i,j,f[3][3]={{0,1,2},{3,4,5},{6,7,8}};
int main(){
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cout<<f[2-i][2-j];
		cout<<endl;
	}
	return 0;
}
