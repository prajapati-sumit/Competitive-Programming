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



int max_here[MX];


void solve() {

    int n;
    cin>>n;
    vector<int>v[n+1];

    repe(i,n){
        max_here[i]=0;
        int ki;
        cin>>ki;
        int cur=0,extra=0;
        repe(j,ki){
            int x;
            cin>>x;
            v[i].pb(x);
            max_here[i]=max(max_here[i],x-extra+1);
            extra++;
        }
    }
    // repe(i,n)
    //     cout<<max_here[i]<<" \n"[i==n];
    int order[n+1];
    repe(i,n)
        order[i]=i;
    sort(order+1,order+n+1,[](auto p,auto q){
        return max_here[p]<max_here[q];
    });
    int needed=0,extra=0;
    repe(i,n){
        int cur=order[i];
        for(auto &el:v[cur]){
            needed=max(needed,el-extra+1);
            extra++;
        }
    }
    cout<<needed<<'\n';


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