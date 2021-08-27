// AUTHOR: SUMIT PRAJAPATI      
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
#define all(a) a.begin(),a.end()
#define trav(v) for(auto &el:v)
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
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 1 
 
 
 
 
 
void solve(){
  
    ll n,m,t;
    cin>>n>>m>>t;
    ll p[n+1];
    pair<ll,ll>ass[m+1];
    repe(i,n)
        cin>>p[i];
    repe(i,m)
        cin>>ass[i].ss;
    repe(i,m)
        cin>>ass[i].ff;
    sort(p+1,p+n+1);    
    sort(ass+1,ass+m+1);
    ll total_time=0;
    for(ll i=m;i>m/2;i--){
        total_time+=ass[i].ss;
    }    
    assert(total_time<=t);
    t-=total_time;
    // cout<<t<<" "<<total_time<<"\n";
    ll ans=0;
    repe(i,n)
    {   

        // cout<<p[i]<<" "<<t<<"\n";
        if((p[i]<=t)){
            ans++;
            t-=p[i];
        }
    }
    cout<<ans<<'\n';
    
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}