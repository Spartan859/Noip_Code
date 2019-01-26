#include <bits/stdc++.h>
#define maxN 100010

using namespace std;
typedef long long QAQ ;

int arr[maxN];

priority_queue<int ,vector<int>,greater<int> >Q; 
QAQ ans ;
int main(){
    int n,tmp2,tmp1;
    ios::sync_with_stdio(false);
    cin >> n ;
    for(int i=1 ; i<=n ;++i)cin >> arr[i];
    sort(arr+1,arr+n+1);;//对数据先排序，防止优先队列超时
    for(int i=1;i<=n;++i){
        Q.push(arr[i]);
    }
    for(int i=1;i<=n-1;++i){
        tmp1=Q.top();
        Q.pop();
        tmp2=Q.top();
        Q.pop();
        Q.push(tmp1+tmp2);
        ans+=tmp1+tmp2;
    }
    printf("%lld",ans);
    return 0 ;
}
