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
const int INF = 1e16;
const int MX = 1e5 + 5;
// -----------------------------------------------------------------------------------------------------------



// --------------------------------Let's Go!------------------------------------------------------------------
struct Figure {
    int x1;
    int y1;
    int x2;
    int y2;
};
struct Point{
    int x;
    int y;
};
struct Testcase {

    int fn(Figure A,Point P){
        int d1=min(abs(P.y-A.y1),abs(P.y-A.y2));
        int d2=min(abs(P.x-A.x1),abs(P.x-A.x2));
        bool c1=(A.x1<=P.x && P.x<=A.x2);
        bool c2=(A.y1<=P.y && P.y<=A.y2);
        if(c1 && c2)
            return 0;
        else if(c1 && !c2)
            return d1;
        else if(!c1 && c2)
            return d2;
        return d1+d2;
    }
    void solve() {

        int n;
        cin >> n;
        // assert(n<=30);
        Figure P[n];
        vector<int>forx,fory;
        rep(i,n){
            cin>>P[i].x1>>P[i].y1>>P[i].x2>>P[i].y2;
            forx.pb(P[i].x1);
            forx.pb(P[i].x2);
            fory.pb(P[i].y1);
            fory.pb(P[i].y2);
        }
        sort(all(forx));
        sort(all(fory));
        // dbg(forx);
        // dbg(fory);
        int x=forx[(SZ(forx)-1)/2];
        int y=fory[(SZ(fory)-1)/2];
        cout<<x<<" "<<y<<"\n";
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        cout<<"Case #"<<tt<<": ";
        Testcase T;
        T.solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}