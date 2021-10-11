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


int mat[101][101];
int res[101][101];
int n, m;
int a[101];

int bin_power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1LL)
            res = (res * a) % MD;
        a = (a * a) % MD;
        b >>= 1;
    }
    return res;
}
void multiply(bool which) {
    int tmp[m + 1][m + 1];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            tmp[i][j] = 0;
            for (int k = 1; k <= m; k++) {
                if (which)
                    tmp[i][j] = (tmp[i][j] + res[i][k] * mat[k][j] % MD) % MD;
                else
                    tmp[i][j] = (tmp[i][j] + mat[i][k] * mat[k][j] % MD) % MD;
            }
        }
    }
    if (which) {
        repe(i, m)
            repe(j, m)
                res[i][j] = tmp[i][j];
    }
    else {
        repe(i, m)
            repe(j, m)
                mat[i][j] = tmp[i][j];
    }

}
void mat_power(int p) {

    while (p) {
        if (p & 1LL) {
            multiply(1);
        }
        p >>= 1;
        multiply(0);
    }

}
void solve() {

    cin >> n >> m;
    repe(i, m)
        cin >> a[i], a[i] = (a[i] + 1) % MD;

    if (n <= m) {
        cout << (a[n] - 1 + MD) % MD << "\n";
        return;
    }
    if (m == 1) {
        cout << (a[1] - 1 + MD) % MD << "\n";
        return;
    }
    for (int j = 1; j <= m - 1; j++) {
        mat[j + 1][j] = 1;
    }
    for (int i = 1; i <= m; i++) {
        mat[i][m] = 1;
    }
    repe(i, m)
        res[i][i] = 1;

    // repe(i,m)
    //     repe(j,m)
    //         cout<<mat[i][j]<<" \n"[j==m];

    int p = n - m;

    mat_power(p);

    // repe(i,m)
    //     repe(j,m)
    //         cout<<res[i][j]<<" \n"[j==m];
    int ans = 1;
    for (int i = 1; i <= m; i++) {
        ans = (ans * bin_power(a[i], res[i][m])) % MD;
    }
    ans = (ans + MD - 1) % MD;
    cout << ans << '\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}