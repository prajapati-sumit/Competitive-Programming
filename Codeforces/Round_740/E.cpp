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



vector<int>res;
void do_op(vector<int>& a,int idx){
    assert(idx%2);
    res.pb(idx);
    repe(i,idx/2)
        swap(a[i],a[idx-i+1]);


}
void fn(vector<int>& a,int n){
    if(n==1){
        return;
    }
    int mx,smx;
    repe(i,n){
        if(a[i]==n)
            mx=i;
        if(a[i]==n-1)
            smx=i;
    }
    if(smx!=n-1 || mx!=n){
        do_op(a,mx);
        repe(i,n){
            if(a[i]==n-1)
                smx=i;
        }
        do_op(a,smx-1);
        do_op(a,smx+1);
        do_op(a,3);
        do_op(a,n);
    }
    fn(a,n-2);
}
void solve() {

    int n;
    cin>>n;
    vector<int>a(n+1);
    a[0]=0;
    res.clear();
    bool ok=true;
    repe(i,n){
        cin>>a[i];
        if(a[i]%2!=i%2)
            ok=false;
        
    }
    if(!ok){
        cout<<"-1\n";
        return;
    }
    fn(a,n);
    assert(SZ(res)<=5*n/2);
    cout<<SZ(res)<<"\n";
    assert(is_sorted(all(a)));
    for(auto &el:res)
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