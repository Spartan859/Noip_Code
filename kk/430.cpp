#include<bits/stdc++.h>
using namespace std;
int dna(string a,string b){
	int cnt;
	for(int i=0;i<min(a.size(),b.size());i++){
		if(a[i]==b[i]) cnt++;
		else break;
	}
	return cnt;
}
int main(){
	int n,anss[30005];
	string x[30005];
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	for(int i=0;i<n;i++){
		int ans=0;
	    for(int j=0;j<n;j++)
	    	if(i!=j){
	    	   ans+=dna(x[i],x[j]);
	    	   //cout<<dna(x[i],x[j])<<endl;
			}
		anss[i]=ans;
	}
	for(int i=0;i<n;i++) cout<<anss[i]<<' ';
	//cout<<dna("321","32");
	return 0;
}
