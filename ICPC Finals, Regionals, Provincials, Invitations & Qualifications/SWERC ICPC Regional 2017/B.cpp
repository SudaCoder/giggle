#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=2005;
bool mp[maxn][maxn];
int rec[maxn][maxn];
int high[maxn];

int main()
{
	int x,y,n,m;
	scanf("%d%d%d%d",&x,&y,&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
		for(int i=x1+1;i<=x2;i++)
			for(int j=y1+1;j<=y2;j++)
				mp[i][j]=true;
	}

	for(int i=1;i<=x;i++)
		mp[i][y+1]=true;

	for(int i=1;i<=x;i++)
	{
		vector<pii> stk;
		for(int j=1;j<=y+1;j++)
		{
			high[j]=mp[i][j]?0:high[j]+1;
			int temp=j;

			while(!stk.empty()&&stk.back().first>=high[j])
			{
				rec[stk.back().first][j-temp]--;
				temp=stk.back().second;
				rec[stk.back().first][j-temp]++;
				stk.pop_back();
			}

			rec[high[j]][j-temp]--;
			stk.push_back(make_pair(high[j],temp));
		}
	}

	for(int i=x;i>=0;i--)
	{
		for(int j=y-1;j>=0;j--)
			rec[i][j]+=rec[i][j+1];
		for(int j=y-1;j>=0;j--)
			rec[i][j]+=rec[i][j+1];
	}

	for(int i=x-1;i>=0;i--)
		for(int j=y;j>=0;j--)
			rec[i][j]+=rec[i+1][j];

	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",rec[x][y]);
	}
	return 0;
}
