#include<bits/stdc++.h>
using namespace std;
bool dis[105][105];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,m;
		memset(dis,false,sizeof(dis));
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			dis[a][b]=true;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=dis[i][j]||(dis[i][k]&&dis[k][j]);
		bool flag=true;
		for(int i=1;i<=n;i++) {
			if(dis[i][i]) {
				flag=false;
				break;
			}
			for(int j=i+1;j<=n;j++) {
				if(dis[i][j]&&dis[j][i]) {
					flag=false;
					break;
				}
			}
		}
		if(!flag) {
			for(int i=1;i<=n;i++)
				printf("0");
			printf("\n");
		} else {
			int ans=0;
			for(int i=1;i<=n;i++) {
				int cnt1=0;
				int cnt0=0;
				for(int j=1;j<=n;j++) {
					cnt1+=dis[i][j];
					cnt0+=dis[j][i];
				}
				if(cnt1<=n/2&&cnt0<=n/2) {
					printf("1");
				} else {
					printf("0");
				}
			}
			printf("\n"); 
		}
	}
	return 0;
}
