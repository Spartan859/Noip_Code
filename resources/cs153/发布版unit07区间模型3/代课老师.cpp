#include<iostream>
#include<algorithm>
#define N 20
using namespace std;
struct teacher{int s,t;};
bool cmp(const teacher& a,const teacher& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
teacher d[N];
int main(){
	int n,i,j,x;
	cin>>n;	
	for(i=0;i<n;i++) cin>>d[i].s>>d[i].t;
	sort(d,d+n,cmp);
	int S=5,T=10,cnt=0;
	for(i=0;i<n&&S<=T;i++){
		for(j=i;j<n&&d[j].s<=S;j++)
			if(d[j].t>d[i].t) i=j;
		if(d[i].s>S) break;
		S=d[i].t+1; cnt++; 
	}	
	if(S<=T) cout<<-1<<endl;
	else cout<<cnt<<endl;	
	return 0;
}


