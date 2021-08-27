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
#define SZ(x)               ((int)x.size())
#define set_bits            __builtin_popcountll
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;





void solve() {

    int n;
    cin>>n;
    int a[n+1];
    bool ok=false;
    repe(i,n){
        cin>>a[i];
        if(a[i]==1)
            ok=true;
    }
    
    if(n==1){
        if(a[1]==0)
            cout<<"1 2\n";
        else
            cout<<"2 1\n";
        return;
    }
    a[0]=0;
    if(a[1]==1){
        cout<<(n+1)<<" ";
        repe(i,n)
            cout<<i<<" ";
        cout<<'\n';
        return;
    }
    else if(a[n]==0){
        repe(i,n)
            cout<<i<<" ";
        cout<<(n+1)<<" ";
        cout<<'\n';
        return;
    }
    if(!ok){
        cout<<"-1\n";
        return;
    }
    vector<int>v;
    FOR(i,1,n-1){
        if(a[i]==0 && a[i+1]==1){
           
            v.pb(i);
            v.pb(n+1);
            FOR(j,i+1,n)
                v.pb(j);
            break;
        }
        else 
            v.pb(i);

    }
    assert(SZ(v)==n+1);
    for(auto &el:v)
        cout<<el<<" ";
    cout<<'\n';


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}