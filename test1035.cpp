#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>x;
	for(int i=x;i>=1;i/=10) y+=i%10;
	cout<<y<<endl;
	return 0;
} 
