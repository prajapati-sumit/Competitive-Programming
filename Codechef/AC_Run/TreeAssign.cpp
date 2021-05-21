// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  100'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
int n,x;
vector<int> v[MX];
int branching[MX];

int dfs1(int node,int par){

    int here_branch=0;
    for(auto child:v[node]){
        if(child!=par)
            here_branch+=dfs1(child,node);
    }
    if(here_branch==0)
        here_branch++;
    branching[node]=here_branch-1;
    return here_branch;
}
int dfs2(int node,int par,int val){
    int res=val;
    int i=1;
    for(auto child:v[node]){
        if(child!=par){
            res+=dfs2(child,node,i*val);
            i++;
        }
    }
    return res;
}
void solve(){
  
    cin>>n>>x;
    rep(i,n+1)
        v[i].clear();
    rep(i,n+1)
        branching[i]=0;
    int p,q;
    repe(i,n-1)
        cin>>p>>q,v[p].pb(q),v[q].pb(p);
    dfs1(1,-1);
    repe(i,n){
        sort(all(v[i]),[&](int c,int d){return branching[c]>=branching[d];});
    }
    int ans=dfs2(1,-1,x);
    cout<<ans<<'\n';
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}