#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int lst;
int a[1005];
ll ans;
int gs;
set<int> s;
bool check(){
	bool ans=1;
	for(int i=1;i<=n;i++)
		if(a[i]){
			ans=0;
			break;
		}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]) gs++,s.insert(i);
	} 

	while(gs){
		ans++;
		int i;
		i=*s.begin();
		if(i+1!=lst){
			if(a[i+1]==1) a[i+1]=0,gs--,s.erase(i+1);
			else a[i+1]=1,gs++,s.insert(i+1);
			lst=i+1;
		}else{
			if(a[1]==1) a[1]=0,gs--,s.erase(1);
			else a[1]=1,gs++,s.insert(1);
			lst=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
