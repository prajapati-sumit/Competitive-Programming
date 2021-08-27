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
    string s;
    cin>>s;

    bool ok=true;
    rep(i,n)
        if(s[i]=='0'){
            ok=false;
            break;
        }

    if(ok){
        if(n&1){
            cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<'\n';
        }
        else{
            cout<<1<<" "<<n<<" "<<1<<" "<<n/2<<'\n';
        }
        return;
    }

    // front
    for(int i=n/2;i<n;i++){
        if(s[i]=='0'){
            cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<"\n";
            return;
        }
    }
    reverse(all(s));
    
    //behind
    for(int i=n/2;i<n;i++){
        if(s[i]=='0'){
            cout<<n-i<<" "<<n<<" "<<n-i+1<<" "<<n<<"\n";
            return;
        }
    }
    // cout<<s<<'\n';
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