#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int t;
    int nexty;
}edge[200000];
int head[20000];
int cnt=0;//��ʽǰ����
void add(int a,int b)//���
{
    cnt++;
    edge[cnt].t=b;
    edge[cnt].nexty=head[a];
    head[a]=cnt;
}
bool used[20000]={0};//�Ƿ������
int col[20000]={0};//ÿһ�����Ⱦɫ
int sum[2];//�ڰ�����Ⱦɫ���Եĵ���
bool dfs(int node,int color)//Ⱦɫ������false��impossible��
{
    if(used[node])//����ѱ�Ⱦ��ɫ
    {
        if(col[node]==color)return true;//�������ԭ������ɫ��������
        return false;//��ԭ������ɫ���������˳�ͻ��������
    }
    used[node]=true;//��¼
    sum[col[node]=color]++;//��һ����ɫ�ĸ�����1���Ҵ˵����ɫҲ��¼����
    bool tf=true;//�Ƿ����
    for(int i=head[node];i!=0&&tf;i=edge[i].nexty)//������
    {
        tf=tf&&dfs(edge[i].t,1-color);//�Ƿ���Լ���Ⱦɫ
    }
    return tf;//�����Ƿ����Ⱦɫ
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    while(m--)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);//���������ߣ����Դ�����
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(used[i])continue;//����˵��ѱ�����Ϊһ���Ѿ�������������ͼ�������ظ�����
        sum[0]=sum[1]=0;//��ʼ��
        if(!dfs(i,0))//�������Ⱦɫ
        {
            printf("Impossible");
            return 0;//ֱ������
        }
        ans+=min(sum[0],sum[1]);//����С��һ��
    }
    printf("%d",ans);//�����
    return 0;
}






