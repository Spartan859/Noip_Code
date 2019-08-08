#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string dp[110][110], s;
 
string _to_string(int num) {
    string ans;
    while(num) {
        ans += num % 10 + '0';
        num /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    int n;
    while(cin >> s) {
        n = s.length();
        for (int i = 0; i < n; i++) {
            dp[i][i] = s[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = s.substr(i, j - i + 1);
                for (int nowl = 1; nowl <= len / 2; nowl++) {
                    if(len % nowl) continue;
                    int l = i, r = i + nowl;
                    while(s[l] == s[r] && r <= j) l++, r++;
                    if(r > j) {
                        int num = len / nowl;
                        dp[i][j] = _to_string(num);
                        dp[i][j] += "(";
                        dp[i][j] += dp[i][i + nowl - 1];
                        dp[i][j] += ")";
                        //cout<< dp[i][j] <<endl;
                        break;
                    }
                }
                for (int k = i; k < j; k++) {
                    if(dp[i][j].length() > dp[i][k].length() + dp[k + 1][j].length() || dp[i][j].length() == 0) {
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                    }
                }
            }
        }
        cout << dp[0][n - 1] <<endl;
    }
     
}
