#include<stdio.h>
#include<math.h>
bool f[41][2000][2000];
int tot,a[41],n;
double ans;
double S(double a,double b,double c)
{
       double p=(a+b+c)/2;
       return sqrt(p*(p-a)*(p-b)*(p-c));
}       
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    f[0][0][0]=1;
    for (int i=1;i<=n;++i)
        for (int j=0;j<=tot/2+1;++j)
            for (int k=0;k<=tot/2+1;++k)
                f[i][j][k]=((f[i-1][j][k])||((a[i]<=j)&&(f[i-1][j-a[i]][k]))||((a[i]<=k)&&(f[i-1][j][k-a[i]])));
    for (int i=1;i<=tot/2+1;++i)
        for (int j=1;j<=tot/2+1;++j)
            if (f[n][i][j])
            {
                           int k=tot-i-j;
                           if ((k+i>j)&&(i+j>k)&&(j+k>i))
                           {
                                                         double tem=S(i,j,k);
                                                         if (tem>ans) ans=tem;
                           }
            }
    if (ans!=0) printf("%d\n",(int)(ans*100));
    else printf("-1\n");
    return 0;
}
