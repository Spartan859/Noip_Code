#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,P=1e9+7;
int main(){
	cin>>n;
	cout<<(((n+2)%P)*((n+1)%P)/2)%P<<endl;;
	return 0;
} 
