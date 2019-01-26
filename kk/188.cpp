#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[105];
    int fup[105]= {0},fdown[105];
    int n,i,j,ans=0;
    cin>>n;
    for(i=1; i<=n; ++i) {
        cin>>a[i];
        fup[i]=1;
        fdown[i]=1;
    }
    //到每个点为止的最长上升子序列（当前点是最高点）
    for(i=2; i<=n; ++i) {
        for(j=1; j<i; ++j) {
            if(a[j] < a[i] && fup[j] >= fup[i])
                fup[i]=fup[j]+1;//a[i]a[j]控制上升还是不下降，f相等也可以取，因为后续操作加1后还是会大
        }
    }
    //从每个点到最后一个点的最长下降子序列（当前点是最高点）
    for(i=n; i>=1; --i) {
        for(j=n; j>i; --j) {
            if(a[j] < a[i] && fdown[j] >= fdown[i])
                fdown[i]=fdown[j]+1;
        }
    }

    for(i=1; i<=n; ++i) {
        if(fup[i]+fdown[i]-1>ans) ans = fup[i]+fdown[i]-1;
    }
    cout<<n-ans<<endl;
    return 0;
}

