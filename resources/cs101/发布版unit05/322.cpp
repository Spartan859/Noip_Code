#include <iostream>
using namespace std;
int n=100,m=5,w[6],v[6],f[6][101];
int main(){
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++)
		for(int j=0;j<=n;j++) {  //ѭ���鿴����ʣ�����j 
			if(j<w[i])   //���i̫�أ��޷����� 
				f[i][j]=f[i-1][j];
			else 		//�Ƚ����־��ߣ����i���Էţ����߲���
				f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+w[i]);
		}
	cout<<f[m][n]<<endl; 
	return 0;
}
