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

             if(k>point)//当前元素大于栈中最大的元素，则比此元素小的元素都入栈

               {

                   for (j=point+1;j<=k;j++)

                     a[++l]=j;

                   point=k;

               }

             if(k<=point)//当前元素小于等于栈中最大元素，判断栈顶元素是否等于该元素

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
