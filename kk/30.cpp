#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[10005];

//�Ѿ���ǰi��õ��˺�sum��Ȼ�����i��֮��Ľ��з�֧
bool dfs(int i, int sum)
{
    //���ǰi�������ˣ��򷵻�sum�Ƿ���k���
    if (i == n)
        return sum == k;
    //������a[i]�����
    if (dfs(i + 1, sum))
        return true;
    //����a[i]�����
    if (dfs(i + 1, sum + a[i]))
        return true;
    //�����Ƿ����a[i]�����ܴճ�k�ͷ���false
    return false;
}

int main()
{
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (dfs(0, 0)){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    return 0;
}
