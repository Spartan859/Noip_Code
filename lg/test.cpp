#include<iostream>
using namespace std;

const int MAXN = 1e6 + 5;

struct Node
{
    int lson, rson, sum;
};

Node t[MAXN * 40];
int a[MAXN];

int tot, rt[MAXN], n, m;

int copy(int pre)
{
    ++tot;
    t[tot].lson = t[pre].lson; t[tot].rson = t[pre].rson; t[tot].sum = t[pre].sum;
    return tot;
}

void update(int id)
{
    t[id].sum = t[t[id].lson].sum + t[t[id].rson].sum;
}

int buildtree(int id, int L, int R)
{
	id=++tot;
    if (L == R)
    {
        t[id].sum = a[L];
        return id;
    }

    int mid = (L + R) / 2;
    //++tot;
    t[id].lson = buildtree(t[id].lson, L, mid);
    t[id].rson = buildtree(t[id].rson, mid + 1, R);
    update(id);
    return id;
}

void change(int pre, int L, int R, int k, int c, int id)
{
    id = copy(pre);
    if (L == R)
    {
        t[id].sum = c;
        return ;
    }

    int mid = (L + R) / 2;
    if (k <= mid)
    {
        change(t[pre].lson, L, mid, k, c, t[id].lson);
    }
    else
    {
        change(t[pre].rson, mid + 1, R, k, c, t[id].rson);
    }
}

int query(int id, int L, int R, int k)
{
    if (L == R)
    {
        return t[id].sum;
    }

    int mid = (L + R) / 2;
    if (k <= mid)
    {
        return query(t[id].lson, L, mid, k);
    }
    else
    {
        return query(t[id].rson, mid + 1, R, k);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    rt[0] = buildtree(0, 1, n);
    cout<<rt[0]<<endl;

    for (int i = 0; i < m; i++)
    {
        int root, op, x;
        cin >> root >> op >> x;
        switch (op)
        {
            case 1:
                int y;
                cin >> y;
                change(rt[root], 1, n, x, y, rt[i]);
                break;
            default:
                cout <<query(rt[root],  1, n, x)<<endl;
                rt[i] = rt[root];
                break;

        }
    }
    return 0;
}
