#include<bits/stdc++.h>
#define N 10005
using namespace std;
struct t {
    int a,b;
};
int n,m;
t d[N];
bool vst[N],tmp;
void dfs(int x) { //dfs(x)������x����������
    vst[x]=1;//x�Ѿ����ҹ�,�´β��ò���
    for(int i=1; i<=m; i++) { //ѭ������x����������
        if(d[i].a==x) { //���d[i].a��x��һ�����
            if(d[i].b==1) { //���d[i].b�ǻʵ�
                tmp=1;//�й�ϵ
                break;
            } else if(!vst[d[i].b]) dfs(d[i].b); //���d[i].b������û�в��ҹ�  ����d[i].b����������
        } else if(d[i].b==x) { //���d[i].b��x��һ�����
            if(d[i].a==1) { //���d[i].a�ǻʵ�
                tmp=1;//�й�ϵ
                break;
            } else if(!vst[d[i].a]) dfs(d[i].a); //���d[i].a������û�в��ҹ�  ����d[i].a����������
        }
    }
    return;
}
int main() {
    cin>>m>>n;
    for(int i=1; i<=m; i++) cin>>d[i].a>>d[i].b;
    dfs(0);//�����Լ�����������
    if(tmp) cout<<"Yes";
    else cout<<"No";
    return 0;
}
