#include<bits/stdc++.h>
#define N 10005
using namespace std;
struct t {
    int a,b;
};
int n,m;
t d[N];
bool vst[N],tmp;
void dfs(int x) { //dfs(x)代表找x的所有亲戚
    vst[x]=1;//x已经查找过,下次不用查找
    for(int i=1; i<=m; i++) { //循环查找x的所有亲戚
        if(d[i].a==x) { //如果d[i].a和x是一个编号
            if(d[i].b==1) { //如果d[i].b是皇帝
                tmp=1;//有关系
                break;
            } else if(!vst[d[i].b]) dfs(d[i].b); //如果d[i].b的亲戚没有查找过  查找d[i].b的所有亲戚
        } else if(d[i].b==x) { //如果d[i].b和x是一个编号
            if(d[i].a==1) { //如果d[i].a是皇帝
                tmp=1;//有关系
                break;
            } else if(!vst[d[i].a]) dfs(d[i].a); //如果d[i].a的亲戚没有查找过  查找d[i].a的所有亲戚
        }
    }
    return;
}
int main() {
    cin>>m>>n;
    for(int i=1; i<=m; i++) cin>>d[i].a>>d[i].b;
    dfs(0);//查找自己的所有亲戚
    if(tmp) cout<<"Yes";
    else cout<<"No";
    return 0;
}
