#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100, MAX_M = 100;
char field[MAX_N+5][MAX_M+5];
int dx[4]={0,1,0,-1}; 
int dy[4]={1,0,-1,0};
int n, m;

void DFS(int x, int y);

int main()
{
    int num = 0;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", field[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (field[i][j] == '@') {//从有@的地方DFS
                DFS(i, j);
                num++;
            }
    printf("%d\n", num);
    return 0;
}

void DFS(int x, int y)
{
    //遍历8个方向
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;
            //判断(nx, ny)是否在园子内且是否有积水
            if (nx >= 0 && nx < n && ny >=0 && ny < m && field[nx][ny] == '@') {
                field[nx][ny] = '.';
                DFS(nx, ny);
            }
        }
}
