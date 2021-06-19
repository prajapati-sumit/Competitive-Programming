// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long           
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
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  100'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
 
 
void solve(){
  
    ll n;
    cin>>n;
    // ll dp[n+1][2];
    // dp[0][0]=0;
    // dp[0][1]=1;
    
    ll prev0=0,prev1=1,cur0,cur1;
    repe(i,n){
        cur0=(4*prev0+prev1)%MD;
        cur1=(prev0+(1<<(i>1))*prev1)%MD;
        prev0=cur0;
        prev1=cur1; 
        // dp[i][0]=(dp[i-1][1]+4*dp[i-1][0])%MD;
        // dp[i][1]=(dp[i-1][0]+dp[i-1][1])%MD;
        // if(i>1)
        //     dp[i][1]=(dp[i][1]+dp[i-1][1])%MD;

    }
    // repe(i,n)
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<'\n';
    ll ans=(cur0+cur1)%MD;
    cout<<ans<<'\n';


} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}