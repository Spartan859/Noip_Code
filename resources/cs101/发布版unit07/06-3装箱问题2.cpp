#include<iostream>
#define V 20005
#define N 50
using namespace std;
bool h[N][V];//h[i][j]表示用前i件物品能否正好占用j体积 
int v,n,i,j,w[N];
int main(){
	cin>>v>>n;
	for(i=1;i<=n;i++) cin>>w[i];
	h[0][0]=1;
	for(i=1;i<=n;i++){
		h[i][0]=1;
		for(j=1;j<=v;j++) 
			if(j>=w[i]) h[i][j]=h[i-1][j] or h[i-1][j-w[i]];
			else h[i][j]=h[i-1][j]; 			
	}
	for(j=v;j>=0 && !h[n][j];j--);
	cout<<v-j<<endl;
	return 0;
}


