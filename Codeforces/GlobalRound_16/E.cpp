//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                     unsigned long long
#define ll                      long long
// #define int                     long long
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



vector<int>v[MX];
int n;
bool add[MX];
bool sub[MX];

void dfs(int cur,int par){
    bool isleaf=true,allminus=true;
    for(auto &child:v[cur]){
        if(child!=par){
            isleaf=false;
            dfs(child,cur);
            if(add[child]){
                allminus=false;
            }
        }
    }
    if(isleaf){
        add[cur]=true;
    }
    else{ 
        if(allminus)
            add[cur]=true;
        else if(cur!=1)
            sub[cur]=true;
    }
}
void solve() {

    cin>>n;
    repe(i,n)
        add[i]=0,sub[i]=0,v[i].clear();

    repe(i,n-1){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }    
    dfs(1,-1);
    int ans=0;
    repe(i,n){
        // cout<<i<<": "<<add[i]<<" "<<sub[i]<<"\n";
        if(add[i])
            ans++;
        else if(sub[i])
            ans--;
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