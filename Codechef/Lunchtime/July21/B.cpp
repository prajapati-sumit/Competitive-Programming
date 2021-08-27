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
const int MX=1e5+5;

 
 
 
int n;
int a[MX];
int b[MX];

vector<int>best(vector<int>x,vector<int>y){

    rep(i,n){
        if(x[i]<y[i])
            return x;
        else if (x[i]>y[i])
            return y;
    }
    return x;

}
vector<int> fn(int ind){
    vector<int>c;
    int ai=0;
    FOR(i,ind,n-1)
        c.pb((a[ai++]+b[i])%n);
    FOR(i,0,ind-1)
        c.pb((a[ai++]+b[i])%n);
    return c;
}
void solve(){
  
    cin>>n;
    vector<int>cand;
    rep(i,n){
        cin>>a[i];
        a[i]%=n;
    }  
    rep(i,n){
        cin>>b[i];
        b[i]%=n;
    }
    int cur_min=INF,res=INF;
    rep(i,n){
        int cur=(a[0]+b[i])%n;
        if(res>cur){
            res=cur;
            cur_min=b[i];
        }

    }
    rep(i,n){
        if(b[i]==cur_min)
            cand.pb(i);
    }
    vector<int>c(n,INF);
    for(auto &el:cand){
        vector<int>tmp=fn(el);
        // for(auto el:tmp)
        //     cout<<el<<" ";
        // cout<<'\n';
        c=best(c,tmp);
        // for(auto &el:c)
        //     cout<<el<<" ";
        // cout<<'\n';
        // cout<<'\n';
    }
    assert(c.size()==n);
    for(auto &el:c)
        cout<<el<<" ";
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