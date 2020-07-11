#include<bits/stdc++.h>
//using namespace std;

int main(){
	long long result=1;
	for(int i=3;i<30;i+=2){
		result*=i;
	} 
	printf("%lld\n",result);
	return 0;
}

