//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define ld                  long double
// #define int                 long long           
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
const int MX=1e5+5;

 
 
 
 
void solve(){
  
    int n;
    cin>>n;
    ld a[n+1];
    repe(i,n)
        cin>>a[i];
    ld dp[n+1][n+1],ans=0;
    dp[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 && j==0){
                continue;
            }
            if(i+j>n)
                continue;
            dp[i][j]=0;
            if(i>0)
                dp[i][j]+=a[i+j]*dp[i-1][j];
            if(j>0)
                dp[i][j]+=(1.0-a[i+j])*dp[i][j-1];
        }
    }
  
    for(int i=n;i>n/2;i--)
        ans+=dp[i][n-i];
    cout<<ans<<'\n';
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cout<<setprecision(11)<<fixed;
    // cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}