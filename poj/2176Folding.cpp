#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#define N 105
#define ll long long
using namespace std;
string s;
string dp[N][N];
ll n;
string _to_string(ll num) {
    string ans;
    while(num) {
        ans += num % 10 + '0';
        num /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
	getline(cin,s);
	n=s.length();
	s=' '+s;
	for(ll i=1;i<=n;i++) dp[i][i]=s[i];

	for(ll len=2;len<=n;len++)
		for(ll i=1;i+len-1<=n;i++){
			ll j=i+len-1;
			
			dp[i][j]=s.substr(i,len);
			for(ll k=1;k<=len/2;k++){
				
				if(len%k) continue;
				ll l=i,r=i+k;
				while(s[l]==s[r]&&r<=j) l++,r++;
				//if(i==10&&j==15&&k==2) 
				if(r>j){
					
					string tmp=_to_string(len/k)+'('+dp[i][i+k-1]+')';
					//if(i==10&&j==15) cout<<tmp<<endl;
					if(dp[i][j].length()>tmp.length()) dp[i][j]=tmp;
					break;
				}
					
			}
			for(ll k=i;k<j;k++)
				if(dp[i][j].length()>dp[i][k].length()+dp[k+1][j].length()) dp[i][j]=dp[i][k]+dp[k+1][j];
		}
	cout<<dp[1][n]<<endl;
	return 0;		
}
