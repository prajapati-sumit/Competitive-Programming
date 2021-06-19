//~ author      : Sumit Prajapati
//~ mail ID     : sumitprajapati821@gmail.com
//~ codefoces   : sumitprajapati81, codechef: sumit141   
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
// #define int                 long long           
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
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

 

void solve(){
  
    int n;
    cin>>n;
    // n=2000;
    int a[n+1];
    vector<int>v;
    repe(i,n){
       cin>>a[i];
       if(a[i]%2==0)
        v.pb(a[i]);
    }
    repe(i,n)
    {
        if(a[i]&1)
            v.pb(a[i]);
        // a[i]=i;
    }
    assert(v.size()==n);
    int ans=0;
    // rep(i,n)
    //     cout<<v[i]<<" \n"[i==n-1];
    rep(i,n)
        FOR(j,i+1,n-1){
            // cout<<a[i]<<" "<<a[j]<<'\n';
            ans+=(__gcd(v[i],2*v[j])>1);
        }
    cout<<ans<<'\n';
  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}