#include<bits/stdc++.h>
using namespace std;
int main(){
	multiset<int> ms,ms2;//�������� 
	multiset<int>::iterator it;//������ 
	int n,temp,temp2,ans;//ansΪ�� 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		ms.insert(temp);
	}//����������ԱѪ�� 
	for(int i=0;i<n;i++){
		it=ms.begin();
		if(*it!=0){
			ms.erase(it);
			ans++;
		}//���γɹ���ɾ����ans++ 
		else ms.erase(it);//����ʧ�ܣ�ɾ�� 
		for(it=ms.begin();it!=ms.end();){
			temp2=*it;
			if(temp2!=0) temp2--;
			ms2.insert(temp2);//��һ���Ӻ����Ա���ݴ浽ms2�� 
			ms.erase(it);//ɾ���Ѿ��浽temp2������ 
			it=ms.begin(); 
		}
		for(it=ms2.begin();it!=ms2.end();it++) ms.insert(*it); //ms2���ms 
		for(it=ms2.begin();ms2.empty();){ms2.erase(it); it=ms2.begin();} //ms2��� 
	}
	cout<<ans;
	return 0;
} 
