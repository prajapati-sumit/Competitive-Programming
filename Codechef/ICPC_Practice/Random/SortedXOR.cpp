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
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()


const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 1 
 
const int MAXLOG=5; 
 
ll nc2(ll x){
    if(x<2)
        return 0;
    return (x*(x-1))/2;
}
 
void solve(){
  
    ll n=4;
    // ll a[]={11,5,12,3};
    ll k=5;
    cin>>n>>k;
    ll a[n+1];
    rep(i,n)
        cin>>a[i];

    ll cur=MAXLOG-1;
    ll ON[MAXLOG],OFF[MAXLOG];
    ll on=0,off=0;
    ll onehere,zerohere;
    ll ans=0;
    for(ll j=MAXLOG-1;j>=0;j--){
        on=0;
        off=0;
        onehere=0;
        zerohere=0;
        cout<<ans<<" \n";
        rep(i,n){
            // cout<<(a[i]&(1<<j))<<" \n";

            if((ans&(1<<(j+1)))^(a[i]>>(j+1))==0){
                cout<<bitset<5>(a[i])<<" \n";
                on+=((a[i]&(1<<j))!=0);
                off+=((a[i]&(1<<j))==0);
            }
        }
        onehere=(on*off);
        zerohere=nc2(on)+nc2(off);
        if(zerohere<k){
            k-=zerohere;
            ans|=(1<<j);
        }
        cout<<zerohere<<" "<<onehere<<"\n";
        cout<<'\n';
    }
    multiset<int>s,dif;
    rep(i,n){
        FOR(j,i+1,n-1){
            s.insert(a[i]^a[j]);
        }
    }    
    trav(s){
        // cout<<bitset<5>(el)<<" \n";
        cout<<el<<" ";
    }
    cout<<"\n";

    cout<<ans<<"\n";
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