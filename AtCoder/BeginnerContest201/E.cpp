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
#define MX                  200'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
ll n;
vector<pll>v[MX];
ll prefixsum[MX];
ll level[MX];


void dfs(ll node,ll par,ll lev){
    
    
    level[node]=lev;
    for(auto x:v[node])
        if(x.ff!=par)
            dfs(x.ff,node,lev^x.ss);
}

void solve(){
    
    cin>>n;
    repe(i,n-1)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        v[x].pb({y,w});
        v[y].pb({x,w});
    }
    dfs(1,-1,0);
    vector<ll>helper;
    repe(i,n){
        ll here=level[1]^level[i];
        helper.pb(here);
    }
    ll ans=0;
    for(ll i=61;i>=0;i--){
        ll cnt1=0,cnt0=0;
        rep(j,n){
            if(helper[j]&(1LL<<i))
                cnt1++;
            else
                cnt0++;
        }
        ll help=(1LL<<i)%MD;
        ans=(ans+cnt0*cnt1*help)%MD;
    }
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