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
const int MX = 3e5 + 5;



// #warning works on array from 1...n
// with path compression and union by rank.
class DSU{

public:
    vector<int>parent;
    vector<int>val;

    DSU(int n){
        parent.resize(n+1);
        val.resize(n+1);
        for(int i=1;i<=n;i++)
            parent[i]=-1,val[i]=0;
    }
    int find_set(int x){
        return parent[x]<0?x:parent[x]=find_set(parent[x]);
    } 
    void union_set(int a,int b){
        int pa=find_set(a);
        int pb=find_set(b);
        if(pa==pb)
            return;
        if(parent[pa]>parent[pb])
            swap(pa,pb);

        parent[pa]+=parent[pb];
        parent[pb]=pa;
    } 
    bool same_set(int a,int b){
        return find_set(a)==find_set(b);
    }

};
vector<int>v[MX];
int color[MX];
int vis[MX];
void dfs(int u,int col){
    color[u]=col;
    vis[u]=1;
    for(auto &el:v[u]){

        // assert(color[el]==-1 || color[u]!=color[el]);
        // if(!(color[el]==-1 || color[u]!=color[el])){
        //     cout<<u<<" "<<el<<"\n";
        // }
        if(!vis[el])
            dfs(el,col^1);
    }
}
void solve() {

    int n,m;
    cin>>n>>m;
    vector<pii>rem;
    DSU D(n);
    repe(i,m){
        int x,y;
        string s;
        cin>>x>>y>>s;
        if(s=="imposter")
            rem.pb({x,y});
        else{
            D.union_set(x,y);
        }
    }
    int nax=0;
    vector<int>val;
    map<int,int>mp;
    repe(i,n)
        if(D.parent[i]<0){
            mp[i]=nax++;
            val.pb(-D.parent[i]);
        }
    rep(i,nax)
        color[i]=-1,vis[i]=0,v[i].clear();
    for(auto &el:rem){
        if(D.same_set(el.ff,el.ss)){
            cout<<"-1\n";
            return;
        }
        else{

            int p1=D.find_set(el.ff);
            int p2=D.find_set(el.ss);
            v[mp[p1]].pb(mp[p2]);
            v[mp[p2]].pb(mp[p1]);
        }

    }

    int ans=0;
    rep(i,nax)
        if(!vis[i]){

            dfs(i,0);
        }
    rep(i,nax){
        if(color[i]==0)
            ans+=(val[i]);
    }
    ans=max(ans,n-ans);
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