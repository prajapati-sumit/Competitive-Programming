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
const int MX=1e6;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<long long unsigned> distribution(0,0xFFFFFFFFFFFFFFFF); 
 
 
 
 
void solve(){
  
    int n;
    int m;
    cin>>n>>m;
    int x,y;
    repe(i,n)    
        cin>>x>>y;
    int z,w;
    repe(i,m)
        cin>>x>>y>>z>>w;
    repe(i,m){
        int fir=distribution(generator)%(2*MX + 1) -MX;
        int sec=distribution(generator)%(2*MX + 1) -MX;
        cout<<fir<<" "<<sec<<'\n';
    }
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t=1;
    //cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}