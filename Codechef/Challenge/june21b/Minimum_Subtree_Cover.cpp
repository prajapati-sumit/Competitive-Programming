//~ author      : Sumit Prajapati
//~ mail ID     : sumitprajapati821@gmail.com
//~ codefoces   : sumitprajapati81, codechef: sumit141
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
// #define int                 long long
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
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0, 0xFFFFFFFFFFFFFFFF);

const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;


int n, k;
vector<int>v[MX];
vector<int>path;

pii dfs(int cur,int par){

    pii res={0,cur};
    for(int &child:v[cur]){
        if(child==par)
            continue;
        pii temp=dfs(child,cur);
        if(temp.ff>res.ff)
            res=temp;
    }
    res.ff+=1;
    // cout<<cur<<" ->"<<res.ff<<" "<<res.ss<<'\n';
    return res;
}
bool fillpath(int cur,int par,int dest){

    path.pb(cur);
    if(cur==dest)
        return true;
    bool flag=false;
    for(int &el:v[cur]){
        if(el==par)
            continue;
        flag|=fillpath(el,cur,dest);
    }
    if(!flag){
        path.pop_back();
        return false;
    }
    return true;

}
int active;
vector<int> dfs2(int cur,int par,int f1,int f2){

    vector<int>res;
    int max_here=0;
    for(int &child:v[cur]){
        if(child==par || child==f1 || child==f2)
            continue;
        for(int &el:dfs2(child,cur,-1,-1)){
            max_here=max(max_here,el);
            res.pb(el);
        }
    }
    if(cur==active)
        return res;
    if(res.empty())
        res.pb(1);
    else{
        for(int i=0;i<res.size();i++){
            if(res[i]==max_here){
                res[i]++;
                break;
            }
        }
    }
    return res;

}
void solve() {

    cin >> n >> k;
    
    int x, y;
    //---------------------------
    repe(i,n)
        v[i].clear();
    path.clear();
    //---------------------------

    repe(i, n - 1)  cin >> x >> y, v[x].pb(y), v[y].pb(x);
    if(k==1){
        cout<<"1\n";
        return;
    }
    pii f_end=dfs(1,-1);
    pii s_end=dfs(f_end.ss,-1);
    int till_now=s_end.ff,ans=0;
    // cout<<till_now<<'\n';
    if(till_now>=k){
        cout<<"2\n";
        return;
    }
    ans=2;
    fillpath(f_end.ss,-1,s_end.ss);

    // for(int el:path)
    //     cout<<el<<" ";
    // cout<<'\n';
    int d=path.size();
    vector<int> here,temp;
    for(int i=1;i<d-1;i++){
        active=path[i];
        if(v[path[i]].size()<=2)
            continue;
        // cout<<path[i]<<" ->";
        for(int &el:dfs2(path[i],-1,path[i-1],path[i+1])){
            here.pb(el);
            // cout<<el<<" ";
        }
        // cout<<'\n';
    }
    sort(all(here),[&](int P,int Q){return P>Q;});
    // for(auto &el:here)
    //     cout<<el<<" ";
    // cout<<'\n';
    for(int &el:here){
        ans++;
        till_now+=el;
        if(till_now>=k)
            break;
    }
    cout<<ans<<'\n';
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}