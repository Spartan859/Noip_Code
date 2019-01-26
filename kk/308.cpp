#include<bits/stdc++.h>
using namespace std;
struct dog{
	int birth;
	string name;
};
int main(){
	int n,m;
	cin>>n>>m;
	dog d[n+1];
	bool ans[m+1]; for(int i=0;i<m;i++) ans[i]=0;
	for(int i=0;i<n;i++) cin>>d[i].name>>d[i].birth;
	for(int i=0;i<m;i++){
		dog dx; int out=0;
		cin>>dx.birth>>dx.name;
		for(int j=0;j<n;j++)
		    if(dx.birth==d[j].birth&&dx.name==d[j].name) ans[i]=1;
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<' ';
	return 0;
}
