//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                     unsigned long long
#define ll                      long long
#define int                     long long
#define pii                     pair<int, int>
#define pll                     pair<ll, ll>
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define SZ(x)                   ((int)x.size())
#define set_bits                __builtin_popcountll
#define all(a)                  a.begin(),a.end()
#define trav(x,v)               for(auto &x:v)
#define rep(i,n)                for(int i=0;i<n;i++)
#define repe(i,n)               for(int i=1;i<=n;i++)
#define FOR(i,a,b)              for(int i=a;i<=b;i++)
#define curtime                 chrono::high_resolution_clock::now()
#define timedif(start,end)      chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define myshuffle(a,n)          FOR(i,1,n-1) swap(a[i], a[rand() % (i + 1)])
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;



const int MX = 800005;
vector<int> v[MX];
int n;
int val[MX];
vector<int>f[MX];

// ~works on tree with vertices from 1 to n
// ~make sure adjaceny matrix vector<int>v[n+1]
//  is present in global

class LCA {

    vector<int>out_time;
    vector<int>depth;
    vector<int>flatten;
    vector<int>LOG2;
    vector<vector<int>>sparse;

    int LOG_MAX;
    int timer;
    int n;
    int fl_N;

    void dfs(int cur, int par, int lev) {

        depth.pb(lev);
        flatten.pb(cur);
        timer++;
        for (auto &el : v[cur]) {
            if (el != par) {
                dfs(el, cur, lev + 1);
                depth.pb(lev);
                flatten.pb(cur);
                timer++;
            }
        }

        out_time[cur] = timer;
    }

    void merge(int& A, int& B, int& res) {
        if (depth[A] < depth[B])
            res = A;
        else
            res = B;
    }

    void init() {

        for (int i = 1; i <= fl_N; i++) {
            sparse[i][0] = i ;
        }
        for (int j = 1; j <= LOG_MAX; j++) {
            for (int i = 1; (i + (1 << j) - 1) <= fl_N && i <= fl_N; i++) {
                merge(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1], sparse[i][j]);
            }
        }
    }

public:
    LCA(int n, int root) {
        this->n = n;

        depth.pb(-1);
        flatten.pb(-1);
        out_time.resize(n + 1);
        timer = 0;
        dfs(root, -1, 0);
        fl_N = (int)depth.size();
        --fl_N;


        LOG2.resize(fl_N + 1);
        LOG2[1] = 0;
        for (int i = 2; i <= fl_N; i++)
            LOG2[i] = 1 + LOG2[i / 2];

        LOG_MAX = LOG2[fl_N];
        sparse.resize(fl_N + 1, vector<int>(LOG_MAX + 1));
        init();

    }
    
    int query(int x, int y) {
        // #warning check this condition
        if (x > y)
            return INF;

        int h = LOG2[y - x + 1];
        merge(sparse[x][h], sparse[y - (1 << h) + 1][h], h);
        return h;
    }

    int get_lca(int a, int b) {
        a = out_time[a];
        b = out_time[b];
        if(a>b)
            swap(a,b);
        return flatten[query(a, b)];
    }
    int get_dist(int a,int b){
        return depth[out_time[a]]+depth[out_time[b]]-2*depth[out_time[get_lca(a,b)]];
    }
};



void dfs2(int cur,int par){
    for(auto &el:v[cur]){
        if(el==par)
            continue;
        dfs2(el,cur);
        val[cur]+=val[el];
    }
}




void solve() {
    cin>>n;
    repe(i,n)
        v[i].clear(),val[i]=0,f[i].clear();
    
    repe(i,n-1){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    LCA L(n,1);
    cout<<n<<"\n";
    return;
    repe(i,n){
        int y;
        cin>>y;
        f[y].pb(i);

    }
    repe(i,n){
        if(SZ(f[i])<=1)
            continue;
        int l=f[i][0];
        val[f[i][0]]++;
        FOR(j,1,SZ(f[i])-1){
            l=L.get_lca(l,f[i][j]);
            val[f[i][j]]++;
        }
        val[l]-=SZ(f[i]);
    }
    dfs2(1,-1);
    int ans=0;
    FOR(i,2,n){
        ans+=(val[i]>0);
    }
    ans=n-1-ans;
    assert(ans>=0);
    cout<<ans<<" \n";






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