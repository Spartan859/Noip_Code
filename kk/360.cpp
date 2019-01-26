//
//  360.cpp
//  
//
//  Created by qianjing on 2018/1/24.
//
//

#include <bits/stdc++.h>
using namespace std;
int x[SIZE],y[SIZE],z[SIZE];
void converts(int *a, string s) {
    int i, l;
    for (l=s.size(), i=0; i<l; a[i]=s[l-1-i]-'0', i++);
    for (; i<SIZE; a[i++]=0);
}
bool lte(int *a, int *b, int len=SIZE) {
    int i;
    for (i=len-1; i>=0 && a[i]==b[i]; i--);
    return i<0 || a[i]<b[i];
}
void converti(int *a, int x) {
    int i;
    for (i=0; x; i++) {  //µ±x>0 ±£¨»°√ø“ªŒª ˝◊÷
        a[i] = x % 10;
        x /= 10;
    }
    for (; i<SIZE; a[i++]=0);
}
void copy(int *a, int *b) {
    int i;
    for (i=0; i<SIZE; a[i]=b[i], i++);
}
void division(int *q, int *r, int *a, int *b) {
    int i;
    converti(q, 0);
    copy(r, a);
    for (i=SIZE-1; !b[i]; i--);
    for (i=SIZE-1-i; i>=0; i--) {
        for (; lte(b, r+i, SIZE-i); sub(r+i, b, SIZE-i), q[i]++);
    }
}
int mod(int *a, int n) {
    int i, r=0;
    for (i=SIZE-1; i>=0; r=(r*10+a[i--])%n);
    return r;
}
bool eq(int *a, int *b) {
    int i;
    for (i=0; i<SIZE && a[i]==b[i]; i++);
    return i==SIZE;
}
void print(int *a) {
    int i;
    for (i=SIZE-1; i>0 && !a[i]; i--);  //∫ˆ¬‘∏ﬂŒªµƒ0
    for (; i>=0; cout << char(a[i--]+'0'));
}
int measure(int *a, int *b)
{
    copy(z,b);
    int q[SIZE],r[SIZE],temp[SIZE];
    converts(temp,"0")
    division(q,r,a,b);
    while(!eq(r,temp))
    {
        division(q,r,a,b);
        copy(z,r);
        copy(a,b);
        copy(b,z);
    }
    print(z);
}
int x[SIZE],y[SIZE],z[SIZE];
int main(){
    string sx,sy;
    converts(x,sx);
    converts(y,sy);
    measure(x,y);
    return 0;
}
