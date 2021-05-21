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
#define MX                  5001


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
ll a[MX];
ll dp[MX][MX][2];

void solve(){
  
    ll n;
    cin>>n;
    rep(i,n)cin>>a[i];
   
    for(ll i=n-1;i>=0;i--){
        for(ll j=i;j<n;j++){
            if(i==j)
                dp[i][j][1]=a[i],dp[i][j][0]=0;
            else{
                ll fir=a[i]+dp[i+1][j][0];
                ll sec=a[j]+dp[i][j-1][0];

                if(fir>sec){
                    dp[i][j][1]=fir;
                    dp[i][j][0]=dp[i+1][j][1];
                }
                else{
                    dp[i][j][1]=sec;
                    dp[i][j][0]=dp[i][j-1][1];
                }
            }

        }
    }
    // rep(i,n){
    //     rep(j,n)
    //         cout<<" {"<<dp[i][j][1]<<" "<<dp[i][j][0]<<"} ";
    //     cout<<'\n';
    // }

    cout<<dp[0][n-1][1]<<'\n';
 
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