#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 85, Mod = 10000; //�߾���λѹ���󷨺� 
int n, m;
int ar[MAXN];

struct HP {
    int p[505], len;
    HP() {
        memset(p, 0, sizeof p);
        len = 0;
    } //���ǹ��캯��������ֱ�Ӵ���һ���߾��ȱ��� 
    void print() {
        printf("%d", p[len]);  
        for (int i = len - 1; i > 0; i--) {  
            if (p[i] == 0) {
                printf("0000"); 
                continue;
            }
            for (int k = 10; k * p[i] < Mod; k *= 10) 
                printf("0");
            printf("%d", p[i]);
        }
    } //��λѹ������� 
} f[MAXN][MAXN], base[MAXN], ans;

HP operator + (const HP &a, const HP &b) {
    HP c; c.len = max(a.len, b.len); int x = 0;
    for (int i = 1; i <= c.len; i++) {
        c.p[i] = a.p[i] + b.p[i] + x;
        x = c.p[i] / Mod;
        c.p[i] %= Mod;
    }
    if (x > 0)
        c.p[++c.len] = x;
    return c;
} //�߾�+�߾� 

HP operator * (const HP &a, const int &b) {
    HP c; c.len = a.len; int x = 0;
    for (int i = 1; i <= c.len; i++) {
        c.p[i] = a.p[i] * b + x;
        x = c.p[i] / Mod;
        c.p[i] %= Mod;
    }
    while (x > 0)
        c.p[++c.len] = x % Mod, x /= Mod;
    return c;
} //�߾�*���� 

HP max(const HP &a, const HP &b) {
    if (a.len > b.len)
        return a;
    else if (a.len < b.len)
        return b;
    for (int i = a.len; i > 0; i--)
        if (a.p[i] > b.p[i])
            return a;
        else if (a.p[i] < b.p[i])
            return b;
    return a;
} //�Ƚ�ȡ���ֵ 

void BaseTwo() {
    base[0].p[1] = 1, base[0].len = 1;
    for (int i = 1; i <= m + 2; i++){ //������m! m! m! ��TMд��n����n��... 
        base[i] = base[i - 1] * 2;
    }
} //Ԥ�����2���� 

int main(void) {
    scanf("%d%d", &n, &m);
    BaseTwo();
    while (n--) {
        memset(f, 0, sizeof f);
        for (int i = 1; i <= m; i++)
            scanf("%d", &ar[i]);
        for (int i = 1; i <= m; i++)
            for (int j = m; j >= i; j--) { //��Ϊ��ֵ��С���䣬DP��Ȼ�ʹӴ����俪ʼ 
                f[i][j] = max(f[i][j], f[i - 1][j] + base[m - j + i - 1] * ar[i - 1]); 
                f[i][j] = max(f[i][j], f[i][j + 1] + base[m - j + i - 1] * ar[j + 1]);
            } //�ýṹ�����������д�����Ƚ���Ȼ 
        HP Max;
        for (int i = 1; i <= m; i++)
            Max = max(Max, f[i][i] + base[m] * ar[i]);
        ans = ans + Max; //��¼���ܴ��� 
    }
    ans.print(); //��� 
    return 0;
}
