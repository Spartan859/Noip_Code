#include<bits/stdc++.h> 
using namespace std;

int ans=0,zero=0;
unsigned int add[11]={1};
bool ze,flag,haha[598765],Jud[12]={0,1};
char use[11],mem[98];

void HASH()//用于记录元素的哈希值
{
    unsigned int Hash=1,n=strlen(use);
    for(int i=0;i<n;i++)Hash=Hash*131+use[i];
    haha[Hash & 0x7FFFF]=1;
}

bool mult(char c)
{
    ze=flag=0;
    zero++;//记录当前讨论字符的位置（前缀长度）
    for(int i=9;i>=0;i--)if(add[i])add[i+1]=add[i]*131+c;//更新哈希值
    for(int i=10;i;i--)
    {
        flag|=Jud[i];
        if(haha[add[i] & 0x7FFFF]&&Jud[i])
        {
            flag=1;
            ze=1;
            ans=max(ans,zero);
        }
        Jud[i+1]=Jud[i];
    }
    Jud[1]=ze;
    if(!ze&&!flag)return 0;
    return 1;
}

int main()
{
    while(use[0]!='.')
    {
        memset(use,0,sizeof(use));
        scanf("%s",&use);
        HASH();
    }
    while(scanf("%s",&mem)!=EOF)
    {
        for(int i=0;i<strlen(mem);i++)
            if(!mult(mem[i])){printf("%d",ans);return 0;}
        memset(mem,0,sizeof(mem));
    }
    printf("%d",ans);
    return 0;
}
