#include <cstdio>
#include <iostream>
const int N = 1e3 + 9;
using namespace std;
int n, m, q, sum[N];
string s, t;

int main() {
  cin >> n >> m >> q;
  cin >> s >> t;
  int pos = 0;
  while ((pos = s.find(t, pos)) != string::npos) {
    sum[++pos] = 1;
  }
  for (int i = 1; i <= s.length(); i++) {
    sum[i] += sum[i - 1];
  }
  int l, r;
  while (q--) {
    cin >> l >> r;
    r -= t.length() - 1;
    cout << (r >= l ? sum[r] - sum[l - 1] : 0) << endl;
  }
  return 0;
}