//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                     unsigned long long
#define ll                      long long
#define int                     long long
#define pii                     pair<int, int>
#define pll                     pair<ll, ll>
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define SZ(x)                   ((int)x.size())
#define set_bits                __builtin_popcountll
#define all(a)                  a.begin(),a.end()
#define trav(x,v)               for(auto &x:v)
#define rep(i,n)                for(int i=0;i<n;i++)
#define repe(i,n)               for(int i=1;i<=n;i++)
#define FOR(i,a,b)              for(int i=a;i<=b;i++)
#define curtime                 chrono::high_resolution_clock::now()
#define timedif(start,end)      chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define myshuffle(a,n)          FOR(i,1,n-1) swap(a[i], a[rand() % (i + 1)])
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 2e5 + 5;



vector<pii>G[MX];


bool vis[MX];
bool color[MX];
int zero,one;
//returns false if the graph is not bipartite.
bool dfs(int u,int col){

    vis[u]=true;
    color[u]=col;
    zero+=(col==0);
    one+=(col==1);
    for(auto &ch:G[u]){
        int c=ch.ff,h=ch.ss;
        if((!vis[c] && dfs(c,col^h)==false) || 
            (vis[c] && color[u]^h!=color[c])){
            return false;    
        }
    }
    return true;
}

void solve() {

    int n,m;
    cin>>n>>m;
    int x,y;
    string s;
    repe(i,n){
        vis[i]=0;
        color[i]=0;
        G[i].clear();
    }
    repe(i,m){
        cin>>x>>y>>s;
        int w=(s=="imposter");
        G[x].pb({y,w});
        G[y].pb({x,w});
    }
    int ans=0;
    repe(i,n){
        zero=0;
        one=0;
        if(!vis[i]){
            bool ok=dfs(i,0);
            if(!ok){
                cout<<"-1\n";
                return;
            }
            ans+=max(zero,one);
        }
    }
    cout<<ans<<"\n";


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}