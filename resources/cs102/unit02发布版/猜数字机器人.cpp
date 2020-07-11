#include<iostream>
using namespace std;
int main(){
	cout<<"Please pick an integer from [0,1000], as your answer. Don't tell me yet. "<<endl;
	int l=0,r=1000,x;
	for(int i=1;i<=10;i++){
		cout<<"Is it ";
		int mid=l+(r-l)/2;
		cout<<mid<<"?"<<endl;
		cout<<"Too small[0], too big[1], right answer[2]:";
		cin>>x;
		if(x==0) l=mid+1;
		else if(x==1) r=mid-1;
		else break;
	}
	if(x==2) cout<<"I knew it. I am a genius!"<<endl;
	else cout<<"Sorry. I must have made a mistake."<<endl;
	return 0;
} 


