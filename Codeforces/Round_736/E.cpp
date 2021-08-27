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
const int MX = 3e6 + 5;

int fact[MX];
int dp[MX][3];
int ncrx[MX];
int inv[MX];

ll bin_power(ll a,ll b,ll md){
    ll res=1;
    while (b){
        if (b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
}

int inv3=bin_power(3,MD-2,MD);
void solve() {

    int n, q;
    cin >> n >> q;
    dp[0][0] = n;
    dp[0][1] = n;
    dp[0][2] = n;
    ncrx[0]=1;
    repe(i,3*n+1){
        ncrx[i]=(ncrx[i-1]*(3*n-i+1))%MD;
        ncrx[i]=(ncrx[i]*inv[i])%MD;
        // cout<<ncrx[x]<<"\n"
    }
    // cout<<"hi\n";
    // return;
    for(int x=1;x<=3*n;x++){
        dp[x][0]=(ncrx[x+1]-2*dp[x-1][0]-dp[x-1][1]+3*MD)%MD;
        dp[x][0]=(dp[x][0]*inv3)%MD;
        dp[x][1]=(dp[x][0]+dp[x-1][0])%MD;
        dp[x][2]=(dp[x][1]+dp[x-1][1])%MD;
    }
    repe(i,q){
        int x;
        cin>>x;
        int ans=(dp[x][0]+ncrx[x])%MD;
        cout<<ans<<'\n';
    }

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    // cin>>t;
    fact[0]=1;
    repe(i,MX-1)
        fact[i]=i*fact[i-1]%MD;
    inv[1] = 1;
    for(int i = 2; i < MX; ++i)
        inv[i] = MD - (MD/i) * inv[MD%i] % MD;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}