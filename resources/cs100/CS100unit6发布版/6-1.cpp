#include<iostream>
#include<algorithm>
#define M 10005
using namespace std;
int n,a=0;
struct treasure{
	int id,w,m;
};
treasure t[M];
int cmp(const treasure&x,const treasure&y){
	if(x.m>y.m) return 1;
	if(x.m<y.m) return 0;
	if(x.w>y.w) return 0;
	if(x.w<y.w) return 1;
	if(x.id<y.id) return 1;
	else return 0;
}
int main(){
	cin>>n;
	while(a<n){
		cin>>t[a].id>>t[a].m>>t[a].w;
		a++;
	}
	sort(t,t+n,cmp);
	for(int i=0;i<n;i++) cout<<t[i].id<<endl;
	return 0;
}
