#include<iostream>
using namespace std;
int n;
char c;
void pyramid(int m,char x){
int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<m-i-1;j++) cout<<' ';
		for(j=0;j<i+i+1;j++) cout<<x;
		cout<<endl;
	}
}
int main(){
	cin>>n>>c;
	pyramid(n,c);
	pyramid(2*n,c);
	return 0;
} 


