#include<iostream>
using namespace std;
const int dayNum[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
int m,offset,i;
int main() {
	cin>>m;
	cout<<"S\tM\tT\tW\tT\tF\tS"<<endl; //'\t'ÎªTABÖÆ±í·û
	____(1)______;
	for (i=1; i<m; i++)
		offset = ____(2)_____;
	for (i=0; i<offset; i++)
		cout<<'\t';
	for (i=1; i<=__(3)____; i++) {
		cout<<___(4)______;
		if (i==dayNum[m] || ___(5)____==0)
			cout<<endl;
		else
			cout<<'\t';
	}
	return 0;
}


