//
//  main.cpp
//  360
//
//  Created by qianjing on 2018/1/25.
//  Copyright © 2018年 qianjing. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define LL long long
#define FOR(i,x,y) for(int i=x;i<=y;i++)
#define rFOR(i,x,y) for(int i=x;i>=y;i--)
#define rep(i,x,y) for(int i=x;i<y;i++)
using namespace std;
const int maxn = 10000 + 10;
struct Bignum
{
    int a[maxn];
    int n;
    void input(char str[])
    {
        n = strlen(str);
        rep(i,0,n) a[i] = str[n-i-1] - '0';
    }
    void output()
    {
        rFOR(i,n-1,0)printf("%d",a[i]);
    }
    bool operator < (const Bignum& rhs) const
    {
        if(n < rhs.n) return true;
        if(n > rhs.n) return false;
        rFOR(i,n-1,0) { if(rhs.a[i] > a[i]) return true; if(a[i] > rhs.a[i]) return false;}
        return true;
    }
    Bignum operator - (const Bignum& rhs) const
    {
        Bignum ret ; ret.n = n;
        int mu = 0;
        rep(i,0,n)
        {
            int tmp;
            if(i < rhs.n) tmp = a[i] - rhs.a[i] - mu;
            else tmp = a[i] - mu;
            if(tmp < 0)
            {
                mu = 1;
                tmp += 2;
            }
            else mu = 0;
            ret.a[i] = tmp;
        }
        while(ret.n > 0 && ret.a[ret.n-1] == 0) ret.n--;
        return ret;
    }
    Bignum Div2()
    {
        Bignum ret ; ret.n = n - 1;
        rep(i,0,n-1) ret.a[i] = a[i+1];
        return ret;
    }
};
void gcd(Bignum a , Bignum b)
{
    int zero = 0;
    while(a.n && b.n)
    {
        if(a.a[0])
        {
            if(b.a[0])
            {
                if(b < a) a = a - b;
                else b = b - a;
            }
            else b = b.Div2();
        }
        else
        {
            if(b.a[0]) a = a.Div2();
            else
            {
                a = a.Div2();
                b = b.Div2();
                zero++;
            }
        }
    }
    if(a.n) a.output();
    else b.output();
    while(zero--)printf("0");
    printf("\n");
}
char s[maxn];
Bignum a , b;
int main()
{
    scanf("%s",s);
    a.input(s);
    scanf("%s",s);
    b.input(s);
    gcd(a , b);
    return 0;
}
