#include <stdio.h>
int f[31][31];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    f[1][0]=1;
    for (int j=1;j<=m;j++)
        for (int i=1;i<=n;i++)
        {
            if (i==1)
                f[i][j]=f[2][j-1]+f[n][j-1];
            else if (i==n)
                f[i][j]=f[1][j-1]+f[n-1][j-1];
            else f[i][j]=f[i-1][j-1]+f[i+1][j-1];
        }
    printf("%d\n",f[1][m]);
}
