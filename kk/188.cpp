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
    //��ÿ����Ϊֹ������������У���ǰ������ߵ㣩
    for(i=2; i<=n; ++i) {
        for(j=1; j<i; ++j) {
            if(a[j] < a[i] && fup[j] >= fup[i])
                fup[i]=fup[j]+1;//a[i]a[j]�����������ǲ��½���f���Ҳ����ȡ����Ϊ����������1���ǻ��
        }
    }
    //��ÿ���㵽���һ�������½������У���ǰ������ߵ㣩
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

