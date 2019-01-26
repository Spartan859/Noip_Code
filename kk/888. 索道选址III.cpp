#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define MAXN 2010
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
int N;
double Map[MAXN][MAXN];
struct Node
{
    double x, y, h;
};
Node num[MAXN];
double cost[MAXN][MAXN], len[MAXN][MAXN];
double dis(Node a, Node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void getMap()//求出cost 和 len
{
    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            cost[i][j] = cost[j][i] = fabs(num[i].h - num[j].h);
            len[i][j] = len[j][i] = dis(num[i], num[j]);
        }
    }
}
double low[MAXN];
bool vis[MAXN];
int pre[MAXN];//记录该点在最小生成树中的前驱
double prime()//求最小生成树
{
    for(int i = 0; i < N; i++)
    {
        vis[i] = false;
        low[i] = Map[0][i];
        pre[i] = 0;
    }
    vis[0] = true;
    double sumcost = 0, sumlen = 0;
    for(int i = 1; i < N; i++)
    {
        double Min = INF;
        int next = 0;
        for(int j = 0; j < N; j++)
        {
            if(!vis[j] && Min > low[j])
            {
                next = j;
                Min = low[j];
            }
        }
        vis[next] = true;
        sumcost += cost[pre[next]][next];//记录花费
        sumlen += len[pre[next]][next];//记录长度
        for(int j = 0; j < N; j++)
        {
            if(!vis[j] && low[j] > Map[next][j])
            {
                low[j] = Map[next][j];
                pre[j] = next;
            }
        }
    }
    return sumcost / sumlen;
}
void newMap(double o)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)//重新计算Map值
            Map[i][j] = Map[j][i] = cost[i][j] - o * len[i][j];
    }
}
int main()
{
    while(scanf("%d", &N)!=EOF)
    {
        for(int i = 0; i < N; i++)
            scanf("%lf%lf%lf", &num[i].x, &num[i].y, &num[i].h);
        getMap();
        double x0;
        double sumcost = 0, sumlen = 0;
        for(int i = 1; i < N; i++)//任选N-1条边
            sumcost += cost[0][i], sumlen += len[0][i];
        double x = sumcost / sumlen;
        while(1)
        {
            x0 = x;
            newMap(x);//按x的值 重新计算Map值
            x = prime();//更新
            if(fabs(x0 - x) < eps)//新值没有减少
                break;
        }
        printf("%.3lf\n", x);
    }
    return 0;
}
