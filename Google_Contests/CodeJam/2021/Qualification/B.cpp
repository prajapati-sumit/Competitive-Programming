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
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const ll INF=1e16;
const ll MX=1e3+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 
 
 
ll X,Y;
string s;
ll n; 
ll dp[MX][4];
ll fn(ll cur,ll prev){

    if(cur==n)
        return 0;
    if(dp[cur][prev]!=-INF)
        return dp[cur][prev];
  
    if(s[cur]=='C'){
        if(prev==1)
            return dp[cur][prev]=Y+fn(cur+1,0);
        else 
            return dp[cur][prev]=fn(cur+1,0);

    }
    else if(s[cur]=='J'){
        if(prev==0)
            return dp[cur][prev]=X+fn(cur+1,1);
        else
            return dp[cur][prev]=fn(cur+1,1);
    }
    else{
        if(prev==0){
             return dp[cur][prev]=min(fn(cur+1,0),X+fn(cur+1,1));
        }
        else if(prev==1)
        {
            return dp[cur][prev]=min(Y+fn(cur+1,0),fn(cur+1,1));
        }
        else 
            return dp[cur][prev]=min(fn(cur+1,0),fn(cur+1,1));
    }
    return 0;

}
void solve(){

    rep(i,MX)
        rep(j,4)
            dp[i][j]=-INF;
    cin>>X>>Y;
    cin>>s;
    n=s.length();
    ll ans=fn(0,3);
    // rep(i,n){
    //     rep(j,4)
    //         cout<<dp[i][j]<<" ";
    //     cout<<'\n';
    // }
    cout<<ans<<'\n';
  
 
} 
  // CJ?CC?
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}