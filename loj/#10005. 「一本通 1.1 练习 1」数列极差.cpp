#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=50005;
multiset<int> a,b;
multiset<int>::iterator it;
int main(){
	scanf("%d",&n);
	for(int i=1,tmp;i<=n;i++){
		scanf("%d",&tmp);
		a.insert(tmp);
		b.insert(tmp);
	}
	for(int i=1,c;i<=n-1;i++){
		it=a.begin();
		c=*it;
		a.erase(it);
		it=a.begin();
		c*=*it;
		a.erase(it);
		a.insert(c+1);
		
		it=b.end();--it;
		c=*it;
		b.erase(it);
		it=b.end();--it;
		c*=*it;
		b.erase(it);
		b.insert(c+1);
	}
	printf("%d\n",*a.begin()-*b.begin());
	return 0;
}

