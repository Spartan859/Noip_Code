#include <stdio.h>
#include <stdlib.h>
int fun(const void *a,const void *b)//��С���� 
{
   return *(int*)b-*(int*)a;
}
int main()
{
    int n,m,i,j;//n��ˮ������m��ͷ����
    int time=0,kk;//time���� 
    int w[10001];
    int star[10001],end[10001];
    //freopen("water.in","r",stdin);
    //freopen("water.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)//����ÿ����Ҫ��ˮ������������w���� 
    {
        scanf("%d",&w[i]);
    }
    if(n<=m)//��ˮ����С����ͷ�������Ӵ�С��һ����ֱ���������Ǹ� 
    {
        qsort(w,n,sizeof(int),fun);
        printf("%d\n",w[0]);//������ 
    }
    else if(n>m)//��ˮ������������ͷ��������ʼģ�� 
    {
           for(i=0;i<m;i++)//�����ڽ�ˮ����
        {
            star[i]=w[i];
        }
        for(j=i,kk=0;j<=n;j++,kk++)//����ʣ�µ���
        {
            end[kk]=w[j];
        }
        kk=i;//����һ���ڽ�ˮ������  
        j=0;
        while(n>0)//��ʼģ���ˮ 
        {
            for(i=0;i<kk;i++)//ģ���ˮ���̣��ڽ�ˮ���������ˮ��-1 
            {
                star[i]--;
            }    
            time++;//����+1                
              for(i=0;i<kk;i++)//���һ���˽����ˣ�end�������ʣ�µ��˽��� 
            {
                if(star[i]==0)//������һ���� 
                  {
                    star[i]+=end[j];//������һ���� 
                      j++;//endʣ������������±�j+1 
                      n--;//����-1    
                  }                   
            }                                    
        }                
        printf("%d\n",time);//������� 
    }
    return 0;
}
