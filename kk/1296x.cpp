#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std;
typedef long long ll;
bool prime[10005];
void getprime(){
    memset(prime,true,sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i < 10005; i++){
        if(prime[i]){
            for(int j = i+i; j < 10005; j += i){
                prime[j] = false;
            }
        }
    }
}
int cal(int n,int p){
    if(n < p) return 0;
    else return n / p + cal(n / p,p);
}
int main(){
    getprime();
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int i = 2;
        ll sum = 1;
        while(i <= n){
            if(prime[i]){
                sum = sum * (ll)(cal(n,i)*2 + 1) % MOD;
                cout<<i<<endl;
            }
            i++;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
