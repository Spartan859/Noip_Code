#include<iostream>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int i,j,k,x,y;
char f[5][5],g[5][5];
int main(){
	for(i=0;i<5;i++)
		for(j=0;j<5;j++) {
			cin>>f[i][j];
			g[i][j]='E';
		}			
	for(i=0;i<5;i++)
		for(j=0;j<5;j++) 
			if(f[i][j]=='A') {
				g[i][j]='A';
				for(k=0;k<4;k++){
					x=i+dx[k];
					y=j+dy[k];
					if(x>=0&&x<=4&&y>=0&&y<=4)
						g[x][y]='A';						
				}	
			}
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++)
			cout<<g[i][j];	
		cout<<endl;
	}
	return 0;
}
