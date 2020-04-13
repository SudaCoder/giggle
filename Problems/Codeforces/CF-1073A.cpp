// CF1073A
#include <bits/stdc++.h>
using namespace std;

int n;
char s[1010];

int main() {
  cin >> n >> s;
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] != s[i + 1]) {
      cout << "YES" << endl;
      cout << s[i] << s[i + 1] << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}