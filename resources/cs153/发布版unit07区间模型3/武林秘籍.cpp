#include<iostream>
#include<algorithm>
#define N 105
using namespace std;
struct piece{int s,t;};
bool cmp(const piece& a,const piece& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
piece d[N];
int main(){
	int n,i,j,x;
	cin>>n;	
	for(i=0;i<n;i++) cin>>d[i].s>>d[i].t;
	sort(d,d+n,cmp);
	int S=1,T=100,cnt=0;
	for(i=0;i<n&&S<=T;i++){
		for(j=i;j<n&&d[j].s<=S;j++)
			if(d[j].t>d[i].t) i=j;
		if(d[i].s>S) break;
		S=d[i].t+1; cnt++; 
	}	
	if(S<=T) cout<<"sorry"<<endl;
	else cout<<cnt<<endl;	
	return 0;
}


