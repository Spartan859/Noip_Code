#include<bits/stdc++.h>
using namespace std;
int n,a,b,f[10005],q,r,s,t,z;
double c,d;
/*int gcd(int a,int b,int &x,int &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    int q=gcd(b,a%b,y,x);
    y-=a/b*x;
    return q;
}*/
int gcd(int a,int b){
	q=a/b; z=b;
	r=a%b;
	if(r==0) return a;
	else return gcd(b,r);
}
int main(){
	cin>>n>>a>>b;
	s=max(a,b); t=min(a,b);
	c=gcd(s,t)*n/q;
	d=(n-s*c)/t;
	if(int(c)!=c||int(d)!=d){
		cout<<-1;
		return 0;
	}
	while(d<0) c-=t/z,d+=s/z;
	while(c<0) c+=t/z,d-=s/z;
	if(c<0||d<0) {
		cout<<-1;
		return 0;
	}
	cout<<c+d<<endl;
	return 0;
}
