#include<bits/stdc++.h>
using namespace std;
int n,m,v[100000],c[100000],l[1000][1000],dp[100000],t,e,q=0,s;//v��value��c��cost��
int main()
{
    cin>>n>>m>>t>>e;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>l[i][j];//�ڣ�i,j��������ժһ�ο��Եõ���������
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>s;//��Ʒ�ĸ���
            int t=1,x=2*(i+j);
            if(l[i][j])//�����ƵĲ�֣�
            {
                while(s>=t)
                {
                    c[++q]=t*x;
                    v[q]=t*l[i][j];
                    s-=t;t*=2;
                }
                c[++q]=x*s;//��Ҫ��Ҫ��Ҫ���������� 
                v[q]=s*l[i][j];//��Ҫ��Ҫ��Ҫ�� 
            }
        }
    t=min(t,e-1);//��Ϊʱ���������������ȣ����Կ��Կ�����һ�����ƣ���Ϊ����>0����������ȡt,e-1��Сֵ��
    for(int i=1;i<=q;i++)
        for(int j=t;j>=c[i];j--)
            dp[j]=max(dp[j],dp[j-c[i]]+v[i]);//״̬ת�Ʒ��̣���01��һ���ģ�
    cout<<dp[t];
    return 0;
}
