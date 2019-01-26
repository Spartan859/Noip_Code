#include<bits/stdc++.h>
using namespace std;
int main(){
	multiset<int> ms;
	multiset<int>::iterator it,it2;
	int n,m,ans; cin>>n>>m;
	for(int i=0;i<n;i++){
		int temp; cin>>temp;
		if(temp>=m){
			cout<<0<<endl;
			return 0;
		}
		ms.insert(temp);
	}
	while(1){
		int pos=*ms.begin();
		ans++;
		if(pos+10>=m) break;
		ms.erase(ms.begin());
		ms.insert(pos+10);
	}
	cout<<ans<<endl;
	return 0;
}
