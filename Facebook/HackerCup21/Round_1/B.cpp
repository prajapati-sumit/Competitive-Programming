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
const int MX = 1e5 + 5;





void solve() {

    
    int n,m;
    cin>>n>>m;
    int a[n][m];
    rep(i,n)
        rep(j,m)
            a[i][j]=1000;
    int A,B;
    cin>>A>>B;
    if(A<(n+m-1) || B<(n+m-1)){
        cout<<"Impossible\n";
        return;
    }
    int remA=A-(n+m-2),remB=B-(n+m-2);
    rep(i,n)
        a[i][0]=1,a[i][m-1]=1;
    rep(i,m)
        a[0][i]=1,a[n-1][i]=1;
    a[n-1][m-1]=remA;
    a[n-1][0]=remB;
    cout<<"Possible\n";
    rep(i,n)
        rep(j,m)
            cout<<a[i][j]<<" \n"[j==m-1];

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