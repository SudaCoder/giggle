#include<bits/stdc++.h>
using namespace std;
int x[20],y[20],n;
int a[20],b[20],ans;
bool vis[20];
pair<int,int> p[20];
int solve(int cnt) {
    for(int i=1;i<=cnt;i++) {
        int dx=x[a[i]]-x[b[i]];
        int dy=y[a[i]]-y[b[i]];
        int g=__gcd(dx,dy);
        dx/=g,dy/=g;
        if(dx<0||(dx==0&&dy<0)) {
            dx=-dx;
            dy=-dy;
        }
        p[i]=make_pair(dx,dy);
    }
    int temp=0;
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<i;j++)
            if(p[i]==p[j])
                temp++;
    return temp;
}
void dfs(int x,int now) {
    if(now==n/2) {
        ans=max(ans,solve(now));
        return;
    }
    for(int i=x+1;i<=n;i++) {
        if(!vis[i]) {
            a[now+1]=i;
            vis[i]=true;
            for(int j=i+1;j<=n;j++) {
                if(!vis[j]) {
                    b[now+1]=j;
                    vis[j]=true;
                    dfs(i,now+1);
                    vis[j]=false;
                }
            }
            vis[i]=false;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}
