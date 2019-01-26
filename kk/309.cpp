#include<bits/stdc++.h>
using namespace std;
struct person{
	int id;
	int rice;
};
struct cmp{
	bool operator()(const person&a,const person&b)const{
		return a.rice<b.rice||a.rice==b.rice&&a.id<b.id;
	}
};
int main(){
	multiset<person,cmp> ms;
	multiset<person,cmp>::iterator it;
	int n,ans;
	bool lin[n];
	cin>>n;
	for(int i=0;i<n;i++){
		person p;
		cin>>p.rice;
		p.id=i;
		ms.insert(p);
	}
	for(int i=0;i<n;i++){
		person temp;
		it=ms.begin();
		temp=*it;
		temp.rice+=3;
		lin[temp.id]=1;
		ms.erase(it);
		ms.insert(temp);
	}
	for(int i=0;i<n;i++)
		if(lin[i]==0) ans++;
	cout<<ans;
	return 0;
}
