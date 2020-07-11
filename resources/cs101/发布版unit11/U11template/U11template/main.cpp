#include<iostream>
#include<string>
#include<set>
using namespace std;
struct dog{
    string id;
    int birth;
}; dog d;
set<dog> s;
set<dog>::iterator it;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>d.id>>d.birth;
        s.insert(d);
    }
    for(int i=0;i<m;i++){
        string sx; int bx,out=0;
        cin>>sx>>bx;
        for(it =s.begin();it!=s.end();it++)
            if((*it).id==sx&&(*it).birth==bx){
                out=1;
                cout<<1;
            }
        if(out==0) cout<<0;
    }
    return 0;
}
