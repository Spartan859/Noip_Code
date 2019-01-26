#include<bits/stdc++.h>
using namespace std;
int main(){
	multiset<int> ms,ms2;//两个容器 
	multiset<int>::iterator it;//迭代器 
	int n,temp,temp2,ans;//ans为答案 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		ms.insert(temp);
	}//输入所有伤员血量 
	for(int i=0;i<n;i++){
		it=ms.begin();
		if(*it!=0){
			ms.erase(it);
			ans++;
		}//救治成功，删除，ans++ 
		else ms.erase(it);//救治失败，删除 
		for(it=ms.begin();it!=ms.end();){
			temp2=*it;
			if(temp2!=0) temp2--;
			ms2.insert(temp2);//将一分钟后的伤员数据存到ms2中 
			ms.erase(it);//删除已经存到temp2的内容 
			it=ms.begin(); 
		}
		for(it=ms2.begin();it!=ms2.end();it++) ms.insert(*it); //ms2存回ms 
		for(it=ms2.begin();ms2.empty();){ms2.erase(it); it=ms2.begin();} //ms2清空 
	}
	cout<<ans;
	return 0;
} 
