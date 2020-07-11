#include<bits/stdc++.h>
#define N 105
using namespace std;
struct food{int s,t;};
struct cmp{
	bool operator()(const food &a,const food &b)const{
		return a.t<b.t||a.t==b.t&&a.s<b.s;
	}
}; 
food d;
int n,i,x,ans;
int main(){
	multiset<food,cmp> ms;
	multiset<food,cmp>::iterator it;
	cin>>n;	
	for(i=0;i<n;i++){
	    cin>>d.s>>d.t;
	    ms.insert(d);
	}
	x=-1; ans=0;
	for(it=ms.begin();it!=ms.end();it++)
		if((*it).s>=x) {
			ans++;
			x=(*it).t;
		}
	cout<<ans<<endl;	
	return 0;
}
