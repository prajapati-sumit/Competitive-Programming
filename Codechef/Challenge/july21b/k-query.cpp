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
const int MAXLOG=19;
const int MX=1e5+2;
int LCA[MX][MAXLOG];
int level[MX];
vector<int>v[MX];
int n;

void dfs(int node,int par,int lev){
    LCA[node][0]=par;
    level[node]=lev;
    for(auto x:v[node])
        if(x!=par)
            dfs(x,node,lev+1);
}
void init(){
    repe(i,n)
        rep(j,MAXLOG)
            LCA[i][j]=-1;

    dfs(1,-1,1);
    for(int i=1;i<MAXLOG;i++){
        for(int j=1;j<=n;j++){
            if(LCA[j][i-1]!=-1){
                int par=LCA[j][i-1];
                LCA[j][i]=LCA[par][i-1];
            }
        }

    }
}
int getLCA(int a, int b){
    
    if(a==-1)
        return b;
    if(level[a]>level[b])
        swap(a,b);
    int d=level[b]-level[a];
    while(d>0){
        int jump=log2(d);
        b=LCA[b][jump];
        d-=(1LL<<jump);
    }
    if(a==b)
        return a;
    for(int i=MAXLOG-1;i>=0;i--){
        if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i]))
            a=LCA[a][i],b=LCA[b][i];
    }
    return LCA[a][0];
}

 
 
 
 
void solve(){
  
    cin>>n;

    repe(i,n)
        v[i].clear();    
    repe(i,n-1){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    init();

    int q;
    cin>>q;
    int k;
    repe(i,q){
        cin>>k;
        vector<int>b(k);
        int low=1,high=-1;
        rep(i,k){
            cin>>b[i];
            high=getLCA(high,b[i]);
            if(level[b[i]]>level[low])
                low=b[i];
        }
        vector<int>other,me;
        rep(i,k){
            int L=getLCA(low,b[i]);
            if(L==high){
                other.pb(b[i]);
            }
            else{
                me.pb(b[i]);
            }
        }
        int sz=other.size();
        bool ok=true;
        sort(all(other),[&](auto p,auto q){
            return level[p]<level[q];
        });
        rep(i,sz-1){
            int L=getLCA(other[i],other[i+1]);
            if(L==other[i] || L==other[i+1]);
            else{
                ok=false;
                break;
            }
        }
        if(!ok){
            cout<<"NO\n";
            continue;
        }
        sort(all(me),[&](auto p,auto q){
            return level[p]<level[q];
        });
        int sz2=me.size();
        rep(i,sz2-1){
            int L=getLCA(me[i],me[i+1]);
            if(L==me[i] || L==me[i+1]);
            else{
                ok=false;
                break;
            }
        }
        
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";


    }

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