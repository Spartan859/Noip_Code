#include <stdio.h>
#include <stdlib.h>
int fun(const void *a,const void *b)//大到小快排 
{
   return *(int*)b-*(int*)a;
}
int main()
{
    int n,m,i,j;//n接水人数、m龙头个数
    int time=0,kk;//time次数 
    int w[10001];
    int star[10001],end[10001];
    //freopen("water.in","r",stdin);
    //freopen("water.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)//输入每个人要接水的数量，存入w数组 
    {
        scanf("%d",&w[i]);
    }
    if(n<=m)//接水人数小于龙头个数，从大到小排一下序，直接输出最大那个 
    {
        qsort(w,n,sizeof(int),fun);
        printf("%d\n",w[0]);//输出最大 
    }
    else if(n>m)//接水人数大于于龙头个数，开始模拟 
    {
           for(i=0;i<m;i++)//存入在接水的人
        {
            star[i]=w[i];
        }
        for(j=i,kk=0;j<=n;j++,kk++)//存入剩下的人
        {
            end[kk]=w[j];
        }
        kk=i;//备份一下在接水的人数  
        j=0;
        while(n>0)//开始模拟接水 
        {
            for(i=0;i<kk;i++)//模拟接水过程，在接水的人所需的水量-1 
            {
                star[i]--;
            }    
            time++;//次数+1                
              for(i=0;i<kk;i++)//如果一个人接完了，end数组里的剩下的人接替 
            {
                if(star[i]==0)//接完了一个人 
                  {
                    star[i]+=end[j];//接替上一个人 
                      j++;//end剩下数组里的人下标j+1 
                      n--;//人数-1    
                  }                   
            }                                    
        }                
        printf("%d\n",time);//输出次数 
    }
    return 0;
}
