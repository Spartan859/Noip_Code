#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;

struct query{ ll l,r,id,pos;} q[N]; // ������ѯ
struct freq { ll c,cnt; }; // ��ɫ������

ll b[N],n,m,K,ans[N],sz,cnt[N];

bool cmpQ(const query&a,const query&b){
    return a.pos<b.pos || (a.pos==b.pos && a.r>b.r);
}

int main(){
    cin>>n>>m>>K;
    sz=(ll) sqrt(n);
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r; q[i].id=i;
        q[i].pos=(q[i].l-1)/sz+1; // ���ڿ�
    }
    // ������˵��������˵�ͬһ��İ��Ҷ˵㽵��
    sort(q+1,q+m+1,cmpQ);
    for(ll i=1,l=1,r=0,mx=0;i<=m;i++){
        // ��������
        while (l>q[i].l) ++cnt[b[--l]];
        while (r<q[i].r) ++cnt[b[++r]];
        while (l<q[i].l) --cnt[b[l++]];
        while (r>q[i].r) --cnt[b[r--]];
        for (ll j=1;j<=K;j++)
            if (cnt[mx]<cnt[j] || (cnt[mx]==cnt[j] && mx>j)) mx=j;
        ans[q[i].id]=mx;
    }
    for(ll i=1;i<=m;i++) printf("%lld\n",ans[i]);
    return 0;
} 
