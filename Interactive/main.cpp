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
#define nl  '\n'
// ------------------------------------------------------------------------------------------------------------


//-----------------------------Debugging----------------------------------------------------------------------
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type > ostream & operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v) os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() {
    cerr << endl;
}
template<typename TT, typename... UU> void dbg_out(TT H, UU... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
//-----------------------------------------------------------------------------------------------------------



// ------------------------------Global Variables-------------------------------------------------------------
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;
// -----------------------------------------------------------------------------------------------------------


// --------------------------------Let's Go!------------------------------------------------------------------



//-----------------------My Judge------------------------------------------
struct MyJudge {
    vector<int>hidden;
    int n;
    void init(int N) {
        n = N;
        hidden.resize(N + 1);
        set<int>st;
        repe(i, N) {
            int x;
            while(st.count(x = mtrand(1, N)));
            st.insert(x);
            hidden[i] = x;
        }
    }
    void init(){
        return;
    }
    int query_judge(vector<int>& a) {
        repe(i, n) {
            int here = a[i] + hidden[i];
            for(int j = i + 1; j <= n; j++){
                if(a[j] + hidden[j] == here)
                    return i;
            }
        }
        return 0;
    }
} MJ;
//---------------------------------------------------------------------------
int cnt = 0;
int n,limit;
int query(vector<int> &a) {

    assert(cnt < limit);
    cnt++;
#ifdef LOCAL
    return MJ.query_judge(a);
#else
    cout << "? ";
    repe(i, n)
    cout << a[i] << " ";
    cout << nl;
    int resp;
    cin >> resp;
    return resp;
#endif


}
void solve() {

    cin >> n;

    // reset
    cnt = 0;
    limit = 2*n;

#ifdef LOCAL
    MJ.init(n);
#endif
    vector<int>a(n + 1, 0);
    vector<int>p(n + 1, 0);
    int last = n;
    for(int i = 2; i <= n; i++) {
        a[n] = 1;
        repe(j, n - 1)
        a[j] = i;
        int h = query(a);
        if(h == 0) {
            last = i - 1;
            break;
        }
        p[h] = (1 - i);
    }
    for(int i = n - 1; i >= 1; i--) {
        a[n] = n;
        repe(j, n - 1)
        a[j] = i;
        int h = query(a);
        if(h == 0) {
            break;
        }
        p[h] = (n - i);
    }
    repe(i, n)
    p[i] += last;

    cout << "! ";
    repe(i, n)
    cout << p[i] << " ";
    cout << nl;




#ifdef LOCAL
    dbg(MJ.hidden);
#endif

}


int32_t main() {




    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    return 0;

}