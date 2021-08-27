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
const int MX=1e3+5;



void solve(){
    
    int n,k;
    cin>>n>>k;
    int a[n+1];
    
    int nax=0;
    repe(i,n)
        cin>>a[i],nax=max(a[i],nax);
    int ans=1;
    int dp[n+1][k+1];
    // dp[i][j]=max length of j-beautiful subseq of 
    //          first i elements ending at i
    // dp[i][j]=max(same:last[a[i]][k],dp[<i][k-1])
    vector<int>last(nax+1,0);
    
    dp[0][0]=0;
    repe(i,n){
        dp[i][0]=1+last[a[i]];
        last[a[i]]=dp[i][0];
        dp[i][0]=max(dp[i][0],dp[i-1][0]);
        // cout<<dp[i][0]<<" ";
    }
    repe(j,k)
        dp[0][j]=0;
    // cout<<'\n';
    repe(j,k){
        repe(i,nax)
            last[i]=0;
        repe(i,n){
            dp[i][j]=1+max(dp[i-1][j-1],last[a[i]]);
            last[a[i]]=dp[i][j];
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            // cout<<i<<" "<<j<<" "<<dp[i][j]<<" \n";
        }
        // cout<<n<<" "<<j<<"\n";
        // cout<<dp[n][j]<<" "<<ans<<'\n';
        ans=max(ans,dp[n][j]);
    }

    cout<<ans<<'\n';

  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}