#include<iostream>
#include<string>
#include<map>
#include<set>
#define N 110
using namespace std;
string x[N];
map<string,int> cnt;
set<string> rgb;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>x[i];
	rgb.insert("red");
	rgb.insert("green");
	rgb.insert("blue");
	int sum=0,ans=n+1;
	int tail=0,head=0; 
	while(1){
		while(head<n&&sum<3) {
			string color=x[head++];
			if(!rgb.count(color))continue;
			if((++cnt[color])==1)sum++;
		}
		if(sum<3)break;	
		ans=min(ans,head-tail);   
		string color=x[tail++];	
		if(!rgb.count(color))continue;
		if((--cnt[color])==0)sum--;  		
	}
	cout<<ans<<endl; 	
	return 0;
}

