#include<bits/stdc++.h>

using namespace std;

int n,a[1010],pd,b[1010],c[1010];

int main()

{

       int i,j,point,k,l;

       cin>>n;

       point=0;

       l=0;

       k=0;

       for(i=1;i<=n;i++)

         {

             scanf("%d",&k);

             if(k>point)//��ǰԪ�ش���ջ������Ԫ�أ���ȴ�Ԫ��С��Ԫ�ض���ջ

               {

                   for (j=point+1;j<=k;j++)

                     a[++l]=j;

                   point=k;

               }

             if(k<=point)//��ǰԪ��С�ڵ���ջ�����Ԫ�أ��ж�ջ��Ԫ���Ƿ���ڸ�Ԫ��

               if (a[l]==k)

                 l--;

               else

                {

                   printf("NO");

                   return 0;

                }

        }

       printf("YES");

       return 0;

}
