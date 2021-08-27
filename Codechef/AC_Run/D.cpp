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
const int MX=3e5+5;

vector<pii> G[2*MX];
int n;
int dist[2*MX];
void dijkstra(int start)
{
    
 
    dist[start]=0;
    priority_queue< pii,vector<pii>,greater<pii> > pq;
    pq.push(pii(0,start));
    while(!pq.empty())
    {
        pii p=pq.top();
        pq.pop();
        int d=p.first;
        int u=p.second;
        if(d>dist[u])
            continue;
 
 
        for(auto x: G[u])
        {
            if(dist[u]+x.second<dist[x.first])
            {
                dist[x.first]=dist[u]+x.second;
                pq.push(pii(dist[x.first],x.first));
            }
        }
 
 
    }
 
} 
 
 
 
void solve(){
  
    cin>>n;
    int x,y,w;
    repe(i,2*MX-1)
        dist[i]=INF;
    repe(i,n-1){
        cin>>x>>y>>w;
        G[x].pb({y,w});
        G[n+x].pb({n+y,2*w});
    }
    repe(i,n){
        cin>>w;
        G[i].pb({n+i,w});
        G[n+i].pb({i,w});
    }
    dijkstra(n+1);
    int q;
    cin>>q;
    repe(i,q)
    {
        cin>>x>>y;
        assert(y==1);
        cout<<dist[x+n]<<'\n';
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