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



int n;
class DSU{

public:
    vector<int>parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
            parent[i]=-1;
    }
    int find_set(int x){
        return parent[x]<0?x:parent[x]=find_set(parent[x]);
    } 
    void merge(int a,int b){
        int pa=find_set(a);
        int pb=find_set(b);
        if(pa!=pb){
            if(parent[pa]<parent[pb]){
                parent[pa]+=parent[pb];
                parent[pb]=pa;
            }
            else{
                parent[pb]+=parent[pa];
                parent[pa]=pb;
            }
        }
        
        
    } 
};
struct Edge{
    int a,b,w;
};
void solve() {

    cin>>n;
    DSU D(n);
    Edge E[n-1];
    rep(i,n-1)
        cin>>E[i].a>>E[i].b>>E[i].w;

    int ans=0;
    sort(E,E+n-1,[&](auto p,auto q){
        return p.w<q.w || (p.w==q.w && p.a<q.a);
    });
    rep(i,n-1){
        int a=E[i].a,b=E[i].b,w=E[i].w;
        a=D.find_set(a);
        b=D.find_set(b);
        // cout<<a<<" "<<b<<'\n';
        ans+=w*(D.parent[a]*D.parent[b]);
        D.merge(E[i].a,E[i].b);
    }
    cout<<ans<<'\n';


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