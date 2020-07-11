#include<iostream>
#include<fstream>
using namespace std;
int main(){
	long long n,ans;
	ifstream fin;
	ofstream fout;
	fin.open("count.in");
	fout.open("count.out");
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=i;j++)
	        if(i%j==0) ans++;
	fout<<ans;
	fin.close();
	fout.close();
	return 0;
} 
