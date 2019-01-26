//
//  main.cpp
//  twb-light
//
//  Created by Xiao Ge on 2/9/18.
//  Copyright ? 2018 Xiao Ge. All rights reserved.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n,m,p=1000007;

ll pow(ll x,ll y){
    if (y==0) return 1;
    ll z=pow(x,y/2);
    return y&1? z*z%p*x%p: z*z%p;
}

ll inv(ll x) {    return pow(x,p-2); }

ll C(ll x,ll y){
    if (y>x) return 0;
    ll ans=1;
    for (ll i=1;i<=y;i++)
        ans= ans*inv(i)%p*(x-i+1)%p;
    return ans;
}

int main() {
    //cin>>n>>m;
    cout<<C(7,2)<<endl;
    return 0;
}

