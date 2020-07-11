#include<iostream>
#include<algorithm>
#define M 10
using namespace std;
int f[M];
int cmp(const int &x,const int &y){
	if(x%2>y%2 || x%2==1&&y%2==1&&x>y || x%2==0&y%2==0&&x<y) return 1;
	else return 0;
}
int main(){
	for(int i=0;i<M;i++) cin>>f[i];
	sort(f,f+M,cmp);
	for(int i=0;i<M;i++) cout<<f[i]<<" ";	
	return 0;
}


