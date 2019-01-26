#include<bits/stdc++.h>
using namespace std;
string s[105],m;int f[10005],l,i,j,k;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(cin>>s[k])k++;
	m=s[k-1];k--;l=m.size();m=" "+m;
	for(i=1;i<=l;i++){
		f[i]=f[i-1];
		for(j=0;j<k;j++){
			if(i>=s[j].size()&&m.substr(i-s[j].size()+1,s[j].size())==s[j]){
				f[i]=max(f[i],f[i-s[j].size()]+1);
				
			}
		}
	}
	cout<<f[l]<<endl;
	return 0;
}
