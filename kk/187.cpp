#include<bits/stdc++.h>
using namespace std;
int main() {
    int i,j,max,t,a[1005],b[1005],imax;
    cin>>t;
    for(i=0; i<t; i++)
        cin>>a[i];
    b[0]=a[0];
    for(i=1; i<t; i++) {
        b[i]=a[i];
        imax=0;
        for(j=0; j<i; j++) {
            if(a[i]>a[j]) {
                if(imax<b[j])
                    imax=b[j];
            }
        }
        b[i]+=imax;
    }
    for(i=0,max=0; i<t; i++)
        if(max<b[i])
            max=b[i];
    cout<<max<<endl;
    return 0;
}
