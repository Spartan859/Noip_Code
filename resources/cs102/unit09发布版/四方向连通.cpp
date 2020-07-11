#include<iostream>
using namespace std;
int dx[4]={0,1,0,-1}; 
int dy[4]={1,0,-1,0};
int x,y;
int main(){
	cin>>x>>y;
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		cout<<"("<<nx<<","<<ny<<")"<<endl;
	}
	return 0;
}


