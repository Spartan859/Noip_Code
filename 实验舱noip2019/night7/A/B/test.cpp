#include <bits/stdc++.h>
using namespace std;
inline int Rand() {
    return rand()|rand()<<16;
}
int main() {
    freopen("B.in","w",stdout);
    srand(((unsigned long long)new char)+time(NULL));
    int n=1000000,G=26,l=rand()%50000+50000,r=rand()%50000+400000;
    cout<<n<<endl;
    for(int i=1;i<=n;i++) {
	if(i>=l&&i<=r) putchar('a');
	else putchar(rand()%G+'a');
    }
    return 0;
}
