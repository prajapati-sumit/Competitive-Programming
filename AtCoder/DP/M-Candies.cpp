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
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e2+5;

 
int a[MX]; 
int dp[MX][100001];

void solve(){
  
    int n,k;
    cin>>n>>k;
    repe(i,n)
        cin>>a[i];
    dp[0][0]=1;
    repe(i,k)
        dp[0][i]=1;
    repe(i,n){
        rep(j,k+1){
            dp[i][j]=dp[i-1][j];
            if(a[i]<j)
                dp[i][j]=(dp[i][j]-dp[i-1][j-a[i]-1]+MD)%MD;
            //sum of dp[i-1][j-a[i] to j];
            // cout<<dp[i][j]<<" ";
            dp[i][j]=(dp[i][j]+(j>0?dp[i][j-1]:0))%MD;
        }
        // cout<<'\n';
        
    }
    int ans=(dp[n][k]-dp[n][k-1]+MD)%MD;
    cout<<ans<<'\n';
  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}