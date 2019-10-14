#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans, cas = 0; 
	long long k;
	while(~scanf("%d%lld", &n, &k)) {
		if(k <= n) ans = k;
		else {
			k -= n;
			k %= 2 * (n - 1);
			if(k == 0)
				k = 2 * n - 2;
			if(k <= n - 1)
				ans = k;
			else {
				ans = k == 2 * n - 2 ? n : k % (n - 1);
			}
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}