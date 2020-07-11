#include <iostream>
#define MAXC 1001 
#define MAXN 501
using namespace std;
int n,C,w[MAXN],v[MAXN],f[MAXN][MAXC]; 
int main(){
	cin>>C>>n;
	for(int i=1;i<=n;++i) cin>>w[i]>>v[i];		
	// f[i][j]�����ǰi����Ʒ��ѡ���������ز�����j������ֵ 
	for (int i=1;i<=n;++i)   //ѭ���鿴��Ʒi 
		for (int j=0;j<=C;++j)   //ѭ���鿴����ʣ������j 
			if(j<w[i])   // ��Ʒi̫�أ��޷����� 
				f[i][j]=f[i-1][j];
			else 		// �Ƚ����־��ߣ���Ʒi���Էţ����߲���
				f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
	cout<<f[n][C]<<endl; 
	return 0;
} 


