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
#define bs bitset<1001>
int n;
int a[MX];
bs segm[4 * MX];
// 1-base indexing


void buildtree(int cur, int start, int end) {
    if (start == end) {
        //BASE CASE
        segm[cur][a[start]] = 1;
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(cur << 1, start, mid);
    buildtree((cur << 1) ^ 1, mid + 1, end);
    //MERGING STEP
    segm[cur] = segm[(cur << 1)] ^ segm[(cur << 1) ^ 1];

}
bs query(int cur, int start, int end, int qs, int qe) {
    if (start >= qs && end <= qe)
        return segm[cur];
    if (start > qe || end < qs) {
        bs b;
        return b;          //INVALID RETURN
    }
    int mid = (start + end) >> 1;
    bs A = query((cur << 1) , start, mid, qs, qe);
    bs B = query((cur << 1) ^ 1, mid + 1, end, qs, qe);
    //MERGING STEP
    bs res = A ^ B;

    return res;
}
void update(int cur, int start, int end, int ind, int val) {
    if (start == ind && start == end) {
        //DO UPDATE
        // segm[cur] = val;
        segm[cur].flip(val);
        segm[cur].flip(a[ind]);
        return;
    }
    if (start > ind || end < ind)
        return;          //OUT OF RANGE
    int mid = (start + end) >> 1;
    update(cur << 1, start, mid, ind, val);
    update((cur << 1) ^ 1, mid + 1, end, ind, val);
    //MERGING STEP
    segm[cur] = segm[(cur << 1)] ^ segm[(cur << 1) ^ 1];


}

bs query(int l, int r) {
    return query(1, 1, n, l, r);
}
void update(int ind, int  val) {
    update(1, 1, n, ind, val);
}



struct Testcase {


    void solve() {
        cin >> n;
        map<int, int>mp;
        repe(i, n)
        cin >> a[i], mp[a[i]]++;;
        int q;
        cin >> q;
        buildtree(1, 1, n);
        // dbg("hi\n");
        // return;
        repe(i, q) {
            char c;
            cin >> c;
            if (c == '?') {
                int l, r;
                cin >> l >> r;
                bs qu = query(l, r);
                // dbg(l, r, qu.count());
                cout << (SZ(mp) - qu.count()) << "\n";
            }
            else if (c == '*') {
                int x, y;
                cin >> x >> y;
                int val = a[x];
                auto it = mp.find(a[x]);
                if (it->second == 1)
                    mp.erase(it);
                else
                    mp[a[x]]--;
                a[x] = y;
                mp[a[x]]++;
                update(x, val);
            }
            else {
                int x, y;
                cin >> x >> y;
                int val = a[x];
                auto it = mp.find(a[x]);
                if (it->second == 1)
                    mp.erase(it);
                else
                    mp[a[x]]--;
                a[x] = gcd(a[x], y);
                mp[a[x]]++;
                update(x, val);
            }
        }



    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        Testcase T;
        T.solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}