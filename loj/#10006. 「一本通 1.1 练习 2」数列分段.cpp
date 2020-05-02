#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=100005;
multiset<int> a;
multiset<int>::iterator it;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,tmp;i<=n;i++){
		scanf("%d",&tmp);
		a.insert(tmp);	
	}
	for(int i=1;i<=n;i++){
		it=a.upper_bound(m);
		cout<<*it<<endl;
		m-=*it;
		a.erase(it);
	}
	return 0;
}
/*
5 0
4 2 4 5 1
*/

