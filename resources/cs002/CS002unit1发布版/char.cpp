#include<iostream>
using namespace std;

int main(){
	cout<<"ASCII chart"<<endl<<endl;
	for(int i=0;i<16;i++) {
		for(int j=0;j<8;j++){
			cout<<i*8+j<<" "<<char(i*8+j)<<"\t";
			for(int k=0;k<20000000;k++);
		}
		cout<<endl;
	}
	return 0;
}
