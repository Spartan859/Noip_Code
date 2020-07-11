#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	srand(time(0));
	int ans=rand()%1000;
	int x;
	for(int i=1;i<=10;i++){
		cout<<"Please guess a number: ";
		cin>>x;
		if(x>ans) cout<<"Too big!"<<endl;
		else if(x<ans) cout<<"Too small!"<<endl;
		else break;
	}
	if(x==ans) cout<<"Bingo!"<<endl;
	else cout<<"Sorry. Game over!"<<endl;
	cout<<"Answer = "<<ans<<endl;
	return 0;
} 


