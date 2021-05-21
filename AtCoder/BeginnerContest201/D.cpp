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
#define INF                 1'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  100'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
 
 
void solve(){
  
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    rep(i,n)
        rep(j,m){
            char ch;
            cin>>ch;
            if(ch=='+')a[i][j]=1;
            else a[i][j]=-1;
        }
    ll dp[n][m][2];

    for(ll i=n-1;i>=0;i--){
        for(ll j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1){
                dp[i][j][1]=0;
                dp[i][j][0]=0;
                continue;
            }
            ll fir=(i==n-1)?-INF:a[i+1][j]+dp[i+1][j][0],
               sec=(j==m-1)?-INF:a[i][j+1]+dp[i][j+1][0],
               fira=(i==n-1)?INF:dp[i+1][j][1],
               seca=(j==m-1)?INF:dp[i][j+1][1];
            ll dif1=fir-fira,dif2=sec-seca;
            if(dif1>dif2){
                dp[i][j][1]=fir;
                dp[i][j][0]=fira;
            }
            else if(dif1<dif2){
                dp[i][j][1]=sec;
                dp[i][j][0]=seca;
            }
            else{
                if(fir>sec){
                    dp[i][j][1]=fir;
                    dp[i][j][0]=fira;
                }
                else{
                    dp[i][j][1]=sec;
                    dp[i][j][0]=seca;
                }
            }
           
            
            
        }
    }
    // rep(i,n){
    //     rep(j,m)
    //         cout<<"{"<<dp[i][j][1]<<" "<<dp[i][j][0]<<"} ";
    //     cout<<'\n';
    // }
    if(dp[0][0][1]>dp[0][0][0])
        cout<<"Takahashi";
    else if(dp[0][0][1]<dp[0][0][0])
        cout<<"Aoki";
    else
        cout<<"Draw";

  
 
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