//1113A
#include <bits/stdc++.h>
using namespace std;
 
int n, v, ans;
 
int main() {
	cin >> n >> v;
    if (v >= n - 1)
        ans = n - 1;
    else {
        ans = v;
        for (int i = v + 1; i < n; ++i)
            ans += 1 + i - v;
    }
	cout << ans << endl;
	return 0;
}