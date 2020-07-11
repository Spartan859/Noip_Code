#include<iostream>
using namespace std;
long long n,temp;
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		for(int j=2;j<i;j++){
			if(i!=j&&i%j!=0) temp+=1;
		}
		if(temp==i-2) cout<<i<<" ";
		temp=0;
	}
	return 0;
}
