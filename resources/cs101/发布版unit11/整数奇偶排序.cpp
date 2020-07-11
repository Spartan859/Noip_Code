#include<iostream>
#include<set>
using namespace std;
struct cmp{
	bool operator()(const int&a,const int&b)const{
		if(a%2&&b%2==0) return 1;
		if(a%2==0&&b%2) return 0;
		if(a%2&&a>b) return 1;
		if(a%2==0&&a<b) return 1;
		return 0;
	}	
};
int main(){
	multiset<int,cmp> ms;
	multiset<int,cmp>::iterator it;
	for(int i=0;i<10;i++) {
		int x; 
		cin>>x; ms.insert(x);
	}
	for(it=ms.begin();it!=ms.end();it++) 
		cout<<*it<<" ";	
	return 0;
}


