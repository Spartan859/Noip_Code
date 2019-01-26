#include <iostream>
#include <stdio.h>
using namespace std;
char st[110][110];
int n,m;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
	 for (int j=1;j<=m;j++) cin>>st[i][j];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (st[i][j]=='*') 
			{
				cout<<st[i][j];
				continue;
			}
			int s=0;
			if (i-1>=1 && st[i-1][j]=='*') s++;
			if (i+1<=n && st[i+1][j]=='*') s++;
			if (j-1>=1 && st[i][j-1]=='*') s++;
			if (j+1<=m && st[i][j+1]=='*') s++;
			if (i-1>=1 && j-1>=1 && st[i-1][j-1]=='*') s++;
			if (i-1>=1 && j+1<=m && st[i-1][j+1]=='*') s++;
			if (i+1<=n && j-1>=1 && st[i+1][j-1]=='*') s++;
			if (i+1<=n && j+1<=m && st[i+1][j+1]=='*') s++;
			cout<<s;
		} 
		if (i<=n-1) cout<<endl;
	}
	return 0;
}
