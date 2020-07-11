#include<bits/stdc++.h>
#define ll long long
#define MAX 5005
#define K 1000000
using namespace std;

int n, Q;
int a[MAX], cnt[2000005];
ll s[MAX][MAX];

int main() {
    cin >> n >> Q;
    for(int i = 1; i <= n; ++i) 
        scanf("%d", &a[i]), a[i] += K;
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) {
            if(j > i+1)
                if(a[i]+a[j] <= K*3 && a[i]+a[j] >= K) s[i][j] = cnt[K*3-a[i]-a[j]];
            cnt[a[j]]++;
        }
        for(int j = i+1; j <= n; ++j) cnt[a[j]]--;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    int l, r;
    while(Q--) {
        scanf("%d%d", &l, &r);
        printf("%lld\n", s[r][r]-s[l-1][r]-s[r][l-1]+s[l-1][l-1]);
    }
    return 0;
}
