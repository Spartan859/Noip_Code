#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
const int maxn = 105;
const int maxt = 20086;
const int quz = 10005;
int n, t;
int f[maxn][maxt];
int a[maxn];
int ans[maxn];

inline int read() {
    int x = 0, y = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') y = -1;
        ch = getchar();
    }
    while(isdigit(ch)) {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * y;
}

int main() {
    memset(f, 0, sizeof(f));
    n = read(), t = read();
    for(int i = 1; i <= n; ++i)
        a[i] = read();
     f[1][a[1] + quz] = 1;
     f[2][a[1] - a[2] + quz] = -1;
     for(int i = 3; i <= n; ++i)
         for(int j = -10000 + quz; j <= 10000 + quz; ++j) {
             if(f[i - 1][j] != 0) {
                 f[i][a[i] + j] = 1;
                 f[i][j - a[i]] = -1;
             }
         }
    int s = quz + t;
    for(int i = n; i >= 2; --i) {
        ans[i] = f[i][s];
        if(ans[i] == 1)
            s -= a[i];
        else if(ans[i] == -1) 
            s += a[i];
    }
    int cnt = 0;
    for(int i = 2; i <= n; ++i)
        if(ans[i] == 1) {
            cout << i - cnt - 1 << '\n';
            cnt++;
        }
    for(int i = 2; i <= n; ++i) 
        if(ans[i] == -1)
            cout << 1 << '\n';
/*    for(; cnt + 1 <= n - 1; cnt++) 
        cout << 1 << '\n';*/
    return 0;
}
