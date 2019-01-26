#include<bits/stdc++.h>
using namespace std;
 
int main() {
        int levelstack[256];
        char stack[256];
        char str[256];
        int num = 0;
        cin >> str;
        int len = strlen(str);
        bool flag = true;
        int level = 0;
        for (int i = 0; flag && i < len; i++) {
            switch (str[i]) {
            case '(':
                if (level > 3) {
                    flag = false;
                }
                levelstack[num] = level;
                level = 3;
                stack[num++] = str[i];
                break;
            case '[':
                if (level > 2) {
                    flag = false;
                }
                levelstack[num] = level;
                level = 2;
                stack[num++] = str[i];
                break;
            case '<':
                levelstack[num] = level;
                level = 4;
                stack[num++] = str[i];
                break;
            case '{':
                if (level > 1) {
                    flag = false;
                }
                levelstack[num] = level;
                level = 1;
                stack[num++] = str[i];
                break;
            case ')':
                if (num == 0 || stack[--num] != '(') {
                    flag = false;
                }
                level = levelstack[num];
                break;
            case ']':
                if (num == 0 || stack[--num] != '[') {
                    flag = false;
                }
                level = levelstack[num];
                break;
            case '>':
                if (num == 0 || stack[--num] != '<') {
                    flag = false;
                }
                level = levelstack[num];
                break;
            case '}':
                if (num == 0 || stack[--num] != '{') {
                    flag = false;
                }
                level = levelstack[num];
                break;
            default:
                flag = false;
            }
        }
        if (flag && num == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
}
