#include<bits/stdc++.h>

using namespace std;

const int N = 300;
const int N2 = 5;

struct _student {
    int no;
    int yuwen;
    int total;
} s[N];

int cmp(const _student &a, const _student &b)
{
    if(a.total != b.total)
        return a.total > b.total;
    if(a.yuwen != b.yuwen)
        return a.yuwen > b.yuwen;
    else
        return a.no < b.no;
}

int main()
{
    int n, a, b;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s[i].yuwen >> a >> b;
        s[i].no = i + 1;
        s[i].total = s[i].yuwen + a + b;
    }

    sort(s, s + n, cmp);

    for(int i=0; i<N2; i++)
        cout << s[i].no << " " << s[i].total << endl;

    return 0;
}
//CopyRight Spartan117 2018.6.3
