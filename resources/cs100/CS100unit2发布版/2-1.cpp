#include <iostream>
using namespace std;
long long s(int x){
	long long ans=0;
	for(int i=1;i<=x;i++) 
       ans+=i*i;
	   return ans; 
}
int main(){
	int n;
	cin >> n;
	cout << s(n);
}
