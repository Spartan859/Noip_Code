#include<cstdio>
#include<cstring>
int n; double ans;
int main(){
    scanf("%d",&n);double cost=420000.00/n;
    for(int i=1;i<n;i++)
    {
        ans+=cost;
        cost*=(double)(2*i-1)/(double)(2*i);
    }
    printf("%.2lf",ans+cost);
    return 0;
}
