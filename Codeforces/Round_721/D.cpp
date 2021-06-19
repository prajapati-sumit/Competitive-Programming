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
#define rep(i,n)            for(ll i=0;i<n;i++)
#define repe(i,n)           for(ll i=1;i<=n;i++)
#define FOR(i,a,b)          for(ll i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  200'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?

ll n;
vector<ll> v[MX];
ll ans[MX];
ll parent[MX];
ll subtree[MX];
bool vis[MX];
ll dfs(ll cur,ll par){
    int res = 1;
    parent[cur] = par;
    trav(el, v[cur]) {
        if (el != par)
            res += dfs(el, cur);
    }
    return subtree[cur] = res;
}
void solve() {

    //FAILED :(
    cin>>n;
    ll x,y;
    rep(i,n){
        v[i].clear();
        vis[i]=0;
        ans[i]=0;
    }

    repe(i,n-1){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(0,-1);
    ll l=0,r=0;
    ll P=0;
    trav(el,v[0])
        P += (subtree[el] * (subtree[el] - 1)) / 2;
    ans[0]=P;
    P = (n * (n - 1)) / 2 - P;
    vis[0]=1;
    for(ll i=1;i<n;i++){
        ll U=i;
        if(vis[i])
            continue;
        ll sub=0;
        while(!vis[U]){
            vis[U]=true;
            sub=subtree[U];
            U=parent[U];

        }
        ll here;
        // cout<<i<<" "<<l<<" "<<r<<'\n';
        // cout<<subtree[l]<<" "<<subtree[r]<<'\n';
        if(U==l){
            here=subtree[i]*(subtree[r]-sub);
            ans[i]=P-here;
            P=here;
            l=i;
        }
        else if(U==r){
            here=(subtree[l]-sub)*subtree[i];
            ans[i]=P-here;
            P=here;
            r=i;
        }
        else{
            ans[i]=P;
            break;
        }
    }
    ll cnt=0;
    rep(i,n)
        cnt+=(v[i].size()==1);
    ans[n]=(cnt==2);
    FOR(i,0,n)
        cout<<ans[i]<<" \n"[i==n];






}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    ll t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }

    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}