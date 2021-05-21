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

const ll INF=1e10;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
ll n,x,a[102]; 

// ll fn(ll sum,ll num,bitset<n>bits){
     
//     if((x-sum)%num==0){
//         return (x-sum)/num;
//     }
//     ll res=INF;
//     rep(i,n){
        
//         if(b.test(i)){
//             res=min(res,fn(sum-a[i+1],num-1,bits.flip()));
//         }
//     }
//     return =res;
// }
 
void solve(){
    cin>>n>>x;
    cout<<n<<" "<<x<<'\n';
    // ll sum=0;
    // repe(i,n)
    //     cin>>a[i],sum+=a[i];
    // sort(a+1,a+n+1);
    // bitset<n>bits;
    // bits.set()
    // ll ans=fn(sum,n,bits);
    // cout<<ans<<'\n';    
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    //cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}