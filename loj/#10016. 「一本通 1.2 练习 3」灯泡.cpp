#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
    scanf("%d",&T);
    while(T--) {
        double H,h,D,ans;
        scanf("%lf%lf%lf",&H,&h,&D);
        if(sqrt((H-h)/D)>=H/D) ans=h*D/H;
        else if(sqrt((H-h)/D)<=(H-h)/D) ans=h;
        else ans=D+H-2*sqrt((H-h)*D);
        printf("%.3f\n",ans);
    }
    return 0;
}
