// AUTHOR: SUMIT PRAJAPATI      
#include "bits/stdc++.h"
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
const int MX=1e6+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
int LPF[MX]; 

 
void init(){

    repe(i,MX-1)
        LPF[i]=i;
    for(int i=2;i*i<=MX;i++){
        if(LPF[i]==i){
            for(int j=i*i;j<=MX;j+=i)
                if(LPF[j]==j)
                    LPF[j]=i;
        }
    }


} 
 
void solve(){
  
    int n;
    cin>>n;
    map<int,int>mp;
    while(n>1){
        int cur_factor=LPF[n];
        n/=cur_factor;
        mp[cur_factor]++;
    }
    int ans=0;
    for(auto x:mp){
        ans=max(ans,x.ss);
    }
    cout<<ans<<'\n';
    

  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;
    init();
    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}