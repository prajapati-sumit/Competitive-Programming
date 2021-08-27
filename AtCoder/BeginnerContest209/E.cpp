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

 
 
int n;
vector<string>v(MX);
bool vis[MX];
vector<int>dp(MX,-1);
map<string,vector<int>>pref;
int best(int x,int y){
    if(x==0)
        return y;
    if(x==1)
        return x;
    if(x==2 && y==1)
        return y;
    return x;
}
int dfs(int cur){
    // cerr<<cur<<" "<<par<<'\n';
    if(dp[cur]!=-1)
        return dp[cur];
    vis[cur]=1;
    int sz=v[cur].length();
    string tmp;
    repe(i,3)
        tmp.pb(v[cur][sz-i]);
    reverse(all(tmp));
    int res=0;
    for(auto &el:pref[tmp]){
        if(dp[el]!=-1)
            res=best(res,2);
        else{
            int here=dfs(el);
            if(here!=2)
                here^=1;
            res=best(res,here);
        }
    
        
    }
    // vis[cur]=0;
    // cerr<<cur<<" "<<res<<'\n';
    return dp[cur]=res;

}
void solve(){
  
    cin>>n;
    repe(i,n){
        cin>>v[i];
        pref[v[i].substr(0,3)].pb(i);
    }
    repe(i,n){
        if(dp[i]==-1){
            dfs(i);
        }
    }
    repe(i,n){
        if(dp[i]==2)
            cout<<"Draw\n";
        else if(dp[i]==0)
            cout<<"Takahashi\n";
        else
            cout<<"Aoki\n";
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