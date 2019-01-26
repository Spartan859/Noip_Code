#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
void dfs(long long x,long long y){
	for (long long i = 1; i*i <= x; ++i)
    {
        if (x%i == 0)
        {
        	if(y==k){
        		ans++;
			}
            else if(y<k) dfs(i,y+1);
            if (i*i != x)
            {
                if(y==k){
        		    ans++;
			    }
                else if(y<k) dfs(x/i,y+1);
            }
        }
    }
}
int main()
{
    cin >> n >>k;
    dfs(n,0);
    cout<<ans%998244353<<endl;
    return 0;
}
