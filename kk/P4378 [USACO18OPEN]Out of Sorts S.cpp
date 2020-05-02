#include<bits/stdc++.h>
#define mx 100005
using namespace std;
struct node{
    int x,p;
}a[mx];
bool cmp(const node &a,const node &y)
{
    return a.x<y.x||a.x==y.x&&a.p>y.p;
}
int n;
int main(){
	freopen("testdata.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x;
        a[i].p=i;
    }
    sort(a,a+n,cmp);
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,a[i].p-i);
    ans+=1;
    cout<<ans;
    return 0;
}
