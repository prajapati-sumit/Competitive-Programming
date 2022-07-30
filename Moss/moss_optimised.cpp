//~ author      : Sumit Prajapati
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace std;
// using namespace __gnu_pbds;


//---------------------Macros----------------------------------------------------------------------------------
#define ull                     unsigned long long
#define ll                      long long
#define ld                      long double
// #define int                     long long
#define pii                     pair<int, int>
#define pll                     pair<ll, ll>
#define vi                      vector<int>
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
#define myunique(v)             sort( vec.begin(), vec.end() );vec.erase( unique( vec.begin(), vec.end() ), vec.end() )
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
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
#else
#define dbg(...)
#endif
// -----------------------------------------------------------------------------------------------------------



// ------------------------------Global Variables-------------------------------------------------------------
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const ll INF = 1e17;
const int MX = 1e5 + 5;
// -----------------------------------------------------------------------------------------------------------

// --------------------------------Let's Go!------------------------------------------------------------------



vector<int>G[MX];
multiset<ll>st;
map<ll, int>mp;
const int B = 320;
int timer = 0;
int n, q;
ll a[MX], ans[MX], flatten[MX];

struct query {
    int idx, l, r;
    int64_t ord;

    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }
    inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
        if (pow == 0) {
            return 0;
        }
        int hpow = 1 << (pow - 1);
        int seg = (x < hpow) ? (
                      (y < hpow) ? 0 : 3
                  ) : (
                      (y < hpow) ? 1 : 2
                  );
        seg = (seg + rotate) & 3;
        const int rotateDelta[4] = {3, 0, 0, 1};
        int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
        int nrot = (rotate + rotateDelta[seg]) & 3;
        int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
        int64_t ans = seg * subSquareSize;
        int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
        ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
        return ans;
    }
    bool operator <(const query& other)const {
        return ord < other.ord;
    }
} Q[MX];
void dfs(int u, int par) {

    Q[u].l = ++timer;
    Q[u].idx = u;
    flatten[timer] = a[u];

    for (auto &c : G[u])
        if (c != par)
            dfs(c, u);

    Q[u].r = timer;
    Q[u].calcOrder();
}



void add_element(ll x) {
    // x is index

}
void remove_element(ll x) {
    // x is index

}
void MO_S() {

    for (int L = 1, R = 0, i = 1; i <= q; i++) {
        while (R < Q[i].r)
            add_element(++R);
        while (L > Q[i].l)
            add_element(--L);
        while (R > Q[i].r)
            remove_element(R--);
        while (L < Q[i].l)
            remove_element(L++);
        if (SZ(mp)) {
            ans[Q[i].idx] = mp.begin()->first;
        }
    }
}


struct Testcase {


    void solve() {

        cin >> n;
        q = n;
        timer = 0;
        repe(i, n)
        G[i].clear(), ans[i] = -1;

        st.clear();
        mp.clear();
        repe(i, n - 1) {
            int x, y;
            cin >> x >> y;
            G[x].pb(y);
            G[y].pb(x);
        }
        repe(i, n) {
            cin >> a[i];
        }
        dfs(1, -1);


        sort(Q + 1, Q + q + 1);

        MO_S();
        repe(i, q)
        cout << ans[i] << " ";
        cout << "\n";

    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        Testcase T;
        T.solve();
    }

    cerr << "Execution Time: " << timedif(time0, curtime) * 1e-9 << " sec\n";
    return 0;

}