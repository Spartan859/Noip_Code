#include<bits/stdc++.h>
#define K 105
#define ll long long
using namespace std;

char c[K];
ll k,l,u;
struct big{
    ll a[K];
}d,p,q,r,s,t;//�ṹ��
big mul(big x,big y){//�߾��˸߾�
    big z=d;//��ֵʵ�����
    ll i,j;
    for(i=1;i<=k;++i){
        for(j=k-i+1;j;--j){
            z.a[i+j-1]+=x.a[i]*y.a[j];
        }
    }//�߾��˷�
    for(i=1;i<k;++i)z.a[i+1]+=z.a[i]/10,z.a[i]%=10;
    z.a[k]%=10;//�����λ
    return z;
}
int main(){
    ll i,j;
    scanf("%s%d",c,&k),l=strlen(c);
    for(i=(l<k?l:k);i;--i)p.a[i]=c[l-i]-48;//�ַ���ת������p��Ϊԭ��
    r=p,t.a[l=1]=1;//rΪ�˵Ľ������ʼֵΪp
    for(i=1;i<=k;++i){
        if(mul(p,r).a[i]==p.a[i])continue;//����Ϊ1�����
        u=1,s=r;//sΪÿ�γ˵���
        do{
            r=mul(s,r),++u;
            if(u>10){
                puts("-1");//���޽�
                return 0;
            }
        }while(mul(p,r).a[i]!=p.a[i]);
        for(j=1;j<=l;++j)t.a[j]*=u;
        for(j=1;j<l;++j)t.a[j+1]+=t.a[j]/10,t.a[j]%=10;
        if(t.a[l]>=10)t.a[l+1]+=t.a[l]/10,t.a[l++]%=10;//���´𰸣��߾��˵���
    }
    for(i=l;i;--i)printf("%d",t.a[i]);//���
    return 0;
}
