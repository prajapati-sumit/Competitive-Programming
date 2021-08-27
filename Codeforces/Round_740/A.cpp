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
    repe(i,n)
        cin>>a[i];
    bool ok2=true;
    repe(i,n-1)
        if(a[i]>a[i+1]){
            ok2=false;
            break;
        }

    // repe(i,n)
    //     cout<<a[i]<<" \n"[i==n];
    if(ok2){
        cout<<0<<"\n";
        return;
    }

    repe(i,n){
        if(i&1){
            for(int i=1;i<=n-2;i+=2)
                if(a[i]>a[i+1])
                    swap(a[i],a[i+1]);
        }else{
            for(int i=2;i<=n-1;i+=2)
                if(a[i]>a[i+1])
                    swap(a[i],a[i+1]);
        }
        bool ok=true;
        repe(i,n-1)
            if(a[i]>a[i+1]){
                ok=false;
                break;
            }

        if(ok){
            cout<<i<<"\n";
            return;
        }
    }       
    assert(0);

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