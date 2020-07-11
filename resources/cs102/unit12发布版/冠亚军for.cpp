#include<iostream>
#include<algorithm>
#define N 10
using namespace std;
int main(){
	int n=4;
	string team[N];
	for(int i=0;i<n;i++)cin>>team[i];
	sort(team,team+n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
				cout<<team[i]<<" "<<team[j]<<endl;
	return 0;
}
