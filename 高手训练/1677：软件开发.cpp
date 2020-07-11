#include<iostream>
#include<algorithm>
using namespace std;
int t1[105],t2[105],f[105];
int n,m;
bool check(int mid){
    for(int i=1;i<105;i++){
        f[i]=-0x3f3f3f3f;
    }
    f[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=0;k<=min(mid/t1[i],j);k++){
                f[j]=max(f[j],f[j-k]+(mid-t1[i]*k)/t2[i]);
            }
        }
    }
    return f[m]>=m;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t1[i]>>t2[i];
    }
    int l=1,r=1000000;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
    return 0;
}
