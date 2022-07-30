//~ author      : Sumit Prajapati
// #pragma GCC optimize("O3")
// #pragma GCC target ("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace std;
// using namespace __gnu_pbds;


//---------------------Macros----------------------------------------------------------------------------------
#define ull                     unsigned long long
#define ll                      long long
#define ld                      long double
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
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)
int gcd(int a, int b) {return a * b == 0 ? a ^ b : __gcd(a, b);}
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ------------------------------------------------------------------------------------------------------------


// -----------------------------Debugging----------------------------------------------------------------------
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type > ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename TT, typename... UU> void dbg_out(TT H, UU... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define stop(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);cerr<<"exited\n";exit(0);
#else
#define dbg(...)
#define stop(...)
#endif
// -----------------------------------------------------------------------------------------------------------



// ------------------------------Global Variables-------------------------------------------------------------
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;
// -----------------------------------------------------------------------------------------------------------

// --------------------------------Let's Go!------------------------------------------------------------------
// 1-base indexing

void combine(pii& x, pii& y, pii& res) {
    res.ff = min(x.ff, y.ff);
    res.ss = (x.ff == res.ff ? x.ss : 0) + (y.ff == res.ff ? y.ss : 0);

}
template <typename T>
class LazySegTree {
private:
    T* segm;
    int* lazy;
    int N;
    void (*merge)(T&, T&, T&);
    void buildtree(int cur, int start, int end) {
        if (start == end) {
            //BASE CASE
            segm[cur] = {0, 1};
            return;
        }
        int mid = (start + end) >> 1;
        buildtree(cur << 1, start, mid);
        buildtree((cur << 1) ^ 1, mid + 1, end);
        //MERGING STEP
        (*merge)(segm[(cur << 1)], segm[(cur << 1) ^ 1], segm[cur]);

    }
    void lazyUpdate(int cur, int start , int end) {
        if (!lazy[cur])
            return;
        int dx = lazy[cur];
        lazy[cur] = 0;
        segm[cur].ff += dx;
        if (start != end) {
            lazy[(cur << 1)] += dx;
            lazy[(cur << 1) ^ 1] += dx;

        }
    }
    T query(int cur, int start, int end, int qs, int qe) {
        lazyUpdate(cur, start, end);
        if (start >= qs && end <= qe)
            return segm[cur];
        if (start > qe || end < qs)
            return {INF, 1};         //INVALID RETURN
        int mid = (start + end) >> 1;
        T A = query((cur << 1) , start, mid, qs, qe);
        T B = query((cur << 1) ^ 1, mid + 1, end, qs, qe);
        //MERGING STEP
        T res;
        (*merge)(A, B, res);

        return res;
    }
    void update(int cur, int start, int end, int qs, int qe, int val) {
        lazyUpdate(cur, start, end);
        if (start >= qs && end <= qe) {
            //DO UPDATE
            lazy[cur] = val;
            lazyUpdate(cur, start, end);
            return;
        }
        if (start > qe || end < qs)
            return;          //OUT OF RANGE
        int mid = (start + end) >> 1;
        update((cur << 1), start, mid, qs, qe, val);
        update((cur << 1) ^ 1, mid + 1, end, qs, qe, val);
        //MERGING STEP
        (*merge)(segm[(cur << 1)], segm[(cur << 1) ^ 1], segm[cur]);
    }

public:

    LazySegTree(int n, void (*fun)(T&, T&, T&) = &combine) {
        N = n;
        segm = new T[4 * (N + 1)]();
        lazy = new int[4 * (N + 1)]();
        merge = fun;
        buildtree(1, 0, N - 1);
    }
    T query(int l, int r) {
        return query(1, 0, N - 1, l, r);
    }
    void update(int l, int r, int val) {
        update(1, 0, N - 1, l, r, val);
    }

};


struct Testcase {

    int n;
    int q, x;
    vector<vector<int>>G;
    vector<int>startTime;
    vector<int>endTime;
    vector<int>val;
    vector<int>flatten;
    vector<vector<int>>up;
    const int LOG = 20;
    struct Edge {
        int u, v, w;
        Edge() {}
        Edge(int _u, int _v, int _w): u{_u}, v{_v}, w{_w} {}
        bool operator <(const Edge& other) {
            return w < other.w;
        }
    };
    vector<Edge>edges;
    int buildReachabilityTree() {

        sort(all(edges));
        vector<int>p(n + 1);
        repe(i, n)
        p[i] = i;

        function<int(int)> f = [&](int x) {return p[x] == x ? x : p[x] = f(p[x]);};

        for (auto &e : edges) {
            int u = f(e.u), v = f(e.v), w = e.w;

            //adding a new edge
            int ce = p.size();
            p.push_back(ce);
            p[u] = ce;
            p[v] = ce;
            G[ce].push_back(u);
            if (u != v)
                G[ce].push_back(v);

            val[ce] = w;
        }

        return (int)p.size() - 1;

    }
    void init() {
        G.resize(2 * n);
        startTime.resize(2 * n);
        endTime.resize(2 * n);
        val.resize(2 * n);
        up.resize(2 * n, vector<int>(LOG));
        repe(i, n)
        val[i] = 0;
        val[0] = INF;
    }
    void dfs(int u, int p) {
        if (SZ(G[u]) == 0) {
            startTime[u] = SZ(flatten);
            endTime[u] = SZ(flatten);
            flatten.pb(u);
            return;
        }
        startTime[u] = INF;
        for (int c : G[u]) {
            up[c][0] = u; // u is parent of c
            for (int j = 1; j < LOG; j++) {
                up[c][j] = up[up[c][j - 1]][j - 1];
            }
            dfs(c, u);
            startTime[u] = min(startTime[u], startTime[c]);
            endTime[u] = max(endTime[u], endTime[c]);
        }
    }

    int getParent(int u, int k) { // O(log(N))
        for (int j = LOG - 1; j >= 0; j--) {
            int p = up[u][j];
            // dbg(u, p, val[p], j);
            if (val[p] <= k) {
                u = p;
            }
        }
        return u;

    }

    void solve() {
        cin >> n;
        init();
        repe(i, n - 1) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back(Edge(u, v, w));
        }
        int root = buildReachabilityTree();
        dfs(root, 0);
        // dbg(root);
        // dbg(startTime, endTime, flatten);

        cin >> q >> x;
        LazySegTree<pii>LT(n);
        queue<pair<int, pii>>Q;
        repe(i, q) {
            int d, u, k;
            cin >> d >> u >> k;
            while (!Q.empty() && Q.front().first <= d) {
                pii h = Q.front().second;
                Q.pop();
                LT.update(h.ff, h.ss, -1);
            }
            int p = getParent(u, k);
            pii cnt = LT.query(startTime[p], endTime[p]);
            // dbg(d, u, k, p, cnt);
            cout << (cnt.ff == 0 ? cnt.ss : 0) << "\n";
            LT.update(startTime[p], endTime[p], +1);
            Q.push({d + x, {startTime[p], endTime[p]}});
        }


    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        Testcase T;
        T.solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}