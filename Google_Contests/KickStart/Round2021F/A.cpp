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
const int INF = 1e16;
const int MX = 5e5 + 5;



vector<int>G[MX];
int dist[MX];
bool vis[MX];
void solve() {

    int n;
    cin>>n;
    string s;
    cin>>s;
    repe(i,n)
        G[i].clear();
    repe(i,n-1)
        G[i].pb((i+1)),G[i+1].pb(i);
    queue<int>Q;
    rep(i,n){
        if(s[i]=='1'){
            dist[i+1]=0;
            Q.push(i+1);
            vis[i+1]=1;
        }
        else{
            vis[i+1]=0;
            dist[i+1]=INF;
        }
    }
    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        for(int x:G[cur])
            if(!vis[x]){
                vis[x]=1;
                Q.push(x);
                dist[x]=dist[cur]+1;
            }

    }
    int ans=0;
    repe(i,n){
        // cout<<dist[i]<<" \n"[i==n];
        ans+=dist[i];
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
        cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}