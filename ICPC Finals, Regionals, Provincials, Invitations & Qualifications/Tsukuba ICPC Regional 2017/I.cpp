#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int s[maxn],be[maxn],en[maxn];
pair<int,int> p[maxn<<1];
int main() {
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d%d",&a,&b);
        s[a]++;
        s[b]--;
        p[i]=make_pair(a,b);
        be[a]++;
        en[b]++;
    }
    int ans[2]={0,0};
    for(int i=1;i<=100000;i++) {
        s[i]+=s[i-1];
        ans[1]=max(ans[1],s[i]);
        be[i]+=be[i-1];
        en[i]+=en[i-1];
    }
    for(int i=0;i<n;i++)
        ans[0]=max(ans[0],be[p[i].second-1]-en[p[i].first]);
    printf("%d %d\n",ans[0],ans[1]);
    return 0;
}
