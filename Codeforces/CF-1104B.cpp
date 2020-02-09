#include <iostream>
using namespace std;
const int N = 1e5+9;
char c[N];

int main() {
    int ans = 0, i = 0;
    while(cin >> c[++i]) {
        if (c[i] == c[i-1]) {
            i -= 2;
            ans += 1;
        }
    }
    if (ans % 2 == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
}