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
const int MX=1e5+5;

 
 
 
struct inter{
    long double l,r;
}a[2001];
bool valid(int i,int j){
    return !(a[i].l>a[j].r || a[i].r<a[j].l);
}
long double dx=0.1;
void solve(){
  
    int n;
    cin>>n; 

  
    int ans=0;
    int t;
    repe(i,n){
        cin>>t>>a[i].l>>a[i].r;
        if(t==2)
            a[i].r-=dx;
        else if(t==3)a[i].l+=dx;
        else if(t==4)a[i].l+=dx,a[i].r-=dx;
    }
    repe(i,n){
        FOR(j,i+1,n){
            if(valid(i,j) || valid(j,i)){
                // cout<<i<<" "<<j<<'\n';
                ans++;
            }
        }
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
