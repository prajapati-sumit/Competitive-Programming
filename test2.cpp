//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace std;
// using namespace __gnu_pbds;


//---------------------Macros----------------------------------------------------------------------------------
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
#define vec                     vector
#define trav(x,v)               for(auto &x:v)
#define rep(i,n)                for(int i=0;i<n;i++)
#define repe(i,n)               for(int i=1;i<=n;i++)
#define FOR(i,a,b)              for(int i=a;i<=b;i++)
#define curtime                 chrono::high_resolution_clock::now()
#define timedif(start,end)      chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define myshuffle(a,n)          FOR(i,1,n-1) swap(a[i], a[rand() % (i + 1)])
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)
#define ordered_set(T)          tree< T ,  null_type ,  less<T> ,  rb_tree_tag ,  tree_order_statistics_node_update >
#define myunique(v)             sort( vec.begin(), vec.end() );vec.erase( unique( vec.begin(), vec.end() ), vec.end() )
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

        int n;
        cin >> n;
        vec<int>a(n + 1, 0);
        map<int, int>mp;
        repe(i, n)   cin >> a[i], mp[a[i]];
        int q;
        cin >> q;
        vec<pii>Q(q + 1);
        repe(i, q)   cin >> Q[i].ff >> Q[i].ss, mp[Q[i].ff], mp[Q[i].ss];

        int nax = 0;
        for (auto &el : mp)
            el.ss = ++nax;
        repe(i, n)
        a[i] = mp[a[i]];
        int indx[nax + 1] = {0};
        vector<int>v[nax + 1];
        repe(i, q) {
            v[Q[i].ss].pb(Q[i].ff);
        }
        int val[nax+1]={0};
        int dp[n + 1] = {0};
        int pre[n + 1] = {0};
        int ind = 0;
        repe(i, n) {
            int mx = 0;
            for (int x : v[a[i]]) {
                if (dp[mx] < dp[val[x]])
                    mx = val[x];
            }
            dp[i] = 1 + dp[mx];
            pre[i] = mx;
            if (dp[val[a[i]]] < dp[i]) {
                val[a[i]] = i;
            }
            if (dp[ind] < dp[i])
                ind = i;
        }
        vector<int>res;
        for(int cur=ind;cur>0;cur=pre[cur])
            res.pb(cur);
        reverse(all(res));
        cout<<SZ(res)<<"\n";
        for(int x:res)
            cout<<x<<" ";
        cout<<"\n";

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