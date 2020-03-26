//1101B
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, p[4], ans;
char s[N];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '[') {
            p[0] = i;
            break;
        }
    }
    for (int i = n; i; --i) {
        if (s[i] == ']') {
            p[3] = i;
            break;
        }
    }
    if (p[0] == 0 || p[3] == 0) {
        puts("-1");
        return 0;
    }
    for (int i = p[0]; i <= p[3]; ++i) {
        if (s[i] == ':') {
            p[1] = i;
            break;
        }
    }
    for (int i = p[3]; i >= p[0]; --i) {
        if (s[i] == ':') {
            p[2] = i;
            break;
        }
    }
    if (p[1] == 0 || p[1] == p[2]) {
        puts("-1");
        return 0;
    }
    ans = 4;
    for (int i = p[1]; i <= p[2]; ++i) 
        ans += s[i] == '|';
    printf("%d\n", ans);
    return 0;
}