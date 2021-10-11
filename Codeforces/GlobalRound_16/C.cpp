//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                     unsigned long long
#define ll                      long long
#define int                     long long
#define pii                     pair<int, int>
#define pll                     pair<ll, ll>
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define SZ(x)                   ((int)x.size())
#define set_bits                __builtin_popcountll
#define all(a)                  a.begin(),a.end()
#define trav(x,v)               for(auto &x:v)
#define rep(i,n)                for(int i=0;i<n;i++)
#define repe(i,n)               for(int i=1;i<=n;i++)
#define FOR(i,a,b)              for(int i=a;i<=b;i++)
#define curtime                 chrono::high_resolution_clock::now()
#define timedif(start,end)      chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define myshuffle(a,n)          FOR(i,1,n-1) swap(a[i], a[rand() % (i + 1)])
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;




char a[2][MX];



void solve() {

    
    int n;
    cin>>n;
    rep(i,n)
        cin>>a[0][i];
    rep(i,n)
        cin>>a[1][i];
    int ans=0;
    int i=0;
    bool zer=0,one=0;
    while(true){
        if(i>=n){
            break;
        }
        zer|=(a[0][i]=='0' || a[1][i]=='0');
        one|=(a[0][i]=='1' || a[1][i]=='1');
        // cout<<i<<" "<<zer<<" "<<one<<"\n";
        if(zer && one){
            ans+=2;
            i++;
            zer=0;
            one=0;

        }
        else if(zer && !one){
            if(i==n-1){
                ans++;
                i++;
            }
            else if(a[0][i+1]=='1' && a[1][i+1]=='1'){
                ans+=2;
                i+=2;
            }
            else{
                ans++;
                i++;
            }
            zer=0;
            one=0;
        }
        else if(!zer && one){
            i++;
        }
        else
            assert(0);
        

    }
    cout<<ans<<"\n";

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