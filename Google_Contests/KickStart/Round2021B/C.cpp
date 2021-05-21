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


const ll INF=9e11;
const ll MX=1e6+5;
const ll MD=1e9+7;
const ll MDL=998244353;
auto time0 = curtime;
#define TESTCASES 1 
 
bool isPrime[MX];
vector<ll>primes;

void init(){
    isPrime[1]=true;
    for(ll i=2;i*i<=MX;i++){
        if(!isPrime[i]){
            for(ll j=i*i;j<MX;j+=i)
                isPrime[j]=true;
        }
    }
   
    repe(i,MX-1)
        if(!isPrime[i]){
            primes.pb(i);
        }
} 
 
 
 
void solve(){

    ll z;
    cin>>z;
    ll sq=sqrt(z);
    ll L=max(1LL,sq-1000),R=sq+1000;
    vector<bool> cand(R-L+1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            cand[j - L] = false;
    if (L== 1)
        cand[0] = false;
    ll cur=1;
    vector<ll> help;
    rep(i,R-L+1){
        if(cand[i]){
            help.pb(cur*(i+L));
            cur=(i+L);
        }
    }
    ll ans=6,l=0,r=help.size()-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(help[mid]<=z){
            ans=help[mid];
            l=mid+1;
        }
        else r=mid-1;

    }
    cout<<ans<<"\n";
        
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}