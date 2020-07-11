#include <iostream>
using namespace std;
int hanoi(int y){
	if(y==1) return 2;
	else{
		return hanoi(y-1)*4+2;
	}
}
int main(){
	int n;
	cin >> n;
	cout<<hanoi(n);
	return 0;
}



