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
const int INF=1e15+2;
const int MX=1e5+5;

 

bool canform(int x,int m){
    if(m==0)
        return 1;
    if(x==0)
        return m==0;
    if(x==m)
        return 1;
    return (m<(x+1)/2);
}
 
void solve(){
  
    int n;
    cin>>n;
    int a[n+1];
    int mn=INF; 
    repe(i,n)
        cin>>a[i],mn=min(a[i],mn);
    int cntmin=0;
    repe(i,n)    
        cntmin+=(a[i]==mn);
    // cout<<cntmin<<'\n';
    bool ok=true;
    repe(i,n){
        if(a[i]==mn)
            continue;
        if(!canform(a[i],mn)){
            ok=false;
            break;
        }
    }  
    if(ok){
        cout<<(n-cntmin)<<'\n';
    }
    else{
        cout<<n<<'\n';
    }
  
 
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