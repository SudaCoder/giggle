//1040B
#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<int> ans, vec;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k + 1; ++i) {
        vec.clear();
        vec.push_back(i);
        int r = i + k + 1;
        for (int j = r + k; j <= n; j = r + k) {
            r = j + k + 1;
            vec.push_back(j);
        }
        if (r > n)
            if (ans.empty() || vec.size() < ans.size())
                ans = vec;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}