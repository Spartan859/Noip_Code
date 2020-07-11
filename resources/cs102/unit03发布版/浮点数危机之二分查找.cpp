#include<iostream>
#include<algorithm>
#define N 2
using namespace std;
double f[N]={-7.2,-7.2};
int main(){
	cout<<lower_bound(f,f+N,-7.2)-f<<endl;
	cout<<lower_bound(f,f+N,5-12.2)-f<<endl;
	cout<<upper_bound(f,f+N,-7.2)-f<<endl;
	cout<<upper_bound(f,f+N,5-12.2)-f<<endl;
	return 0;
}


