#include <iostream>
#include <cmath> 
#include <algorithm> 
using namespace std;
const int M = 1003;
int n;
int hj[M];
int f[M];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin>>hj[i];
    for(int i=1;i<n;i++)
        f[i] = abs(hj[i] - hj[i+1]);
    sort(f+1,f+n);

    for(int i=1;i<n;i++)
        if(f[i] != i){
            cout << "Not jolly"<<endl;
            return 0;
        }
    cout << "Jolly"<<endl; 
    return 0;
}


