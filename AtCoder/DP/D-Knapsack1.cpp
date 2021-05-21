//CODED BY SUMIT KUMAR PRAJAPATI
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
ll N,W;
ll weight[101],value[101]; 
ll dp[101][MX]; 

ll fn(ll n,ll w){
    if(w<0)
        return -INF;
    if(w==0)
        return 0;
    if(n==0)
        return 0; 

    if(dp[n][w]!=-1)
        return dp[n][w];

    return dp[n][w]=max(fn(n-1,w),value[n]+fn(n-1,w-weight[n]));
} 
 
void solve(){
  
    cin>>N>>W;
    memset(dp,-1,sizeof dp);
    repe(i,N)
        cin>>weight[i]>>value[i];
    ll ans=fn(N,W);
    // repe(i,N)
    // {
    //     rep(j,W+1)
    //         cout<<dp[i][j]<<" ";
    //     cout<<'\n';
    // }
    cout<<ans;

  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    //cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}