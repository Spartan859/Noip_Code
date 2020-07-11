#include<iostream>
using namespace std;
int dx[8]={1,1,1,0,0,-1,-1,-1}; 
int dy[8]={1,0,-1,1,-1,1,0,-1};
int x,y;
int main(){
	cin>>x>>y;
	for(int k=0;k<8;k++){
		int nx=x+dx[k],ny=y+dy[k];
		cout<<"("<<nx<<","<<ny<<")"<<endl;
	}
	return 0;
}


