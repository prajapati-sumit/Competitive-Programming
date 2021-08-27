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
const int INF=1e9;
const int MX=1e5+5;

 
vector<int>v[1003];

int a[1003][502]; 
int n;
bool vis[1003];


bool compatible(int i,int j){
    repe(r,n){
        if(a[i][r]==a[j][r])
            return true;
    }
    return false;

}
int dfs(int cur){
    assert(!vis[cur]);
    vis[cur]=1;
    int res=1;
    for(auto &el:v[cur])
        if(!vis[el])
            res+=dfs(el);
    return res;
}
void solve(){

    cin>>n;
    repe(i,2*n)
        v[i].clear();
    repe(i,2*n)
        vis[i]=0;
    repe(i,2*n)
        repe(j,n)
            cin>>a[i][j];

    repe(i,2*n)
        FOR(j,i+1,2*n)
            if(compatible(i,j))
                v[i].pb(j),v[j].pb(i);
    repe(i,2*n){
        cout<<i<<": ";
        for(auto &el:v[i])
            cout<<el<<" ";
        cout<<'\n';
    }
    vector<int>parent(2*n+1,0);
    repe(i,2*n)
        if(!vis[i])
            parent[i]+=dfs(i);
    int cnt=0;
    int res=1;
    repe(i,2*n){
        if(parent[i]>0){
            res=(res*parent[i])%MDL;
            cnt++;
        }
    }
    if(cnt<n){
        cout<<"0\n";
        return;
    }
    cout<<res<<"\n";
    cnt=0;
    repe(i,2*n){
        if(cnt==n)
            break;
        if(parent[i]>0){
            cnt++;
            cout<<v[i][0]<<" ";
        }
    }
    cout<<'\n';

 
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