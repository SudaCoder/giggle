#include <cstdio>
#include <algorithm>
const int N = 1005;
using namespace std;
 
int n, a, b, f = 1;
bool s[N][N];
 
int main() {
	scanf("%d%d%d", &n, &a, &b);
	if(a > b) swap(a, b), f = 0;
	if(a > 1 || ((n == 2 || n == 3) && a == 1 && b == 1)) {
		return puts("NO"), 0;
	}
  puts("YES");
	for(int i = b; i < n; i++)
		s[i][i+1] = s[i+1][i] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			putchar(i == j ? '0' : (s[i][j] ^ f) + '0');
		puts("");
	}
	return 0;
}