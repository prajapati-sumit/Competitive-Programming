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

 
 
int x=5;
int cnt;
int n,k;
int query(int r){
    assert(cnt<n);
    cnt++;
    cout<<r<<"\n";
    int resp;
    cin>>resp;
    return resp;
    // if(x==r)
    //     return 1;
    // x^=r;
    // return 0;
}
void solve(){
  
    
    cin>>n>>k;
    cnt=0;
    assert(k==2);
    int resp;
    resp=query(0);
    assert(resp!=-1);
    if(resp)
        return;
    rep(i,n-1){
        resp=query(i^(i+1));
        assert(resp!=-1);
        if(resp)
            return;
    }
    assert(false);
  
 
} 
 
 
int32_t main() {

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
        // cerr<<"Job Done\n";
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}