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
#define SZ(x)               ((int)x.size())
#define set_bits            __builtin_popcountll
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;

class DSU{

public:
    vector<int>parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
            parent[i]=i;
    }
    int find_set(int x){
        return parent[x]==x?x:parent[x]=find_set(parent[x]);
    } 
    void union_set(int a,int b){
        int pa=find_set(a);
        int pb=find_set(b);
        if(pa!=pb)
            parent[pb]=pa;
        
        
    } 
};



void solve() {

    int n,m1,m2;
    cin>>n>>m1>>m2;
    DSU D1(n),D2(n);
    repe(i,m1){
        int x,y;
        cin>>x>>y;
        D1.union_set(x,y);
    }
    repe(i,m2){
        int x,y;
        cin>>x>>y;
        D2.union_set(x,y);
    }
    int ans=0;
    vector<pii>v;
    repe(i,n){
        FOR(j,i+1,n){
            int x1=D1.find_set(i),y1=D1.find_set(j);
            int x2=D2.find_set(i),y2=D2.find_set(j);
            if(x1!=y1 && x2!=y2){
                ans++;
                v.pb({i,j});
                D1.union_set(i,j);
                D2.union_set(i,j);
            }
        }
    }
    cout<<ans<<"\n";
    for(auto &el:v)
        cout<<el.ff<<" "<<el.ss<<'\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}