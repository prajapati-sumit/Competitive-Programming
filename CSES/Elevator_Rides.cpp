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
const int nax=2e6;
int n,x;
int a[21];
int dp[nax];
int fn(int sz){

    if(dp[sz]!=-1)
        return dp[sz];
    if(sz==0)
        return dp[sz]=0;

    int op1=fn(sz-1)+a[sz-1];
    int op2=fn(sz-1);
    int op3=a[sz-1];
    vector<int> v{0,op1,op2,op3};
    sort(all(v));
    for(int i=3;i>=0;i--)
        if(v[i]<=x)
            return dp[sz]=v[i];
    
    assert(false);
    return -1;



}
 
void solve(){
  
    
    cin>>n>>x;
    rep(i,n)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    int ans=fn(n);
    rep(i,n+1)
        cout<<dp[i]<<" \n"[i==n];
    cout<<ans;
           
  
 
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