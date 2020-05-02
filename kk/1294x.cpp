#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define maxn 3300005
#define maxm 2
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

int trie[maxn][maxm] = {0};
int color[maxn] = {0}, a[100000];

int t,n,m,ans,k=1,b[32];
int nowp;
void insert(int x){
    for(int i=32; i>=0; i--){
        b[i] = x&1;
        x >>= 1;
    }
    int p = 0;
    for(int i=0; i<32; i++){
        int c = b[i];
        if(!trie[p][c]){
            trie[p][c] = k;
            k++;
        }
        p = trie[p][c];
    }
    color[p] = 1;
}

int search(int x){
    int ret = 0;
    for(int i=31; i>=0; i--){
        b[i] = x&1;
        x >>= 1;
    }
    int p = 0;
    for(int i=0; i<32; i++){
        // 贪心匹配
        int c = 1-b[i];  // 取反 
        if(!trie[p][c]){
            p = trie[p][1-c];  // 自己一定存在树中 
            ret = ret<<1;
        }else{
            p = trie[p][c];
            ret = ret << 1 | 1;
        }
    }
    nowp = p;
    return ret;
}

int main(){
    scanf("%d", &t);
    int i = 1;
    while(t--){
        memset(trie, 0, sizeof(trie));
        memset(color, 0, sizeof(color));
        insert(0);  // 初始化0
        ans = 0;
        int stp = 0;
        int enp = 0;
        int s = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
            s = s ^ a[i];
            //insert(s);
            int tmp = search(s);
            if(tmp > ans) {
                ans = tmp;  
                stp = (nowp-1)/32+1;
                enp = i;
            }
            insert(s);
        } 
        printf("Case #%d:", i++);
        printf("%d %d\n", stp+1,enp+1);  // 范围 
        //printf("%d\n", ans);   // 大小 
    }
    return 0;
}
