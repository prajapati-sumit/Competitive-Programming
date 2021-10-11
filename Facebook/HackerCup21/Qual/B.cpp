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
    char a[n][n];
    rep(i,n)
        rep(j,n)
            cin>>a[i][j];

    map<int,set< vector<pii> > >mp;
    // rows
    rep(i,n){
        int ans=0;
        vector<pii>tmp;
        rep(j,n){
            if(a[i][j]=='O'){
                ans=INF;
                break;
            }
            if(a[i][j]=='.'){
                ans++;
                tmp.pb({i,j});
            }
        }
        sort(all(tmp));
        if(ans<INF)
            mp[ans].insert(tmp);
    }

    // columns
    rep(j,n){
        int ans=0;
        vector<pii>tmp;
        rep(i,n){
            if(a[i][j]=='O'){
                ans=INF;
                break;
            }
            if(a[i][j]=='.'){
                ans++;
                tmp.pb({i,j});
            }
        }
        sort(all(tmp));
        if(ans<INF)
            mp[ans].insert(tmp);
    }
    if(mp.empty()){
        cout<<"Impossible\n";
    }
    else{
        auto it=mp.begin();
        cout<<it->ff<<" "<<(it->ss).size()<<'\n';;
    }



}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}