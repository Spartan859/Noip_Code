#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    string s;

    cin >> t;
    while(t--) {
        cin >> s;

        int num = 1, sign = 1;
        int a = 0, b = 0;
        int flag = 0;       // 方程左右标识，0指左边，1指右边

        for(int i = 0; s[i]; i++) {
            if(s[i] == '=') {
                sign = 1, num = 1;
                flag = 1;
            } else if(s[i] == '+') {
                sign = 1, num = 1;
            } else if(s[i] == '-') {
                sign = -1, num = 1;
            } else {
                num = (s[i] == 'x') ? 1 : 0;
                while(isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                if(s[i] == 'x') {
                    if(flag == 0) b += num * sign;
                    else b -= num * sign;
                } else {
                    i--;
                    if(flag == 0) a -= num * sign;
                    else a += num * sign;
                }
            }
        }

        if(b == 0) {
            if(a == 0)
                cout << "IDENTITY" << endl;
            else
                cout << "IMPOSSIBLE" << endl;
        } else {
            int x = (int)floor((double)a / b);
            cout << x << endl;
        }
    }
}
