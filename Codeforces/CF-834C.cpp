#include<cstdio>
#include<iostream>
#include<algorithm>
const int N = 1e3+9;
using namespace std;
int x3[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void init() {
    for(int i = 0; i < N; i++) {
        x3[i] = i * i * i;
    }
}

bool judge(int a) {
    return *lower_bound(x3, x3 + N, a) != a;
}

int main() {
    init();
    int t, a, b;
    scanf("%d", &t);
    while(t--) {
        bool flag = 0;
        scanf("%d%d", &a, &b);
        int g = gcd(a,b);
        int x = a / g;
        int y = b / g;
        if(g % x != 0 || g % y != 0) flag = 1;
        else {
            g /= x;
            g /= y;
            flag = judge(g);
        }
        if(flag) puts("No");
        else puts("Yes");
    }
    return 0;
}