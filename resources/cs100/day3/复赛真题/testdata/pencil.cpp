#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
long long n,p1,b2,m1,m2,m3,temp,mt=100000000000000,j;
int main(){
	ifstream fin("pencil.in");
	ofstream fout("pencil.out");
	fin>>n;
	for(int i=0;i<3;i++){
	    fin>>p1>>b2;
	    for(j=0;1;j++)
		    if(p1*j>=n) break;
	    if(b2*j<mt) mt=b2*j;
	}
	fout<<mt;
	return 0;
} 
