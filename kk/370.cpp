#include<bits/stdc++.h>
#define N 205
using namespace std;
struct ke{int s,t;};
bool cmp(const ke& a,const ke& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
ke d[N];
int main(){
	int n,i,j,x[N],cnt=0;
	string s1,n2; getline(cin,n2);
	stringstream ss; ss<<n2; ss>>n;
	for(i=0;i<n;i++){
		getline(cin,s1);
		d[i].s=((s1[0]-'0')*10+(s1[1]-'0'))*60+(s1[2]-'0')*10+(s1[3]-'0');
		d[i].t=((s1[5]-'0')*10+(s1[6]-'0'))*60+(s1[7]-'0')*10+(s1[8]-'0');
	}
	sort(d,d+n,cmp);
	for(i=0;i<n;i++){
		for(j=0;j<cnt;j++)
			if(d[i].s>=x[j]+10) break;
		if(j<cnt) x[j]=d[i].t;
		else x[cnt++]=d[i].t;
	}
	cout<<cnt<<endl;	
	return 0;
}
