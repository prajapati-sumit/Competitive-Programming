//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

int fact[MX];
string s;
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
int ncr(int n,int r){
    if(r>n)
        return 0;
    if(r==n)
        return 1;
    return (fact[n]*bin_power(fact[n-r],MDL-2,MDL)%MDL)*bin_power(fact[r],MDL-2,MDL)%MDL;
}

 
 
void solve(){
  
    int n;
    cin>>n;
    cin>>s;
    int zer=-1;
    int one=0;
    int cnt=0;
    s.pb('0');
    rep(i,n+1){
        if(s[i]=='0'){
            one+=cnt/2;
            cnt=0;
            zer++;
        }
        else
            cnt++;
    }
    // cout<<zer<<" "<<one<<" ";
    int ans=ncr(zer+one,zer);
    cout<<ans<<'\n';

  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    fact[0]=1;
    repe(i,MX-1)
        fact[i]=(i*fact[i-1])%MDL;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}