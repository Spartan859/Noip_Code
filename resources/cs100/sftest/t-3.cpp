#include<iostream>
#include<string>
using namespace std;

int kz;

int reverse(string &s) {
	int i,j,t;
	for(i=0,j=s.size()-1; i<j; i++ ,j--) {
		t=s[i]; s[i]=s[j]; s[j]=t;
	}
	return 0;
} 

int main()
{
	string line;
	cin>>kz;
	while(kz!=-1) {
		getline(cin, line);
		reverse(line);
		cout<<line<<endl;
		cin>>kz;
	}
	return 0;
}
