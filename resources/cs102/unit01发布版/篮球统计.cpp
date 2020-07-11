#include<iostream>
#include<iomanip>
#define R 4
using namespace std;
int cnt[R],x;
int main() {
	//cnt计数器数组清零 
	while(cin>>x) cnt[x]++;
	double tot=cnt[3]*3+cnt[2]*2+cnt[1];
	cout<<fixed<<setprecision(1)<<cnt[3]*3/tot*100<<"%"<<endl;
	cout<<fixed<<setprecision(1)<<cnt[2]*2/tot*100<<"%"<<endl;
	cout<<fixed<<setprecision(1)<<cnt[1]/tot*100<<"%"<<endl;
	return 0;
}

