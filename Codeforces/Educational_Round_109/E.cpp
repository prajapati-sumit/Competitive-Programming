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
#define rep(i,n)            for(ll i=0;i<n;i++)
#define repe(i,n)           for(ll i=1;i<=n;i++)
#define FOR(i,a,b)          for(ll i=a;i<=b;i++)
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
 
ll inv(ll n){
    ll res=1;
    for(ll i=1;i<=n;i++)
        res=(res*i)%MDL;
    
    res=bin_power(res,MDL-2,MDL);
    return res;
} 
 
void solve(){
  
    ll n,m;
    cin>>n>>m;
    ll cnt[m][n];
    ll a[n][m];
    rep(i,n)
        rep(j,m)
            cin>>a[i][j]; 
    memset(cnt,0,sizeof(cnt));      
    rep(j,m){
        for(ll k=0;k<n;k++){
            ll heCanGo=n-k;
            for(ll i=0;i<n;i++)
                if(a[i][j]>heCanGo)
                    cnt[j][k]++;

        }
    }
    // rep(j,m)
    //     rep(k,n)
    //         cout<<cnt[j][k]<<" \n"[k==n-1];
    ll ans=0;
    ll good[m];
    for(ll j=0;j<m;j++){
        
        good[j]=cnt[j][0];
        for(ll k=1;k<n;k++){
            good[j]=(good[j]*(cnt[j][k]-k))%MDL;
        }
    }
    // rep(i,m)
    //     cout<<good[i]<<" \n"[i==m-1];
    ll inv_n=inv(n);
    for(ll j=0;j<m;j++){
        ll Pj=(1-(good[j]*inv_n)%MDL + MDL)%MDL;
        ans+=Pj;
        ans%=MDL;
    }
    cout<<ans<<'\n';
  
 
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