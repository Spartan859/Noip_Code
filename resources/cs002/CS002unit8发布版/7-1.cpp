#include<iostream>
using namespace std;
int i,j,tot,f[4][4];
int main(){
	for(i=0;i<4;i++) 
		for(j=0;j<4;j++)
			cin>>f[i][j];
	for(i=0;i<4;i++)
		tot+=f[i][i]+f[i][3-i];
	cout<<tot;	
	return 0;
}
