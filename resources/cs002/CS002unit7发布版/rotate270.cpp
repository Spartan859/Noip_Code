#include<iostream>
using namespace std;
int i,j,f[3][3]={{0,1,2},{3,4,5},{6,7,8}};
int main(){
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cout<<f[j][2-i];
		cout<<endl;
	}
	return 0;
}
