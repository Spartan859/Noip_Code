#include<iostream>
#include<algorithm>
#define M 500
using namespace std;
int d[M],n,N,x,i;
int main(){
	cin>>N;
	for(i=0;i<N;i++) {
		cin>>x;
		if(x%2==1) {
			d[n]=x; n++;
		}
	}
	sort(d,d+n);
	cout<<d[0];
	for(i=1;i<n;i++) cout<<','<<d[i];	
	return 0;
}


