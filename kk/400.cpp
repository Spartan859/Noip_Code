#include<bits/stdc++.h>
#define N 100005
using namespace std;
multiset<int> ms;//ÅÅĞòµ¹½øµÄÊä£¬Êä³öbegin-rbegin 
multiset<int>::iterator it; 
multiset<int> ms2;
multiset<int>::iterator it2;
int m,n,k[N],temp;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>k[i];
	for(int j=0;j<m-1;j++) ms.insert(k[j]);
	for(int i=m;i<n+1;i++){
	    ms.insert(k[i-1]);
	    ms2.insert(*ms.rbegin()-*ms.begin());
	    //for(it=ms.begin();it!=ms.end();it++) cout<<*it<<' ';
	    //cout<<endl;
	    ms.erase(k[i-m]); //cout<<k[i-m]<<endl;
	    //for(it=ms.begin();it!=ms.end();it++) cout<<*it<<' ';
	    //cout<<endl;
	}
	//ms.insert(k[n-1])
	//for(it2=ms2.begin();it2!=ms2.end();it2++) cout<<*it2<<' ';
	cout<<*ms2.begin()<<endl;
	return 0;
}
