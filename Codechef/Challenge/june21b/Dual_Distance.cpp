//~ author      : Sumit Prajapati
//~ mail ID     : sumitprajapati821@gmail.com
//~ codefoces   : sumitprajapati81, codechef: sumit141
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0, 0xFFFFFFFFFFFFFFFF);

const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;
const int MAXLOG = 18;
vector<int>v[MX];
int n, q;
int sparse[MX][MAXLOG];
int level[MX];
vector<unordered_map<int, int>>values;
int subDist[MX];
int subSize[MX];


void dfs(int node, int par, int lev) {

    sparse[node][0] = par;
    level[node] = lev;
    subDist[node] = 0;
    subSize[node] = 1;
    for (auto x : v[node])
        if (x != par) {
            dfs(x, node, lev + 1);
            subDist[node] += subDist[x] + subSize[x];
            subSize[node] += subSize[x];
        }

}
int LCA(int a, int b) {
    if (level[a] > level[b])
        swap(a, b);
    int d = level[b] - level[a];
    int jump = 17;
    while (d) {
        if ((1 << jump) <= d) {
            d -= (1 << jump);
            b = sparse[b][jump];
        }
        jump--;
    }
    if (a == b)
        return a;
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (sparse[a][i] != 0 && (sparse[a][i] != sparse[b][i]))
            a = sparse[a][i], b = sparse[b][i];
    }
    return sparse[a][0];
}
// 1->2->3->4
void init() {
    repe(i, n)
    v[i].clear();

    repe(i, n)
    rep(j, MAXLOG)
    sparse[i][j] = 0;
    values.clear();
    values.resize(n + 1);
}
int subtreeSize(int node, int root) {
    int L = LCA(node, root);
    if (L != node)
        return subSize[node];
    int res = n;
    for (int &el : v[node]) {
        if (LCA(root, el) == el && LCA(node, el) == node) {
            // cout<<root<<" "<<el<<"-?\n";
            res -= subSize[el];
            break;
        }
    }
    return res;

}
void reRoot(int from, int to) {

    // res[node] = res[par] - subSize[node] - subDist[node] + n - subSize[node] + subDist[node];
    subDist[from] = (subDist[from] - subDist[to] - subSize[to]);
    subSize[from] = (subSize[from] - subSize[to]);
    subDist[to] = (subDist[to] + subDist[from] + subSize[from]);
    subSize[to] = n;
    if (values[to].size() == 0) {
        values[to][0] = subDist[to];
        for (int &el : v[to])
            values[to][el] = subDist[el];
    }

}

void dfs2(int cur, int par) {

    for (int &el : v[cur]) {
        if (el != par) {
            reRoot(cur, el);
            dfs2(el, cur);
            reRoot(el, cur);
        }
    }
}
void query(int a, int b) {
    int L = LCA(a, b);
    int disAB = level[a] + level[b] - 2 * level[L];
    int fir = level[a] - level[L], sec = level[b] - level[L];
    // cout<<fir<<" "<<sec<<'\n';
    int froma = a, fromb = b, jump = 17;
    int d = (disAB) >> 1;
    int disa = d + 1, disb = d + 1;
    if (disAB % 2 == 0)
        disb--;
    if (fir != sec) {
        if (fir < sec)
            swap(a, b);
        froma = a;
        fromb = b;
        // cout<<a<<" "<<b<<'\n';
        // return;
        while (d) {
            if ((1 << jump) <= d) {
                d -= (1 << jump);
                froma = sparse[froma][jump];
            }
            jump--;
        }
        fromb = sparse[froma][0];
    }
    else if (fir == sec) {
        while (d) {
            if ((1 << jump) <= d) {
                d -= (1 << jump);
                froma = sparse[froma][jump];
            }
            jump--;
        }
        d = (disAB >> 1) - 1;
        jump = 17;
        while (d) {
            if ((1 << jump) <= d) {
                d -= (1 << jump);
                fromb = sparse[fromb][jump];
            }
            jump--;
        }
    }

    int ans = 0;
    ans += (values[a][0] - ((values[fromb][0] - values[fromb][froma] - subtreeSize(froma, fromb)) + disa * subtreeSize(fromb, a)));

    ans+=(values[b][0] - ((values[froma][0] - values[froma][fromb] - subtreeSize(fromb, froma)) + disb * subtreeSize(froma, b)));
    cout<<ans<<'\n';
}

void solve() {

    cin >> n >> q;
    init();
    int x, y;
    repe(i, n - 1)
    cin >> x >> y, v[x].pb(y), v[y].pb(x);

//------------- Pre-processing-----------------------
    //Calculating Values
    dfs(1, -1, 0);
    values[1][0] = subDist[1];
    for (int &el : v[1])
        values[1][el] = subDist[el];

    // LCA-------------------
    for (int i = 1; i < MAXLOG; i++) {
        for (int j = 1; j <= n; j++) {
            if (sparse[j][i - 1] != 0) {
                int par = sparse[j][i - 1];
                sparse[j][i] = sparse[par][i - 1];
            }
        }
    }
    // ------------------------
    // repe(i, n)
    //     cout << subSize[i] << " \n"[i == n];
    dfs2(1, -1);
    // repe(i, n)
    //     cout << subSize[i] << " \n"[i == n];
    // return;
    repe(i, q) {
        cin >> x >> y;
        query(x, y);
    }
}

//OP BIRRRROOO LCA+REROOTING
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}