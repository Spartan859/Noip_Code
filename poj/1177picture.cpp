#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int N;
int pos[20000+100];
int m = 10000;
struct edge
{
    int x, y, f;
    int flog;
    bool operator < (const edge& r) const
    {
        if(f == r.f)
        {
            return flog>r.flog;
        }
        return f < r.f;
    }
}e[2][10000+10];

int solve(int o)
{
    memset(pos, 0, sizeof(pos));
    sort(e[o], e[o]+2*N);
    int res = 0;
    for(int i=0; i<2*N; i++)
        for(int j=e[o][i].x; j<e[o][i].y; j++)
        {
            pos[j+m] += e[o][i].flog;
            if(pos[j+m]==0 && e[o][i].flog<0)
                res++;
            if(pos[j+m]==1 && e[o][i].flog>0)
                res++;
        }
    return res;
}

int main()
{
    //freopen("picture.in", "r", stdin);
    //freopen("picture.out", "w", stdout);
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        e[0][i*2] = (edge){x1, x2, y1, 1};
        e[0][i*2+1] = (edge) {x1, x2, y2, -1};
        e[1][i*2] = (edge) {y1, y2, x1, 1};
        e[1][i*2+1] = (edge) {y1, y2, x2, -1};
    }
    int ans1 = solve(0);
    int ans2 = solve(1);
    printf("%d\n", ans1+ans2);
    return 0;
}
