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

 
 
 
 
void solve(){
  
    int n;
    cin>>n;
    vector<pair<char,int>>v(n+1);
    repe(i,n){
        cin>>v[i].ff;
        if(v[i].ff=='+')
            cin>>v[i].ss;
        else
            v[i].ss=0;
    }
    int ans=0,two=n-1;
    repe(i,n){
        if(v[i].ff=='-')
            continue;
        for(int j=1;j<=n;j++){  
            int minus=0,smaller=0;
            for(int k=1;k<=j;k++){
                minus+=(v[k].ff=='-');
                smaller+=(v[k].ff=='+' && v[k].ss<=v[i].ss);
            }
            if(j>=i && (minus>smaller)){
                    two-=(minus-smaller);
            }
        }
        cout<<v[i].ss<<" "<<two<<'\n';
        ans+=v[i].ss*(1<<two);
    }
    cout<<ans<<'\n';
  
 
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