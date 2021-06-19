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
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e16;
const int MX=1e5+5;

 
const int base=20000003; 
const int maxn=1e7; 

void solve(){
  
    int n;
    cin>>n;
    int a[n+1];
    repe(i,n)
        cin>>a[i];
   
    map<pii,int>mp;
    for(int i=1;i<=n;i++){
        vector<int>temp;
        int sum=0;
        int hashed_val=0,pow=1;
        for(int j=i;j<=n;j++){
            sum+=a[j];
            hashed_val=(hashed_val+(a[j]+maxn)*pow)%MD;
            pow=(pow*base)%MD;
            mp[{hashed_val,sum}]++;
        }
    } 
    int ans=-INF;
    for(auto &el:mp)
        ans=max(ans,el.ff.ss*el.ss);
    cout<<ans<<'\n';  
  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}