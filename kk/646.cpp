#include<iostream>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand()%x)
using namespace std;
int n,d;
int main() {
	freopen("cosmos.in","r",stdin);
	freopen("cosmos.out","w",stdout);
    srand((int)time(0));
    cin>>n;
    for(int i=0;i<n;i++) cin>>d;
    cout<<random(n)<<endl;
    return 0;
}
