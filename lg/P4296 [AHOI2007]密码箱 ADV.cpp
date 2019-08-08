#include<bits/stdc++.h> 
using namespace std;
int n,a,b,x,p;
set<int> S;
int main(){
    scanf("%d",&n);
    p=int(sqrt(n));
    for (a=1;a<=p;a++) 
		if(n%a==0){
    		b=n/a;
        	for (x=1;x<=n;x+=b) if((x+1)%a==0) S.insert(x);
        	for (x=b-1;x<=n;x+=b) if((x-1)%a==0) S.insert(x);
    	}
    while(!S.empty()){
        printf("%d\n",*S.begin());
        S.erase(S.begin());
    }
    return 0;
}
