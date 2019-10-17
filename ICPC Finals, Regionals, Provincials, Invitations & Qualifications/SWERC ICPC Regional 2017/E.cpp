#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;

map<string,int> id;
struct Edge
{
    int to,nxt,p,c;
}edge[maxn];

int pres[maxn],cost[maxn],in[maxn],
head[maxn],tot;

void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}

void addedge(int u,int v,int cost,int val)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    edge[tot].p=val;
    edge[tot].c=cost;
    head[u]=tot++;
}

void spfa(int x)
{
    queue<int> quu;
    quu.push(x);
    pres[x]=cost[x]=0;
    while(!quu.empty())
    {
        int u=quu.front();
        quu.pop();
        for(int i=head[u];i!=-1;i=edge[i].nxt)
        {
            int v=edge[i].to;
            if(cost[u]+edge[i].c<cost[v])
            {
                cost[v]=cost[u]+edge[i].c;
                pres[v]=pres[u]+edge[i].p;
                quu.push(v);
            }
            else if(cost[u]+edge[i].c==cost[v]
                    &&pres[v]<pres[u]+edge[i].p)
                    {
                        pres[v]=pres[u]+edge[i].p;
                        quu.push(v);
                    }
        }
    }
}

int dp[10005];

int main()
{
    std::ios::sync_with_stdio(false);
    int B,n,m,c,v;
    string a,b,t;
    m=0;
    cin>>B>>n;
    init();
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>t>>c>>v;
        int ida,idb;
        if(!id[a]) ida=id[a]=++m;
        else ida=id[a];
        if(!id[b]) idb=id[b]=++m;
        else idb=id[b];

        in[ida]++;
        addedge(idb,ida,c,v);
    }

    for(int i=1;i<=m;i++)
        cost[i]=pres[i]=1e9+7;
    for(int i=1;i<=m;i++)
        if(in[i]==0)
            spfa(i);

    /*
    for(auto it:id)
    {
        string name=it.first;
        int _id=it.second;
        cout<<name<<" "<<_id<<" "<<cost[_id]<<" "<<pres[_id]<<endl;
    }
    */

    dp[0]=0;
    for(int i=1;i<=m;i++)
        for(int j=B;j>=cost[i];j--)
            dp[j]=max(dp[j],dp[j-cost[i]]+pres[i]);

    int ans1=0,ans2=0;
    for(int i=0;i<=B;i++)
    {
        if(dp[i]>ans1)
        {
            ans1=dp[i];
            ans2=i;
        }
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
