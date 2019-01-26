#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n,ans=0;
string word[maxn];//字符串数组，用来存储单词
string beginn;//用来存储开头字符
int used[maxn];//这个就是用来记录dfs时候每一个单词被使用了几次的数组
bool check(string s,string m,int k){//重点一，check函数判断接口可行性，k代表接口长度，以下同
    int lens = s.length();
    for (int i=0;i<k;i++){
        if(s[lens-k+i]!=m[i])//无法拼接 
            return false;
    }
    return true;
}

void add(string &s,string m,int k){//拼接操作，因为要把m接到s上，所以对于s串不可以传参，因为我们要试图改变这个串，所以用& 
    int lenm = m.length();
    for (int i=k;i<lenm;i++)
        s+=m[i];//C++字符串类型特性操作，支持+=符号直接拼接（傻子都知道） 
}

void dfs(string now){//这只是一个看似平淡无奇的dfs
    int x = now.length();
    ans = max(ans,x);//每次拼接之后更新一下答案
    for (int i=1;i<=n;i++){
        if (used[i]>=2)//如果有一个单词用完了，那这个单词就不能选了
            continue;
        int maxk = word[i].length();
        for (int j=1;j<=maxk;j++){//枚举接口长度
            if (check(now,word[i],j)){
                string temp = now;//重点二，使用字符串副本进行拼接
                add(temp,word[i],j);
                if (temp==now)//拼完之后如果发现长度没增加，也就是和原串一样，那这次拼接没有意义，剪掉
                    continue;
                used[i]++;
                dfs(temp);
                used[i]--;//这只是一个看似平淡无奇的回溯
            }
        }
    }
}

int main(){
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> word[i];
    cin >> beginn;
    dfs(beginn);
    //神奇的一个dfs就解决了哈哈哈哈哈 
    cout << ans << endl;
    return 0;
}
//Copyright 2018/6/16 Xiangyu Li
//Do not copy without permission 
