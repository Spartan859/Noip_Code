#include<cstdio>
using namespace std;
#define fo(a,b,c) for(int a=b;a<=c;a++)
#define go(a,b,c) for(int a=b;a>=c;a--)
#define min(a,b) ((a)<(b)?(a):(b))
int read(){
    int a=0,f=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')f=1;
    for(;c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
    return f?-a:a;
}
const int N=1e5+1;
int a[N],f[N],qu[N],qi[N],pst[N],qst[N],pt,qt,s=1,t,mid;
void pushp(int x){
    if(!pt||qu[pst[pt]]>qu[x])pst[++pt]=x;
}//��˲���
void pushq(int x){
    if(!qt||qu[qst[qt]]>qu[x])qst[++qt]=x; 
}//�Ҷ˲���
void rebuild(){
    mid=s+t>>1;pt=qt=0;
    go(i,mid,s)pushp(i);
    fo(i,mid+1,t)pushq(i);
}//�ع�����ջ
int main(){
//f[i]=f[j]+max(a[j+1]...a[i])(s[i]-s[j]<=m)���鷽��
    int n=read(),m=read(),st=1,sum=0;
    fo(i,1,n){
        sum+=a[i]=read();
        while(sum>m)sum-=a[st++];//ά��st
        while(s<=t&&a[qi[t]]<=a[i]){
            if(qt&&qst[qt]==t)qt--;
            if(pt&&pst[pt]==t)pt--;
            if(--t<=mid)rebuild();
	}
	qi[++t]=i;qu[t]=(s==t?f[st-1]:f[qi[t-1]])+a[i];pushq(t);//���뵱ǰԪ��
        if(pst[pt]==s)pt--;
        if(qst[qt]==s)qt--;//��a[q1]�ų���������f[a[qj]]+a[q[j+1]]���ɣ�
        while(s<=t&&qi[s]<st){
            if(qt&&qst[qt]==s)qt--;
            if(pt&&pst[pt]==s)pt--;
            if(++s>mid)rebuild();
	}
        f[i]=a[qi[s]]+f[st-1];
        if(pt)f[i]=min(f[i],qu[pst[pt]]); 
        if(qt)f[i]=min(f[i],qu[qst[qt]]);//ת��
    }
    printf("%d\n",f[n]);
    return 0;
}
//input
/*
6 6
3 5 1 2 4 1
*/
//output
//13
