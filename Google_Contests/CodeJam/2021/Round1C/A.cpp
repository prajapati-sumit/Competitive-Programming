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
 
 
bool cmp(ll x,ll y){
    return x>y;
}

void solve(){
  
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    repe(i,n)
        cin>>a[i];    
    sort(a+1,a+n+1);

    vector<ll>v;
    v.pb(a[1]-1);
    repe(i,n-1){
        ll l=a[i],r=a[i+1];
        if(r-l==0 || r-l==1)
            continue;
        if(r-l==2){
            v.pb(1);
            continue;
        }

        ll can=(r-l)/2;
        v.pb(can);
        if((r-l)%2==0)
            v.pb(can-1);
        else 
            v.pb(can);
        
    }
    v.pb(k-a[n]);
    sort(all(v),cmp);

    ll max_can=v[0]+v[1];
    // cout<<max_can<<'\n';
    double ans=(double)((1.0*max_can)/k);
    printf("%0.8f\n",ans);
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        printf("Case #%d: ",tt);
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}