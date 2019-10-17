#include<bits/stdc++.h>
#define root 1,1,n
#define lson i<<1,L,MID
#define rson i<<1|1,MID+1,R
using namespace std;
const int maxn=5e5+7;
char s[maxn],t[maxn];
int tree[maxn<<2],dp[maxn],b[maxn],n,k;
void update(int pos,int val,int i,int L,int R) {
    if(L==R) {
        tree[i]=val;
        return;
    }
    int MID=(L+R)>>1;
    if(pos<=MID) update(pos,val,lson);
    else update(pos,val,rson);
    tree[i]=min(tree[i<<1],tree[i<<1|1]);
}
int query(int l,int r,int i,int L,int R) {
    if(l<=L&&R<=r) return tree[i];
    int MID=(L+R)>>1;
    int res=1000000007;
    if(MID>=l) res=min(res,query(l,r,lson));
    if(MID<r) res=min(res,query(l,r,rson));
    return res;
}
int main() {
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    scanf("%s",t+1);
    for(int i=1;i<=n;i++) {
        b[i]=b[i-1]+(t[i]!=t[i-1]);
        update(i,2*dp[i-1]-b[i],1,1,n);
        if(s[i]==t[i]) dp[i]=dp[i-1];
        else dp[i]=(query(max(1,i-k+1),i,root)+b[i]+1)/2+1;
    }
    printf("%d\n",dp[n]);
    return 0;
}
