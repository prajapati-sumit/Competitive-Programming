//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define SZ(x)               ((int)x.size())
#define set_bits            __builtin_popcountll
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;





void solve() {

    int n;
    cin >> n;
    int a[n];
    int b[n];
    vector<int> final(n, -1);
    int ans = 0;
    rep(i, n)
    cin >> a[i];
    rep(i, n)
    cin >> b[i];

    int res = 0;
    for (int i = 31; i >= 0; i--) {
        bool can = true;
        vector<int>pos(n, -1);
        int cnt = 0;
        rep(j, n) {
            if ((a[j] & (1LL << i)) && (b[j] & (1LL << i)))
                continue;
            if (final[j] != 1 && (a[j] & (1LL << i))) {
                pos[j] = 0;
            }
            else if (final[j] != 0 && (b[j] & (1LL << i))) {
                if (final[j] ==-1)
                    cnt++;
                pos[j] = 1;
            }
            else {
                can = false;
                break;
            }
        }
        if (can) {
            res |= (1LL << i);
            rep(j, n)
                final[j] = pos[j];
            ans += cnt;
        }
    }
    assert(ans<=n);
    cout << res << " " << ans << '\n';



}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}