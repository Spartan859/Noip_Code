#include<bits/stdc++.h>
using namespace std;
int main(){
	int x[10001],y[10001];
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	for(int a=0;a<n;a++)
	    for(int b=0;b<=a;b++) if(x[a]==x[b]) y[b]++;
	for(int i=0;i<n;i++){
	    if(y[i]>n/2) cout<<x[i];
	    return 0;
    }
}
