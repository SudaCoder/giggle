#include <bits/stdc++.h>
const int N = 5e4+9;
const int MK = 6;
using namespace std;
int f,m,K,n;
int read(){
    int f=1,v=0; char ch = getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar(); }
    while(ch>='0'&&ch<='9'){ v=v*10+ch-'0';ch=getchar(); }
    return f*v;
}

struct Node{
    int d[MK], mn[MK], mx[MK], v, l, r;
    inline void get(){ for(int i = 0; i < K; i++) d[i] = read(); }
    inline int&operator[](int x){ return d[x]; }
    inline friend bool operator<(Node a, Node b){ return a[f] < b[f]; }
    inline friend bool operator==(Node a, Node b){
        for (int i = 0; i < K; i++) if(a[i] != b[i]) return 0;
        return 1;
    }
    inline void P(){ for (int i = 0; i < K; i++) printf("%d%c", d[i], i==K-1?'\n':' ');}
};

double disE2(Node a, Node b){
    double s = 0;
    for (int i = 0; i < K; i++) s += (a[i]-b[i])*(a[i]-b[i]);
    return s;
}

int disM(Node a, Node b){
    int s = 0;
    for (int i = 0; i < K; i++) s += abs(a[i] - b[i]);
    return s;
}

priority_queue<pair<double, Node> >q;
struct kdt{
    Node t[N], T;
    int cnt;
    inline void update(int k) {
        int l = t[k].l, r = t[k].r;
        for (int i = 0; i < K; i++) {
            t[k].mn[i] = t[k].mx[i] = t[k][i];
            if(l) {
                t[k].mn[i] = min(t[k].mn[i], t[l].mn[i]);
                t[k].mx[i] = max(t[k].mx[i], t[l].mx[i]);
            }if(r) {
                t[k].mn[i] = min(t[k].mn[i], t[r].mn[i]);
                t[k].mx[i] = max(t[k].mx[i], t[r].mx[i]);
            }
        }
    }
    int build(int l=1, int r=n, int d=0) {
        if(l > r) return 0;
        int mid = (l+r)>>1; f = d;
        nth_element(t+l, t+mid, t+r+1);
        t[mid].l = build(l, mid-1, (d+1)%K);
        t[mid].r = build(mid+1, r, (d+1)%K);
        return mid;
    }
    void find(int k, int d=0){
        if(!k) return ;
        double dis = disE2(T, t[k]);
        int ch[2] = {t[k].l, t[k].r};
        bool f = (t[k][d] < T[d]);
        if(ch[f]) find(ch[f], (d+1)%K);
        if(q.size() < m) q.push(make_pair(dis, t[k]));
        else {
            if(dis < q.top().first) q.push(make_pair(dis, t[k])), q.pop();
            if((T[d] - t[k][d])*1.0*(T[d] - t[k][d]) >= q.top().first) return;
        }
        if(ch[f^1]) find(ch[f^1], (d+1)%K);
    }
}kd;
int Q;
stack<Node> s;
int main(){
    while(~scanf("%d%d", &n, &K)) {
        kd.cnt = n;
        for (int i = 1; i <= n; i++) kd.t[i].get();
        int rt = kd.build();
        Q = read();
        while(Q--){
            kd.T.get(); m = read(); kd.find(rt);
            printf("the closest %d points are:\n",m);
            while(!q.empty()) s.push(q.top().second),q.pop();
            while(!s.empty()) s.top().P(),s.pop();
        }
    }return 0;
}
