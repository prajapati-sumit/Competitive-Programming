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
const int INF=1e16;
const int MX=1e5+5;

 
 
 
 
void solve(){
  
    int n;
    cin>>n;
    int a[n+1];
    repe(i,n)
        cin>>a[i];
    if(n==1){
        cout<<"1\n";
        return;
    }
    sort(a+1,a+n+1);
    int ans=INF;
    vector<pii> pref(n+1),suff(n+2);
    pref[0]=suff[n+1]={0,0};
    pref[1]={a[1],a[1]};
    suff[n]={a[n],a[n]};
    FOR(i,2,n){
        pref[i].ff=pref[i-1].ff+a[i];
        pref[i].ss=__gcd(pref[i-1].ss,a[i]);
    }
    for(int i=n-1;i>=1;i--){
        suff[i].ff=suff[i+1].ff+a[i];
        suff[i].ss=__gcd(suff[i+1].ss,a[i]);
    }
    repe(i,n){
        int sum=pref[i-1].ff+suff[i+1].ff;
        int g=__gcd(pref[i-1].ss,suff[i+1].ss);
        ans=min(ans,1+sum/g);
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