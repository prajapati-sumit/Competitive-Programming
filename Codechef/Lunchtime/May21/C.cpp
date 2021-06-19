// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define int                 long long           
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
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e7+1;

 
 
vector<int>isprime(MX,1);
vector<int>primes;
int n; 
int sz;
void init(){
    isprime[1]=0;
    isprime[0]=0;
    for(int i=2;i*i<=MX;i++){
        if(isprime[i]){
            for(int j=i*i;j<MX;j+=i)
                isprime[j]=0;
        }
    }
    FOR(i,2,MX-1)
        if(isprime[i])
            primes.pb(i);
    sz=primes.size();
    // cout<<sz<<" "<<primes.back()<<'\n';
}
void solve(){
  
    cin>>n;
    int l=0,r=sz-1;
    int valid=0;
    int mid;
    while(l<=r){
      
        mid=(l+r)>>1;
        if(2*primes[mid]<=n)
            valid=mid,l=mid+1;
        else
            r=mid-1;
    }

    int total=0;
    l=0;r=sz-1;
    while(l<=r){
        mid=(l+r)>>1;
        if(primes[mid]<=n)
            total=mid,l=mid+1;
        else
            r=mid-1;
    }
    cout<<total+1<<" "<<(valid+1)<<' ';
    int ans=total+1-(valid+1)+1;
    cout<<ans<<'\n';
  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}