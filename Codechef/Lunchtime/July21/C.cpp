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

 
 
 
 
void solve(){
  
    int n,k,s;
    cin>>n>>k>>s;
    int a[n+1];
    a[0]=0;
    repe(i,n)
        cin>>a[i],a[i]+=a[i-1];           
    int go[n+1],ans[n+1];
    repe(i,n){
        // cout<<i<<" "<<s+a[i-1]<<'\n';
        go[i]=upper_bound(a+1,a+n+1,s+a[i-1])-a,ans[i]=i;
    }


    // repe(i,n)
    //     cout<<go[i]<<" \n"[i==n];
    // return;
    while(k){

        if(k&1){
            repe(i,n){
                if(ans[i]<=n)
                    ans[i]=go[ans[i]];
            }
        }
        repe(i,n)
            if(go[i]<=n)
                go[i]=go[go[i]];
        k>>=1;
    }
    int res=0;
    repe(i,n)
        res=max(res,ans[i]-i);
    cout<<res<<'\n';



 
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