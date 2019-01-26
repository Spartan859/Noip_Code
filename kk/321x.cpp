#include<bits/stdc++.h>
using namespace std;
void kill(int *y,int n2){
	for(int i=0;i<n2;i++)
	    if(y[i]!=0) y[i]--;
}
void dead(int *y,int n2){
	for(int i=0;i<n2;i++) y[i]=y[i+1];
}
void print(int *y,int n2){
	for(int i=0;i<n2;i++) cout<<y[i]<<' ';
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	int x[n+1],cnt=0;
	for(int i=0;i<n;i++) cin>>x[i];
	sort(x,x+n);
	for(int a=0;a<n;a++){
		if(x[0]==0){
			dead(x,n);
			kill(x,n);
		}
		else{
			cnt++;
			dead(x,n);
			kill(x,n);
		}
	}
	cout<<cnt<<endl;
	return 0;
}
