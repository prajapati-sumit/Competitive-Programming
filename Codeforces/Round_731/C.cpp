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
  
    int k,n,m;
    cin>>k>>n>>m;
    int lines=k;
    int a[n+1],b[m+1];
    repe(i,n)
        cin>>a[i];
    repe(i,m)
        cin>>b[i];    
    int i=1,j=1;
    vector<int>v;
    while(i<=n && j<=m){
        if(a[i]==0){
            v.pb(a[i]);
            i++;
            lines++;
        }
        else if(b[j]==0){
            v.pb(b[j]);
            j++;
            lines++;
        }
        else if(a[i]<b[j]){
            if(lines>=a[i])
                v.pb(a[i++]);
            else{
                cout<<"-1\n";
                return;
            }
        }
        else{
            if(lines>=b[j]){
                v.pb(b[j++]);
            }
            else{
                cout<<"-1\n";
                return;
            }
        }
    } 
    while(i<=n){
        if(a[i]==0){
            v.pb(a[i]);
            i++;
            lines++;
        }
        else if(lines>=a[i])
            v.pb(a[i++]);
        else{
            cout<<"-1\n";
            return;
        }
    }  
    while(j<=m){
        if(b[j]==0){
            v.pb(b[j]);
            j++;
            lines++;
        }
        else if(lines>=b[j]){
            v.pb(b[j++]);
        }
        else{
            cout<<"-1\n";
            return;
        }

    }
    for(auto &el:v)
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