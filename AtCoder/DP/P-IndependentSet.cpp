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

 
int n;
vector<int>v[MX];
int dp[MX][2]; 
 //0:Black ,1:White 

int fn(int cur,int par,int col){

    if(dp[cur][col]!=-1)
        return dp[cur][col];
    if(v[cur].size()==1 && v[cur][0]==par)
        return dp[cur][col]=1;
    int res=1;
    for(auto &el:v[cur]){
        if(el==par)
            continue;
        if(col)
            res=(res*(fn(el,cur,col)+fn(el,cur,col^1)))%MD;
        else
            res=(res*fn(el,cur,col^1))%MD;
    }
    // cout<<cur<<" "<<v[cur].size()<<" "<<par<<" "<<col<<"-> "<<res<<'\n';
    return dp[cur][col]=res;
}

void solve(){
  
    cin>>n;
    repe(i,n-1){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    if(n==1){
        cout<<"2\n";
        return;
    }
    memset(dp,-1,sizeof(dp));
    int ans=(fn(1,-1,0)+fn(1,-1,1))%MD;
    cout<<ans<<'\n';
    // repe(i,n)
    //     cout<<i<<"-> "<<dp[i][0]<<" "<<dp[i][1]<<'\n';
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