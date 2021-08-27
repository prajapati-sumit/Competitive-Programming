//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long           
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
const int INF=1e9;
const int MX=3e5+5;

 
 
int a[MX];
int n,m; 

bool valid(int k){

    vector<bool> vis(n,0);
    int n_swaps=0;
    rep(i,n){
        if(!vis[i]){
            int cnt=1;
            int cur=i;
            vis[cur]=1;
            while((a[cur]+k)%n!=i){
                // cerr<<i<<" "<<cur<<"\n";
                cnt++;
                cur=(a[cur]+k)%n;
                vis[cur]=1;
            }
            n_swaps+=(cnt-1);
        }
    }
    // cout<<k<<" "<<n_swaps<<'\n';
    return n_swaps<=m;
}
void solve(){
  
    cin>>n>>m;
    vector<int>K(n,0);
    
    int rem=n-2*m;
    rep(i,n){
        cin>>a[i];
        a[i]--;
        K[(i-a[i]+n)%n]++;
    }     
    
    vector<int>v;
    rep(i,n){
        // cout<<i<<" "<<K[i]<<'\n';
        if(K[i]>=rem)
            v.pb(i);
    }
    vector<int>ans;
    for(auto &el:v){
        if(valid(el))
            ans.pb(el);
    }
    cout<<ans.size()<<' ';
    for(auto &el:ans)
        cout<<el<<" ";
    cout<<'\n';

 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    // n=4;
    // a[0]=1;
    // a[1]=2;
    // a[2]=0;
    // a[3]=3;
    // cout<<'\n';
    // valid(3);
    // return 1;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}