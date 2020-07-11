#include<iostream>
#include<set>
using namespace std;
int main() {
	multiset<int> games,stadiums;
	multiset<int>::iterator itg,its;
	int n,x;	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x; games.insert(x);
	}
	int ans=0;
	for(itg=games.begin();itg!=games.end();itg++){
		if(stadiums.empty()) stadiums.insert(*itg);
		else {
			its=stadiums.begin();
			if(*itg-*its<200)
				stadiums.insert(*itg);
			else {
				stadiums.erase(its);
				stadiums.insert(*itg);
			}
		}
		int tot=stadiums.size();
		ans=max(ans,tot);
	}
	cout<<ans<<endl;	
	return 0;
}

