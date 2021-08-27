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
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define TESTCASES 1

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 
int n,p; 
set<ll>s; 
ll cnt=0;
vector<int>primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
void fn(int target,ll n,ll now,int prev){
    if(target<=n){
        cnt++;
        s.insert(now);
    }
    trav(primes){
        if(el>target)
            break;
        if(el>=prev){
            fn(target-el,n,(now*el)%p,el);
        }
    }

}
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
ll maxCanget(ll n){
    ll res=1;
    if(n%3==0)
        return bin_power(3,n/3,MD); 
    while(n!=4 && n!=2)
        res*=3,n-=3;
    res*=n;
    return res;
}
bool isvalid(ll n,ll x){
    ll sum=0;
    trav(primes){
        ll cnt=0;
        while(x>1 && x%el==0 )
            cnt++,x/=el;
        sum+=(cnt*el);
    }
    return (x==1 && sum<=n);
}
void solve(){
  
    s.clear();
    cin>>n>>p;
    fn(n,n,1,0);
    ll limit=maxCanget(n);
    // cout<<limit<<'\n';
    // trav(s)
    //     cout<<el<<" ";
    // cout<<"\n";
    // cout<<cnt<<" ";
    cout<<s.size()<<'\n';
    // cnt=0;
    // repe(i,limit){
    //     if(isvalid(n,i)){
    //         cnt++;
    //         cout<<i<<" ";
    //     }
    // }
    // cout<<'\n';
    // cout<<cnt<<'\n';
  
 
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