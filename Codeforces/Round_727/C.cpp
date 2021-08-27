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
const int MX=2e5+5;

 
int a[MX];
int n,k,x;

vector<int>req;
int fn(int sm,int lar){

    int ans=(lar-sm-1)/x;
    return max(0LL,ans);

} 
void solve(){
  
    // x=4;
    // cout<<fn(4,20)<<'\n';
    // cout<<fn(7,15)<<'\n';
    // cout<<fn(53,56)<<'\n';
    // return;
    cin>>n>>k>>x;           
    repe(i,n)
        cin>>a[i];
    sort(a+1,a+n+1);
    FOR(i,2,n){
        int temp=fn(a[i-1],a[i]);
        if(temp!=0)
            req.pb(temp);
    }
    sort(all(req));
    int part=req.size()+1;
    int cur=0;
    for(auto &el:req){
        if(el>k)
            break;
        k-=el;
        part--;
    }
    cout<<part;

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