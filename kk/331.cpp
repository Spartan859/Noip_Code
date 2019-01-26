#include<bits/stdc++.h>
using namespace std;
struct player{
	string name;//这不重要
	int score;
	int id;//输入顺序 
};
int main(){
	map<string,player> d;
	map<string,player>::iterator it;
	int n; cin>>n; player tmp; string nation;
	for(int i=0;i<n;i++){
		cin>>tmp.name>>nation>>tmp.score; tmp.id=i;
		if(tmp.score>d[nation].score||tmp.score==d[nation].score&&tmp.id<d[nation].id) d[nation]=tmp;
	}
	cout<<d.size()<<endl;
	for(it=d.begin();it!=d.end();it++)
		cout<<it->first<<' '<<(it->second).name<<endl;
	return 0;
}
