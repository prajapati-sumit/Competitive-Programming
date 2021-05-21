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
 
 
 
 
 
 
void solve(){
  
    ll n;
    cin>>n;
    ll cnt=0;
    ll mul=9,i,comma=0,sz=ceil(log10((double)n+1));
    // cout<<sz<<'\n';
    for(i=0;i<(sz-1);i++){
        if(i%3==0 && i>=3)
            comma++;
        // cout<<mul<<" ";
        cnt+=(comma)*(mul);
        
        mul=mul*10;
    }
    if(i%3==0 && i>=3)
        comma++;
    // cout<<cnt<<" "<<i<<"\n";
    ll m1=pow(10,i)-1;
    cnt+=(n-m1)*comma;
    // cout<<pow(10,i)-1<<" "<<comma<<" "<<(n-pow(10,i)-1)<<" ";
    cout<<cnt;
 
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
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}