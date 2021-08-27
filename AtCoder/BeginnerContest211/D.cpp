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
const int MX=2e5+5;

vector<pii> G[MX];
int n,m;
int dist[MX];
int ans[MX];
// #warning fill the distance array with infinity
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
                ans[x.first]=ans[u];
                pq.push(pii(dist[x.first],x.first));
            }
            else if(dist[u]+x.second==dist[x.first]){
                ans[x.first]=(ans[x.first]+ans[u])%MD;
            }
        }
 
 
    }
 
} 
 
 
 
 
void solve(){
  
    cin>>n>>m;
    repe(i,n)
        dist[i]=INF;
    repe(i,m){
        int x,y;
        cin>>x>>y;
        G[x].pb({y,1});
        G[y].pb({x,1});
    }
    ans[1]=1;
    dijkstra(1);
    // repe(i,n)
    //     cout<<ans[i]<<" \n"[i==n];
    cout<<ans[n]<<'\n';
  
 
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