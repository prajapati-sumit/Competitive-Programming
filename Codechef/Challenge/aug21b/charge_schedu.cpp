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
const int MX =3e5 + 5;



int A[MX],T[MX];
struct Node{
    int id,l,r;
};

void solve() {

    int n;
    cin>>n;
    rep(i,n)
        cin>>A[i];
    rep(i,n)
        cin>>T[i];

    int order[n];
    rep(i,n)
        order[i]=i;
    sort(order,order+n,[](auto p,auto q){
        if(T[p]==T[q])
            return A[p]<A[q];
        return T[p]<T[q];
    });
    int cur_time=0;
    vector<Node>v;
    rep(i,n){
        int cur=order[i];
        // cout<<A[cur]<<" "<<T[cur]<<" "<<cur_time<<'\n';
        if(A[cur]+cur_time>T[cur])
            continue;
        v.pb({cur+1,cur_time,cur_time+A[cur]});
        cur_time+=A[cur];

    }
    cout<<SZ(v)<<'\n';
    for(auto &el:v)
        cout<<el.id<<" "<<el.l<<" "<<el.r<<'\n';

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