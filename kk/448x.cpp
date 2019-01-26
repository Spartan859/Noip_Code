#include<bits/stdc++.h>
#define R 10001
using namespace std;
int n=0,anoc[R]={0},cnt[R]={0},x1=0,maxx; int k=0;
vector<int> ax;
vector<int> tmp;
vector<int>::iterator it;
int main(){
	int j=1;
	////////////////
    cin>>n;
	int x;
	for(int i=0;i<n;i++) {
		cin>>x;
		cnt[x]++;
		maxx=max(x,maxx);
	}
	cin>>k;
	for(int i=1;i<=maxx;i++)
		for(int j=0;j<cnt[i];j++)
			ax.push_back(i);
	////////////////////////////
	for(int i=1;i<=maxx;i++) anoc[i]=cnt[i];
	for (int i=1;i<=maxx;i++)
    {  
        anoc[i]=anoc[i]+anoc[i-1];  
    }
    ////////////////////////////
	while(1){//j秒数
	    x1=ax[n-1];
	    ax.erase(ax.begin()+n-1);
		x1-=k-1;//冰最多的用微波炉
		ax.insert(ax.begin()+anoc[x1],x1);
		anoc[x1]++;
		//wugai
		if(ax[n-1]-j<=0) break;
		j++;//秒数加1
		//wugai
	}
	ax.swap(tmp);
	cout<<j<<endl;
	return 0;
}
