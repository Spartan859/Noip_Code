#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#define MAX 2010
using namespace std;
int maps[MAX][MAX];
int in[MAX];
int t[MAX];
int flag;
int k;
int Max,Min;
int DFS(int x)
{
    int i;
    for(i=Min;i<=Max;i++)
    {
        if(maps[x][i])///������һ�����������ĵ����
        {
            maps[x][i]--;///ɾȥ������ı�
            maps[i][x]--;
            DFS(i);
        }
    }
    t[++k]=x;///��¼·������Ϊ�ǵݹ����е��ż�
}
int main()
{
    int n,i,x,y;
    Max=-9999;
    Min=9999;
    flag=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        maps[x][y]++;
        maps[y][x]++;
        Max=max(x,max(y,Max));
        Min=min(x,min(y,Min));
        in[x]++;
        in[y]++;
    }
    for(i=Min;i<=Max;i++)
    {
        if(in[i]%2)///������ȵ㣬˵����ŷ��ͨ·
        {
            flag=1;
            DFS(i);
            break;
        }
    }
    if(!flag)///ȫΪż�ȵ㣬�ӱ����С�Ŀ�ʼ��
    {
        DFS(Min);
    }
    for(i=k;i>=1;i--)
    {
        printf("%d\n",t[i]);
    }
    return 0;
}
/*
34
1 2
2 3
3 4
4 8
8 12
12 11
11 10
10 9
9 5
5 1
1 6
2 7
3 8
5 10
6 11
7 12
6 1
7 2
8 3
10 5
11 6
12 7
2 5
3 6
4 7
6 9
7 10
8 11
5 2
6 3
7 4
9 6
10 7
11 8
*/
