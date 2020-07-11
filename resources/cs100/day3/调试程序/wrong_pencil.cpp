#include<iostream>
using namespace std;

int main(void)
{
    int n,a,b,ans=2147483647;
    cin>>n;
    int i;
    for(i=0;i<3;i++)
    {
        cin>>a>>b;
        ans=min((n/a+1)*b,ans);
    }
	cout<<ans<<endl;
	return 0;
}
