#include <iostream>
#include <cstring>
using namespace std;
int n,m,k,ans;
int hash[5][5];
void work(int x,int y,int tot){
	int i,j;
	if (tot==k){
		ans++;
		return;
	}
	do{
		while (hash[x][y]){
			y++;
			if (y==m){
				x++;
				y=____(1)____;
			}
			if (x==n)
				return;
		}
		for (i=x-1;i<=x+1;i++)
			if (i>=0&&i<n)
				for (j=y-1;j<=y+1;j++)
					if (j>=0&&j<m)
						____(2)____;
		        ____(3)____;
		for (i=x-1;i<=x+1;i++)
			if (i>=0&&i<n)
				for (j=y-1;j<=y+1;j++)
					if (j>=0&&j<m)
						____(4)____;
		y++;
		if (y==m){
			x++;
			y=0;
		}
		if (x==n)
			return;
	}
	while (1);
}
int main(){
	cin >> n >> m >> k;
	ans=0;
	memset(hash,0,sizeof(hash));
	____(5)____;
	cout << ans << endl;
	return 0;
}

