#include<bits/stdc++.h>
using namespace std;
int f[205][205],M,T,n;
int a[105][2];
int main(){
	scanf("%d%d%d",&n,&M,&T);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	for(int k=1;k<=n;k++)
		for(int i=M;i>=a[k][0];i--)
			for(int j=T;j>=a[k][1];j--)
				f[i][j]=max(f[i][j],f[i-a[k][0]][j-a[k][1]]+1);
	printf("%d\n",f[M][T]);
	return 0;
}
