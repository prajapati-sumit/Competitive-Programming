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
    int a[n+1],b[n+1];
    repe(i,n)   
        cin>>a[i];
    repe(i,n)
        cin>>b[i];
    int df=0;
    vector<pii> pos;
    vector<pii> neg;
    repe(i,n){
        df+=(a[i]-b[i]);
        if(a[i]-b[i]>0)
            pos.pb({a[i]-b[i],i});
        else if(a[i]-b[i]<0)
            neg.pb({a[i]-b[i],i});
    }
    if(df!=0){
        cout<<"-1\n";
        return;

    }
    int szp=pos.size(),szn=neg.size(),i=0,j=0;
    vector<pii>res;
    while(i<szp && j<szn){
        // cerr<<i<<" "<<j<<" "<<pos[i].ff<<" "<<neg[j].ss<<"\n";
        res.pb({pos[i].ss,neg[j].ss});

        pos[i].ff--;
        if(pos[i].ff==0)
            i++;
        
        neg[j].ff++;
        if(neg[j].ff==0)
            j++;
    }
    int sz=(int)res.size();
    cout<<sz<<'\n';
    if(sz==0)
        return;
    for(auto &el:res)
        cout<<el.ff<<" "<<el.ss<<'\n';


 
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