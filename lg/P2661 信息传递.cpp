#include<bits/stdc++.h>
using namespace std;
int f[200002],d[200002],n,minn,last;   //f�������Ƚڵ㣬d���浽�����Ƚڵ��·������ 
int fa(int x)
{
    if (f[x]!=x)                       //����ʱ��;�������Ƚڵ��·������ 
    {
        int last=f[x];                 //��¼���ڵ㣨���ڵݹ��б����£��� 
        f[x]=fa(f[x]);                 //�������Ƚڵ㡣 
        d[x]+=d[last];                 //����·������ԭ�����ڸ��ڵ��ϣ��� 
    }
    return f[x];
}
void check(int a,int b)
{
    int x=fa(a),y=fa(b);               //�������Ƚڵ㡣 
    if (x!=y) {f[x]=y; d[a]=d[b]+1;}   //�������������������㣬���¸��ڵ��·������ 
    else minn=min(minn,d[a]+d[b]+1);   //�������ӣ��������С�����ȡ� 
    return;
}
int main()
{
    int i,t;
    scanf("%d",&n);
    for (i=1;i<=n;i++) f[i]=i;         //���Ƚڵ��ʼ��Ϊ�Լ���·����Ϊ0�� 
    minn=0x7777777;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&t);
        check(i,t);                    //��鵱ǰ�����Ƿ����б������ӡ� 
    }
    printf("%d",minn);
    return 0;
}
