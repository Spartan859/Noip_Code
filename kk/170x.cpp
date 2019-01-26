#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1010
#define M 100010
#define mod 100007
#define p 17
using namespace std;
int hash[mod],b[mod],vis[mod];
int get_hash(char *s)
{
    int len = strlen(s),sum = 0;
    for (int i=0;i<len;i++)
        sum = (sum*p+s[i] - กฎaกฎ)%mod;
    return sum;
}
int main()
{
    int n,m,sum = 0;
    char a[12];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%s",a);
        hash[get_hash(a)] = 1;
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%s",a);
        b[i] = get_hash(a);
        if (hash[b[i]] && !vis[b[i]])
        {
            sum++;
            vis[b[i]] = 1;
        }
    }
    printf("%d\n",sum);
    for (int i=1;i<=mod;i++) vis[i]=0; 
    int h=0,t=1,sumx=0,minx=0x7ffffff;
    while (t<=m)
    {
        while (t<=m)
        {
            if (!vis[b[t]] && hash[b[t]]) sumx++;
            vis[b[t]] ++;
            t++;
            if (sumx == sum) break;
        }
        while (h<t && (vis[b[h]]>1 || !hash[b[h]]))
        {
            vis[b[h]] --;
            h++;
        }
        minx = min(minx,t-h);
    }
    printf("%d",minx);
}
