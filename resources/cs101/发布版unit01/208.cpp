#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	double sn;
	cin>>k;
	for(int i=1;;i++){
		sn+=1.0/i;
		if(sn>k){
			cout<<i;
			return 0;
		}
	}
}
