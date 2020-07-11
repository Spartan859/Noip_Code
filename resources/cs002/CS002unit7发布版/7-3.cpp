#include<iostream>
using namespace std;
char d[5][5];
int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++) cin>>d[i][j];
	}
	for(int a=0;a<5;a++){
		for(int b=0;b<5;b++){
			if(a!=0&&b!=0&&a!=4&&b!=4){
				if(d[a][b]=='A'||d[a+1][b]=='A'||d[a-1][b]=='A'||d[a][b+1]=='A'||d[a][b-1]=='A')
			    cout<<'A';
			    else cout<<'E';
			}
			if(a==0&&b==0){
				if(d[a][b]=='A'||d[a+1][b]=='A'||d[a][b+1]=='A')
			    cout<<'A';
			    else cout<<'E';
			}
			if(a==4&&b==4){
				if(d[a][b]=='A'||d[a-1][b]=='A'||d[a][b-1]=='A')
			    cout<<'A';
			    else cout<<'E';
			}
			if(a==0&&b==4){
				if(d[a][b]=='A'||d[a+1][b]=='A'||d[a][b-1]=='A')
			    cout<<'A';
			    else cout<<'E';
			}
			if(a==4&&b==0){
				if(d[a][b]=='A'||d[a-1][b]=='A'||d[a][b+1]=='A')
			    cout<<'A';
			    else cout<<'E';
			}
			if(a==0&&b!=0&&b!=4){
				if(d[a][b]=='A'||d[a+1][b]=='A'||d[a][b+1]=='A'||d[a][b-1]=='A')
			    cout<<'A';
			    else cout<<'E';
			}
			if(a==4&&b!=0&&b!=4){
				if(d[a][b]=='A'||d[a-1][b]=='A'||d[a][b+1]=='A'||d[a][b-1]=='A')
			    cout<<'A';
			    else cout<<'E';
			}
			if(a!=0&&a!=4&&b==0){
				if(d[a][b]=='A'||d[a+1][b]=='A'||d[a-1][b]=='A'||d[a][b+1]=='A')
			    cout<<'A';
			    else cout<<'E';
		    }
		    if(a!=0&&a!=4&&b==4){
		    	if(d[a][b]=='A'||d[a+1][b]=='A'||d[a-1][b]=='A'||d[a][b-1]=='A')
			    cout<<'A';
			    else cout<<'E';
			}
	}
	cout<<endl;
}
	return 0;
}
