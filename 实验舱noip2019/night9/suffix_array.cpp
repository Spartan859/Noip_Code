#include<iostream>
#include<cstdio>
#include<cstring>
#define rint register int
#define inv inline void
#define ini inline int
#define maxn 1000050
using namespace std;
char s[maxn];
int y[maxn],x[maxn],c[maxn],sa[maxn],rk[maxn],height[maxn],wt[30];
int n,m;
inv putout(int x) {
    if(!x) {
        putchar(48);
        return;
    }
    rint l=0;
    while(x) wt[++l]=x%10,x/=10;
    while(l) putchar(wt[l--]+48);
}
inv get_SA() {
    for (rint i=1; i<=n; ++i) ++c[x[i]=s[i]];
//c������Ͱ
//x[i]�ǵ�i��Ԫ�صĵ�һ�ؼ���
    for (rint i=2; i<=m; ++i) c[i]+=c[i-1];
//��c��ǰ׺�ͣ����ǾͿ��Եó�ÿ���ؼ���������ڵڼ���
    for (rint i=n; i>=1; --i) sa[c[x[i]]--]=i;
    for (rint k=1; k<=n; k<<=1) {
        rint num=0;
        for (rint i=n-k+1; i<=n; ++i) y[++num]=i;
//y[i]��ʾ�ڶ��ؼ�������Ϊi��������һ�ؼ��ֵ�λ��
//��n-k+1����nλ��û�еڶ��ؼ��ֵ� ������������ǰ��
        for (rint i=1; i<=n; ++i) if (sa[i]>k) y[++num]=sa[i]-k;
//����Ϊi���� ���������Ƿ��ڵ�kλ�Ժ�
//�������(sa[i]>k) ��ô��������Ϊ���˵ĵڶ��ؼ��֣��Ͱ����ĵ�һ�ؼ��ֵ�λ����ӽ�y������
//����iö�ٵ��ǵڶ��ؼ��ֵ��������ڶ��ؼ��ֿ�ǰ�������
        for (rint i=1; i<=m; ++i) c[i]=0;
//��ʼ��cͰ
        for (rint i=1; i<=n; ++i) ++c[x[i]];
//��Ϊ��һ��ѭ���Ѿ��������εĵ�һ�ؼ��� ����ֱ�ӼӾ�����
        for (rint i=2; i<=m; ++i) c[i]+=c[i-1]; //��һ�ؼ�������Ϊ1~i�����ж��ٸ�
        for (rint i=n; i>=1; --i) sa[c[x[y[i]]]--]=y[i],y[i]=0;
//��Ϊy��˳���ǰ��յڶ��ؼ��ֵ�˳�����ŵ�
//�ڶ��ؼ��ֿ���ģ���ͬһ����һ�ؼ���Ͱ������Խ����
//��������
        swap(x,y);
//���ﲻ����̫�࣬��ΪҪ�����µ�xʱҪ�õ��ɵģ��ͰѾɵĸ���������û�����˼
        x[sa[1]]=1;
        num=1;
        for (rint i=2; i<=n; ++i)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]) ? num : ++num;
//��Ϊsa[i]�Ѿ��ź����ˣ����Կ��԰�����ö�٣�������һ�εĵ�һ�ؼ���
        if (num==n) break;
        m=num;
//����Ͳ����Ǹ�122�ˣ���Ϊ�����µı����
    }
    for (rint i=1; i<=n; ++i) putout(sa[i]),putchar(' ');
}
inv get_height() {
    rint k=0;
    for (rint i=1; i<=n; ++i) rk[sa[i]]=i;
    for (rint i=1; i<=n; ++i) {
        if (rk[i]==1) continue;//��һ��heightΪ0
        if (k) --k;//h[i]>=h[i-1]-1;
        rint j=sa[rk[i]-1];
        while (j+k<=n && i+k<=n && s[i+k]==s[j+k]) ++k;
        height[rk[i]]=k;//h[i]=height[rk[i]];
    }
    putchar(10);
    for (rint i=1; i<=n; ++i) putout(height[i]),putchar(' ');
}
int main() {
    gets(s+1);
    n=strlen(s+1);
    m=122;
    get_SA();
}
