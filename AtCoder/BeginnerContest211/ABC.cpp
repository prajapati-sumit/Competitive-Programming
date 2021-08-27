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
const int MX=1e5+5;

 
string c="chokudai"; 

string s;
int dp[MX][10];

int fn(int n,int cur){
    if(cur==0)
        return 1;
    if(n==0)
        return 0;
    if(dp[n][cur]!=-1)
        return dp[n][cur];
    int res=0;
    res=fn(n-1,cur);
    if(s[n-1]==c[cur-1])
        res=(res+fn(n-1,cur-1))%MD;

    return dp[n][cur]=res;
}
void solve(){
  
    cin>>s;
    int n=s.length();
    memset(dp,-1,sizeof(dp));
    int ans=fn(n,8);
    cout<<ans<<'\n';
    // int cn=c.length();
    // int n=s.length();
    // int dp[n+1][cn+1];
    // rep(j,cn+1)
    //     dp[0][j]=0;
    // rep(i,n+1)
    //     dp[i][0]=1;
    // repe(i,n){
    //     repe(j,cn){
    //         dp[i][j]=dp[i-1][j];
    //         if(s[i-1]==c[j-1])
    //             dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MD;
    //     }
    // }
    // cout<<dp[n][cn]<<'\n';  
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