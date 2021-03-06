//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;

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

    int A;
    void print(vector<pii>ans) {
        for (auto &el : ans)
            cout << el.ff << " " << el.ss << "\n";
        // dbg(A,polygonArea(ans));
        assert(polygonArea(ans)==A);
    }
    int polygonArea(vector<pii> v)
    {   
        int n=SZ(v);
        // Initialize area
        int area = 0;
     
        // Calculate value of shoelace formula
        int j = n - 1;
        for (int i = 0; i < n; i++)
        {
            area += (v[j].ff + v[i].ff) * (v[j].ss - v[i].ss);
            j = i;  // j is previous vertex to i
        }
        
        // Return absolute value
        return abs(area);
    }
    void solve() {

        int n;
        cin >> n >> A;
        assert(n >= 3 && n <= 5);
        if (n == 3) {
            cout << "POSSIBLE\n";
            print({ {0, 0}, {A, 0}, {A, 1} });


        }
        else if (n == 4) {
            if (A < 2) {
                cout << "IMPOSSIBLE\n";
                return;
            }
            cout << "POSSIBLE\n";
            if (A % 2 == 0) {
                print({ {0, 0}, {A / 2, 0}, {A / 2, 1}, {0, 1} });
            }
            else {
                print({
                    {0, 0}, {A - 1, 0}, {(A + 1) / 2, 1}, {(A - 1) / 2, 1}
                });

            }
        }
        else {
            if (A < 3 ) {
                cout << "IMPOSSIBLE\n";
            }
            else {
                cout << "POSSIBLE\n";
                print({
                    {0, 0}, {1, 0}, {1, 1}, {2, A - 1}, {0, 1}
                });



            }
        }
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        cout << "Case #" << tt << ": ";
        Testcase T;
        T.solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}