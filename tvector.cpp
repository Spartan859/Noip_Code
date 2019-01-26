#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> vec; int n=4;
	vector<int>::iterator it;
	long long maxsize=vec.max_size();
	cout<<maxsize<<endl;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(2);
	for(int i=0;i<n;i++) cout<<vec[i]<<' ';
	cout<<endl;
	vec.erase(vec.begin()+n-1);
	for(int i=0;i<n-1;i++) cout<<vec[i]<<' ';
	//for(it=vec.begin();it!=vec.end();it++) cout<<*it<<' ';
	return 0;
}
