#include<bits/stdc++.h>
using namespace std;
multiset<int> y;
multiset<int>::iterator it;
int main(){
    int n,s,a,b,len,x,yin,ans=0;//ans�𰸣�x��yin��ʱ���룬len���߶�
    cin>>n>>s;
    cin>>a>>b;
    len=a+b;
    for(int i=0;i<n;i++){
        cin>>x>>yin;
        if(x<=len) y.insert(yin);//�����ժ���������� 
    }
    //�����ùܣ��Ž�ȥ���ź��� 
    for(it=y.begin();it!=y.end();it++){//it���������Ǹ�ָ�룬����Ҫ��ôд 
        if(s-*it>=0) {
            s-=*it;
            ans++;
        }
        else break;//�����Ż��� 
    }
    cout<<ans<<endl;
    return 0;
}
