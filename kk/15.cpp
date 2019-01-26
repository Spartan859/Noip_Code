#include <bits/stdc++.h>
using namespace std;
ostringstream oss;
int f(int m)//计算m中含有‘3’的个数
{
	oss<<m;
	string s;
	s=oss.str();
    int count = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '3')
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int m, k;
    cin >> m >> k;
    if (m%19 == 0)//can be divided by 19
    {
        int count = f(m);
        if (count == k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
