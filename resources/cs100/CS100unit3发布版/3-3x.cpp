#include<iostream>
using namespace std;
int n;
long long r(long long x){
	int num=0;
	while(x!=0){
	  int tail = x % 10;
      int newnum = num * 10 + tail; 
      if ((newnum - tail) / 10 != num)
      { 
        return 0;
      }
      num = newnum;
      x /= 10;
    }
    return num;
}
int main(){
	cin>>n;
	cout<<r(n);
	return 0;
}

