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

const int MX = 1e5 + 5;
const int LOG = 19;
vector<int> v[MX];
int up[MX][LOG]; // up[u][j] is 2^j-th ancestor of u
int level[MX];

int n,q;

void dfs(int cur, int par) {
    level[cur] = level[par] + 1;
    up[cur][0] = par;
    for (int i = 1; i < LOG; ++i)
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    for (auto &el : v[cur]) {
        if (el != par)
            dfs(el, cur);
    }
}

int get_lca(int x, int y) {
    if (level[x] < level[y])
        swap(x, y);
    int diff = level[x] - level[y];
    for (int i = 0; i < LOG; ++i) {
        if ((1 << i) & diff)
            x = up[x][i];
    }
    if (x == y)
        return x;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[x][i] != up[y][i]) {
            x = up[x][i];
            y = up[y][i];
        }
    }
    return up[x][0];
} 

int get_dist(int x,int y){
    return level[x]+level[y]-2*level[get_lca(x,y)];
}
 
void solve(){
  
    cin>>n>>q;
    repe(i,n-1){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }  
    dfs(1,-1);
    repe(i,q){
        int x,y;
        cin>>x>>y;
        int d=get_dist(x,y);
        if(d&1)
            cout<<"Road\n";
        else
            cout<<"Town\n";
    }
  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}