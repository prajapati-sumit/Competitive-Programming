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
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)
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
const int INF = 1e9;
const int MX = 1e5 + 5;
// -----------------------------------------------------------------------------------------------------------

// --------------------------------Let's Go!------------------------------------------------------------------




struct Testcase {


    void solve() {

        int n, m;
        cin >> n >> m;

        int a[n + 1][31];
        memset(a, 0, sizeof(a));
        vector<pair<pii, int>>v;
        rep(i, m) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int j = 0; j < 31; j++) {
                if ((1LL << j)&x) {
                    v.pb({{l, r}, j});
                }
                else {
                    // if (j == 5)
                    //     dbg(l, r, x);
                    a[l][j] += 1;
                    if (r + 1 <= n)
                        a[r + 1][j] -= 1;

                }
                // dbg(l, r, x);
                // return;
            }

        }
        vector<int>b(n + 1);
        repe(i, n) {
            rep(j, 31) {
                if (i > 1)
                    a[i][j] += a[i - 1][j];
                if (a[i][j] == 0)
                    b[i] |= (1LL << j);
                // a[i][j] = (a[i][j] > 0);
            }
        }
        repe(i, n) {
            rep(j, 31) {
                a[i][j] = (a[i][j] > 0);
            }
        }
        repe(i, n) {
            rep(j, 31) {
                if (i > 1)
                    a[i][j] += a[i - 1][j];
            }
        }
        // repe(i, n)
        // cout << a[i][5] << " \n"[i == n];
        for (auto &el : v) {
            int l = el.ff.ff, r = el.ff.ss, j = el.ss;
            int sum = a[r][j] - a[l - 1][j];
            // dbg(l, r, j, sum);
            if (sum == (r - l + 1)) {
                cout << "-1\n";
                return;
            }

        }
        repe(i, n)
        cout << b[i] << " \n"[i == n];
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

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}