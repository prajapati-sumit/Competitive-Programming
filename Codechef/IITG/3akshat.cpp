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
const int MX = 1e6 + 5;


int dp[MX][4];

void solve() {

    int n;
    cin>>n;
    rep(j,4)
        dp[1][j]=1;
    // 0:A,1:B,2:C,3:D
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3];
        dp[i][0]%=MD;

        dp[i][1]=dp[i-1][0]+dp[i-1][1]+dp[i-1][3];
        dp[i][1]%=MD;

        dp[i][2]=dp[i-1][0]+dp[i-1][2]+dp[i-1][3];
        dp[i][2]%=MD;

        dp[i][3]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3];
        dp[i][3]%=MD;
    }    
    int ans=(dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3])%MD;
    cout<<ans<<'\n';
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