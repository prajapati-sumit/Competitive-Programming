//CODED BY SUMIT KUMAR PRAJAPATI
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
 
ll n,m,k; 
 
ll bin_power(ll a,ll b,ll md){
    if(a==1)
        return 1;
    else if (a==0)
            return 0;
    ll res=1;
    while(b){
        if (b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
} 
 
 
void solve(){
    cin>>n>>m>>k;
    ll ans=0;
    if(n==1 && m==1){
        cout<<k;
        return ;
    }
    if(n==1){
       
        ans=bin_power(k,m,MDL);
        cout<<ans;
        return;

    }
    if(m==1){
        ans=bin_power(k,n,MDL);
        cout<<ans;
        return;
    }

    repe(x,k){
        ll cur=bin_power(x,n,MDL);
        
        cur=(cur+MDL-bin_power(x-1,n,MDL))%MDL;
        ll cur2=bin_power(k-x+1,m,MDL);
        
        ans=(ans+cur*cur2)%MDL;
        //cout<<cur<<" "<<cur2<<" "<<ans<<" \n";
        
        
    }
    cout<<ans;
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
   // cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}