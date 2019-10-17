#include<bits/stdc++.h>
using namespace std;
struct Trie
{
    int root,L,nxt[40007][26],end[40007];
    int newnode()
    {
        for(int i=0;i<26;i++)
            nxt[L][i]=-1;
        end[L]=-1;
        return L++;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void insert(char *buf,int val)
    {
        int now=root;
        for(int i=0;buf[i];i++)
        {
            int &temp=nxt[now][buf[i]-'a'];
            if(temp==-1)
                temp=newnode();
            now=temp;
        }
        end[now]=max(end[now],val);
    }
}t;
char mcc[55],cc[55];
int c,ans[55],dp[55][55],f[55][20007],val;
int main()
{
    scanf("%s",mcc+1);
    scanf("%d",&c);
    int n=strlen(mcc+1);
    t.init();
    for(int i=0;i<c;i++)
    {
        scanf("%s%d",cc,&val);
        t.insert(cc,val);
        reverse(cc,cc+strlen(cc));
        t.insert(cc,val);
    }
    memset(dp,-1,sizeof(dp));
    for(int l=n;l;l--)
    {
        for(int r=l-1;r<=n;r++)
            for(int p=0;p<t.L;p++)
                f[r][p]=-1;
        f[l-1][0]=0;
        for(int r=l-1;r<=n;r++)
            for(int p=0;p<t.L;p++)
                if(f[r][p]!=-1)
                {
                    for(int k=r+1;k<=n;k++)
                    {
                        if(dp[r+1][k]!=-1)
                            f[k][p]=max(f[k][p],f[r][p]+dp[r+1][k]);
                    }
                    if(r<n)
                    {
                        int temp=t.nxt[p][mcc[r+1]-'a'];
                        if(temp!=-1)
                        {
                            f[r+1][temp]=max(f[r+1][temp],f[r][p]);
                            if(t.end[temp]!=-1)
                                f[r+1][0]=max(f[r+1][0],f[r][p]+t.end[temp]);
                        }
                    }
                    if(p==0)
                        dp[l][r]=max(dp[l][r],f[r][p]);
                }
    }
    for(int r=1;r<=n;r++)
    {
        ans[r]=ans[r-1];
        for(int l=1;l<=r;l++)
            if(dp[l][r]!=-1)
                ans[r]=max(ans[r],ans[l-1]+dp[l][r]);
    }
    printf("%d\n",ans[n]);
    return 0;
}
