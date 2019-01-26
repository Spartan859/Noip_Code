#include<bits/stdc++.h>
using namespace std;
struct student{
	string id;
	double score;
}; student st;
struct cmp{
	bool operator()(const student &a,const student &b)const{
		return a.score>b.score;
	}
};
int main(){
	multiset<student,cmp> ms;
	multiset<student,cmp>::iterator it;
	int n,k,cnt=1; cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>st.id>>st.score;
		ms.insert(st);
	}
	it=ms.begin();
	while(cnt<k){
		it++;
		cnt++;
	}
	cout<<(*it).id<<' '<<(*it).score;
	return 0;
} 
