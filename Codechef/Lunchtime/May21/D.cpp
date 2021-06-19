// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define int                 long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e13;
const int MX=1e5+1;

 
 
void solve(){
  
    int  n,k;
    cin>>n>>k;
    int a[n+1];    
    repe(i,n)
        cin>>a[i];
    int dp[n+1][k+1];
    repe(i,k)
        dp[0][i]=-INF;
    repe(i,n)
        dp[i][0]=-INF;
    int ans=-INF,cur,prev;
    for(int j=1;j<=k;j++){
        prev=-INF;
        for(int i=1;i<=n;i++){
            // int op1=max(dp[1 to i-1][j-1])+j*a[i];
            // int op2=max(dp[1 to i-1][j])+j*a[i];
            int op1=(j==1?max(0LL,prev):prev)+j*a[i];
            int op2=dp[i-1][j]+j*a[i];

            dp[i][j]=max(op1,op2);
            prev=max(prev,dp[i][j-1]); 
            if(j==k)
                ans=max(ans,dp[i][j]);          
        }
        

    }
    cout<<ans<<'\n';
    // repe(i,n)
    //     repe(j,k)
    //         cerr<<dp[i][j]<<" \n"[j==k];

} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}