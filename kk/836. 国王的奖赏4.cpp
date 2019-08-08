#include<bits/stdc++.h>
using namespace std;
int n, m, q, x1, y11, x2, y2, k1, k2;
int a[505][505];
int st[505][505][10][10];
int lg[505];

int main()
{
    freopen("reward4.in","r",stdin);
    freopen("reward4.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	m = n;
    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= m ; ++j)
        	scanf("%lld",&a[i][j]),st[i][j][0][0]=a[i][j];
    for (int p = 0 ; (1<<p)<=n ;p++)
        for (int q = 0 ; (1<<q)<=m ; q++)
            if (p != 0 || q != 0)
                for (int i = 1 ; i + (1<<p) - 1 <= n ; i ++)
                    for (int j = 1 ; j + (1<<q) - 1 <= m ; j ++)
                        if (!p) st[i][j][p][q] = max(st[i][j][p][q - 1], st[i][j+(1<<(q-1))][p][q - 1]);
                        else st[i][j][p][q] = max(st[i][j][p-1][q], st[i+(1<<(p-1))][j][p-1][q]);
    while(q--)
    {
        scanf("%d %d %d %d",&x1,&y11,&x2,&y2);
        k1 = lg[x2 - x1 + 1], k2 = lg[y2 - y11 + 1];
        printf("%d ", max(st[x1][y11][k1][k2], max(st[x2-(1<<k1)+1][y11][k1][k2], max(st[x1][y2-(1<<k2)+1][k1][k2], st[x2-(1<<k1)+1][y2-(1<<k2)+1][k1][k2]))));
    }
    return 0;
}
