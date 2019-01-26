#include<bits/stdc++.h>
#define N 30005
using namespace std;
int dna(string a,string b){
	int temp;
	for(int i=0;i<min(a.size(),b.size());i++){
		if(a[i]==b[i]) temp++;
		else break;
	}
	return temp;
}
int main(){
	string x[N]; int n,ans;
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	    	if(i!=j) ans+=dna(x[i],x[j]);
		}
		cout<<ans<<' ';
		ans=0;
	}
	return 0;
}
