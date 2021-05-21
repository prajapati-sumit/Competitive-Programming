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
 
 
void solve(){
  
    int n;
    cin>>n;
    int total=(n*(n+1))/2;
    ll dp[total+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    rep(i,n){
        int cur=i+1;
        for(int j=total;j>=cur;j--)
            if(dp[j-cur])
                dp[j]=(dp[j-cur]+dp[j])%MD;
    //      repe(i,total)
    //     cout<<dp[i]<<" ";
    // cout<<'\n';
    }
   
    if(total&1)
        cout<<0;
    else{
        ll ans=(dp[total/2]*bin_power(2,MD-2,MD))%MD;
        cout<<ans;
   } 

 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    // cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}