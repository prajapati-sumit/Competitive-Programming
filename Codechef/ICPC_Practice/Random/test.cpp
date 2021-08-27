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
const int INF=1e9+2;
const int MX=1e5+5;

 
 
int n;
int a[MX],cost[MX]; 
bool vis[MX];


void solve(){

    cin>>n;
    repe(i,n)
        vis[i]=0;

    repe(i,n)
        cin>>a[i];
    repe(i,n)
        cin>>cost[i];

    int nG=1;
    vector<pii>v;

    repe(i,n){
        if(!vis[i]){
            int cur=i;
            vis[cur]=1;
            
            v.pb({cost[cur],nG});
            cur=a[cur];
            while(cur!=i){
                vis[cur]=1;

                v.pb({cost[cur],nG});
                cur=a[cur];
            }
            nG++;
        }
    }

    nG--;
    sort(all(v));
    for(auto &el:v)
        cout<<el.ff<<" "<<el.ss<<'\n';
    map<pii,int>mp;
    assert(v.size()==n);
    rep(i,n-1){
        int x=v[i].ss,y=v[i+1].ss;
        if(x==y)
            continue;
        if(x>y)
            swap(x,y);
        int dif=abs(v[i].ff-v[i+1].ff)+1;
        int cur=mp[{x,y}];
        mp[{x,y}]=(cur==0?dif:min(dif,cur));
    }
    int ans=0;
    vector<int>res;
    for(auto& el:mp){
        res.pb(el.ss-1);
    }
    assert(res.size()>=(nG-1));
    sort(all(res));
    rep(i,nG-1){
        ans+=res[i];
    }
    
    cout<<ans<<'\n';
 
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