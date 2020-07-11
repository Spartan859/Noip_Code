#include <iostream>
using namespace std;

const int SIZE = 50;
int n1, m1, n2, m2, a[SIZE][SIZE], b[SIZE][SIZE];

int main()
{
    int i, j, k1, k2;
    bool good, haveAns;
    
    cin >> n1 >> m1;
    for(i = 1; i <= n1; i++)
        for(j = 1; j <= m1; j++)
            cin >> a[i][j];
    cin >> n2 >> m2;
    for(i = 1; i <= n2; i++)
        for(j = 1; j <= m2; j++)
            cin>>b[i][j];
    haveAns = false;
    for(i = 1; i <= n1 - n2 + 1; i++)
        for(j = 1; j <= m1-m2+1; j++)
        {
            good=true;
            for(k1 = 1; k1 <= n2; k1++)
                for(k2 = 1; k2 <= m2; k2++)
                {
                    if(a[i + k1 - 1][j + k2 - 1] != b[k1][k2])
                        good = false;
                }
            if(good)
            {
                cout << i << ' ' << j << endl;
                haveAns=true;
            }
        }

    if(!haveAns)
        cout << "There is no answer" << endl;
    return 0;
}
