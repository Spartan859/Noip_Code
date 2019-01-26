#include<bits/stdc++.h>
using namespace std;
multiset<int> y;
multiset<int>::iterator it;
int main(){
    int n,s,a,b,len,x,yin,ans=0;//ans答案，x、yin临时输入，len最大高度
    cin>>n>>s;
    cin>>a>>b;
    len=a+b;
    for(int i=0;i<n;i++){
        cin>>x>>yin;
        if(x<=len) y.insert(yin);//如果可摘，放入容器 
    }
    //排序不用管，放进去就排好了 
    for(it=y.begin();it!=y.end();it++){//it迭代器，是个指针，遍历要这么写 
        if(s-*it>=0) {
            s-=*it;
            ans++;
        }
        else break;//可以优化了 
    }
    cout<<ans<<endl;
    return 0;
}
