#include<bits/stdc++.h>
using namespace std;
long factorial(long number){
	if(number<=1)
		return 1;
	else 
		return number*factorial(number-1);
}
 
int combinator(int n,int m)
{	int temp;
	if(n<m)
	{	temp=n;
		n=m;
		m=temp;}
	return factorial(n)/(factorial(m)*factorial(n-m));
}
		
int main()
{	int a,b,result;
	cout<<"please input two positive integer:";
	cin>>a>>b;
	result=combinator(a,b);
	cout<<result<<endl;
	return 0;
}

