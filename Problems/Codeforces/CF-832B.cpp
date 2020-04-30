//832B
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int good[30], pos, n, len, lent;
char s[N], t[N], goodchars[30];

int main() {
    scanf("%s%s%d", goodchars, s + 1, &n);
    len =  strlen(s + 1);
    for (int i = 0; goodchars[i]; ++i)
        good[goodchars[i] - 'a'] = 1;
    for (int i = 1; i <= len; ++i)
        if (s[i] == '*')
            pos = i;
    while (n--) {
        scanf("%s", t + 1);
        int flag = 1;
        lent = strlen(t + 1);
        if (pos == 0) {
            if (len != lent) flag = 0;
            else {
                for (int i = 1; i <= len; ++i) {
                    if (s[i] == '?' && good[t[i] - 'a'] == 0)
                        flag = 0;
                    if (s[i] != '?' && s[i] != t[i])
                        flag = 0;
                }
            }
        }
        else {
            if (len - 1 > lent) flag = 0;
            for (int i = 1; i <= lent; ++i) {
                if (i < pos) {
                    if (s[i] == '?' && good[t[i] - 'a'] == 0)
                        flag = 0;
                    if (s[i] != '?' && s[i] != t[i])
                        flag = 0;
                }
                else if (len - pos >= lent - i + 1) {
                    if (s[len - (lent - i)] == '?' && good[t[i] - 'a'] == 0)
                        flag = 0;
                    if (s[len - (lent - i)] != '?' && s[len - (lent - i)] != t[i])
                        flag = 0;
                }
                else {
                    if (good[t[i] - 'a'])
                        flag = 0;
                }
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}