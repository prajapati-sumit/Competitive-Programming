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
const int MX=4e5+5;

 
set<int>v[MX]; 
int n,m;
int ans[MX]; 
int color[MX];
// 0:white,1:grey,2:black
bool cycles[MX];
void dfs(int cur,int par){
    cerr<<cur<<" "<<par<<" "<<color[cur]<<"\n";
    if(color[cur]==1){
        cycles[cur]=true;
        v[par].erase(cur);
        return;
    }
    color[cur]=1;
    for(auto &el:v[cur]){
        dfs(el,cur);
    }
    color[cur]=2;
    return ;
}
void dfs2(int cur,bool inf){
    // cout<<cur<<" "<<inf<<" "<<vis[cur]<<'\n';
    inf|=cycles[cur];
    if(inf)
        ans[cur]=-1;
    else if(ans[cur]==0)
        ans[cur]=1;
    else
        ans[cur]=2;
    for(auto &el:v[cur]){
        dfs2(el,inf);
    }

}
void solve(){
 
    cin>>n>>m;
    repe(i,n)
        v[i].clear();
    repe(i,n)
        color[i]=0,ans[i]=0,cycles[i]=0;
    
    repe(i,m){
        int x,y;
        cin>>x>>y;
        v[x].insert(y);
    }
    dfs(1,-1);
    dfs2(1,cycles[1]);

    repe(i,n)
        cout<<ans[i]<<" \n"[i==n];
  
 
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