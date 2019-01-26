#include<bits/stdc++.h> 
using namespace std;

int main()
{
    bool flag = 0;
    int a[4][100001],b[4];
    int i=0,j=0;
    while(cin >> a[0][i] >> a[1][i] >> a[2][i] >> a[3][i]) i++;
    while((a[1][j] + a[2][j] + a[3][j] + a[0][j]) != 0)
    {
    	b[0]=a[0][j];
    	b[1]=a[1][j];
    	b[2]=a[2][j];
    	b[3]=a[3][j];
        vector<int>v;
        if(flag == 1)
            printf("\n");
        if(flag == 0)
            flag = 1;
        sort(b,b + 4);
        do
        {
            if(b[0] == 0)
                continue;
            v.push_back(b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3]);
        }
        while(next_permutation(b,b + 4));
        cout << v[0];
        int k = v[0] / 1000;
        for(int i = 1;i < v.size();i ++)
        {
            if(v[i] / 1000 == k)
            {
                printf(" %d",v[i]);
            }
            else
            {
                printf("\n");
                printf("%d",v[i]);
                k = v[i] / 1000;
            }
        }
        j++;
        if((a[1][j] + a[2][j] + a[3][j] + a[0][j]) != 0) printf("\n");
    }
    return 0;
}
