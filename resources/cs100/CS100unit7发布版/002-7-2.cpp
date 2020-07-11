#include<iostream>
#define SIZE 4000
using namespace std;
int i,j,x,n,m,f[1000],exist[SIZE];
//exist[x]代表x这个数能否被两个数凑和 
int main(){
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>f[i];
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) 
			exist[f[i]+f[j]]=1;
	for(i=0;i<n;i++){
		x=m-f[i];
		if(x>=0 && x<SIZE && exist[x]){
			cout<<"Yes"<<endl;
			return 0;
		}			
	}		
	cout<<"No"<<endl;
	return 0;
}
