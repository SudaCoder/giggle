#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
int n, a[200008], dp[200008], ans[200008];
vector<int> mp[200008];
 
void dfs(int rot, int pre)
{
	for (auto nxt: mp[rot])
	{
		if (nxt == pre)
			continue;
		dfs(nxt, rot);
		dp[rot] += max(0, dp[nxt]);
	}
	dp[rot] += (a[rot]?1:-1);
 
}
 
void dfs2(int rot, int pre)
{
	for (auto nxt: mp[rot])
	{
		if (nxt == pre)
			continue;
		int x = ans[rot] - max(0, dp[nxt]);
		ans[nxt] = dp[nxt] + max(0, x);
		dfs2(nxt, rot);
	}
}
 
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		mp[x].pb(y);
		mp[y].pb(x);
	}
	dfs(1, 0);
	ans[1] = dp[1];
	dfs2(1, 0);
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}