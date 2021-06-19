// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long           
#define int                  long long           
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
#define MX                  200'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
int x[MX];
int y[MX]; 
bool cmp1(int a,int b){
    return x[a]==x[b]?y[a]<y[b]:x[a]<x[b];
}
bool cmp2(int a,int b){
    return y[a]==y[b]?x[a]<x[b]:y[a]<y[b];
}
void solve(){
  
    int n;
    cin>>n;
    
    rep(i,n){
        cin>>x[i]>>y[i];
    }
    int xs[n];
    int ys[n];
    rep(i,n)
        xs[i]=ys[i]=i;
    sort(xs,xs+n,cmp1);  
    sort(ys,ys+n,cmp2);  
    // trav(el,xs)
    //     cout<<el<<" ";
    // cout<<'\n';
    // trav(el,ys)
    //     cout<<el<<" ";
    // cout<<'\n';
    int res=0;
    if(!(xs[0]==ys[0] && xs[n-1]==ys[n-1])){
        int op1=abs(x[xs[0]]-x[xs[n-1]]);
        int op2=abs(y[ys[0]]-y[ys[n-1]]);
        res=min(op1,op2);
    }
    
    int op1=max(abs(x[xs[1]]-x[xs[0]]),abs(x[xs[1]]-x[xs[n-1]]));
    int op2=max(abs(x[xs[n-2]]-x[xs[0]]),abs(x[xs[n-2]]-x[xs[n-1]]));
    int op3=max(abs(y[ys[1]]-y[ys[0]]),abs(y[ys[1]]-y[ys[n-1]]));
    int op4=max(abs(y[ys[n-2]]-y[ys[0]]),abs(y[ys[n-2]]-y[ys[n-1]]));
    res=max(res,max({op1,op2,op3,op4}));
    
    cout<<res;
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    // cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}