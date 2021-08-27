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
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;




string K;
int n, D;
// string tmp;
int dp[MX][101][2];
int fn(int cur, int sum, bool onedge) {
    if (cur > n)
        return 0;
    if (cur == n  && sum == 0){
        // cout<<tmp<<'\n';
        return 1;
    }
    if(dp[cur][sum][onedge]!=-1)
        return dp[cur][sum][onedge];
    int lim = (onedge ? K[cur]-'0' : 9);
    int res = 0;
    rep(i, lim + 1) {
        // tmp.pb((char)'0'+i);
        res = (res + fn(cur + 1, (sum + i + D) % D, onedge && i == lim   ) ) % MD;
        // tmp.pop_back();
    }
    return dp[cur][sum][onedge]=res;
}
void solve() {

    cin >> K;
    cin >> D;
    n = K.length();
    memset(dp,-1,sizeof(dp));
    int ans = (fn(0, 0, 1)-1+MD)%MD;
    cout << ans << '\n';



}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}