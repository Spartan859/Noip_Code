#include<bits/stdc++.h>
int a[30],book[30];
int n,j,s,sum,f;
void dfs(int step)
{
    int i;
    if(s>=sum )
    {
        if(s==sum)
        {
            if(f==0)
            {
                f=1;
            }
            if(f)
            {
                printf("YES\n");
                exit(0);
            }
        }
        //return ;
    }
    int  k;
    for(k=step; k<n; k++)
    {
        s+=a[k];
        book[k]=1;
        dfs(k+1);
        s-=a[k];
        book[k]=0;
    }
}
int main()
{
    int i;
    while(~scanf("%d%d",&n,&sum))
    {
        s=0,f=0;
        memset(book,0,sizeof(book));
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        dfs(0);
        if(f==0) printf("NO\n");
    }
    return 0;
}
