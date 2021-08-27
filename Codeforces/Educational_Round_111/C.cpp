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

 
 
bool isvalid(int a,int b,int c){
    // cout<<a<<" "<<b<<" "<<c<<'\n';
    return !((a<=b && b<=c) || (a>=b && b>=c));
}
 
void solve(){
  
    int n;
    cin>>n;
    int a[n+1];
    int ans=2*n-1;
    repe(i,n)
        cin>>a[i]; 
    // 3-size subarrays 

    for(int j=1;j+2<=n;j++){
        if(isvalid(a[j],a[j+1],a[j+2])){
            ans++;
        }
    }
    
    // 4-size subarrays
    for(int j=1;j+3<=n;j++){
        if(isvalid(a[j],a[j+1],a[j+2]) && 
            isvalid(a[j+1],a[j+2],a[j+3]) && 
            isvalid(a[j],a[j+2],a[j+3]) &&
            isvalid(a[j],a[j+1],a[j+3])) 
            ans++;  

        
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