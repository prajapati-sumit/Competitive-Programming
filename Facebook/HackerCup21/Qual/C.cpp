//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define SZ(x)               ((int)x.size())
#define set_bits            __builtin_popcountll
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;

const int MX = 50 + 2;
const int LOG = 7;
vector<int> v[MX];
int up[MX][LOG]; // up[v][j] is 2^j-th ancestor of v
int depth[MX];
int dist[MX];
int cost[MX];
vector<pii>helper;

void dfs(int a, int par) {

    for (int b : v[a]) {
        if (b == par)
            continue;
        depth[b] = depth[a] + 1;
        up[b][0] = a; // a is parent of b
        for (int j = 1; j < LOG; j++) {
            up[b][j] = up[up[b][j - 1]][j - 1];
        }
        dfs(b, a);
    }
}
void dfs2(int a, int par) {
    dist[a] = cost[a] + dist[par];
    if (SZ(v[a]) == 1) {
        helper.pb({dist[a], a});
        return;
    }
    for (auto b : v[a])
        if (b != par)
            dfs2(b, a);

}
int get_lca(int a, int b) { // O(log(N))
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    // 1) Get same depth.
    int k = depth[a] - depth[b];
    for (int j = LOG - 1; j >= 0; j--) {
        if (k & (1 << j)) {
            a = up[a][j]; // parent of a
        }
    }
    // 2) if b was ancestor of a then now a==b
    if (a == b) {
        return a;
    }
    // 3) move both a and b with powers of two
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

struct cmp {
    bool operator()(pii const& p, pii const& q)
    {
        if (p.ff == q.ff)
            return p.ss > q.ss;
        return p.ff < q.ff;
    }
};



void solve() {

    int n;
    int k = 1;
    cin >> n>>k;
    repe(i, n)
    cin >> cost[i];
    repe(i,n)
        v[i].clear(),dist[i]=0,depth[i]=0;
    repe(i, n - 1) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1, -1);
    priority_queue < pii, vector<pii>, cmp> pq;
    pq.push({0, 1});
    for (int c : v[1]) {
        dfs2(c, 1);
        sort(all(helper));
        int sz = SZ(helper);
        pq.push({helper[sz - 1].ff, 1});
        int best = helper[sz - 1].ss;
        for (int i = sz - 2; i >= 0; i--) {
            int here = helper[i].ff, node = helper[i].ss;
            int L = get_lca(best, node);
            pq.push({dist[node] - dist[L], 0});
        }
        helper.clear();
    }
    int ans = cost[1];
    if(k==0){
        cout<<ans<<'\n';
        return;
    }
    assert(pq.top().ss==1);
    ans+=pq.top().ff;
    pq.pop();
    // while(!pq.empty()){
    //     cout<<pq.top().ff<<" "<<pq.top().ss<<"\n";
    //     pq.pop();
    // }
    // return;
    while (!pq.empty() && k-- > 1) {
        ans += pq.top().ff;
        pq.pop();
    }
    while (!pq.empty() && pq.top().ss == 0) {
        pq.pop();
    }
    if (!pq.empty()){
        ans += pq.top().ff;
    }
    cout << ans << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}