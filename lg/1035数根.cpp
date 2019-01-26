#include<iostream> 
using namespace std;
int chaishu(int n)
{
  	int s=0;
	  while(n){
		s+=n%10;
		n/=10;
	}
	return s;	
}
int main()
{
	int n,s=0;
	cin>>n;
    s=chaishu(n);
	while(s>=10)
	s=chaishu(s);
	cout<<s;
	return 0;
	
}
