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
const int MX = 2e5 + 5;


int fact[MX];
ll bin_power(ll a,ll b,ll md){
    ll res=1;
    while (b){
        if (b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
}
int ncr(int n,int r){
    if(r>n)
        return 0;
    return (fact[n]*bin_power(fact[n-r],MD-2,MD)%MD)*bin_power(fact[r],MD-2,MD)%MD;

}
void solve() {

    int n,k;
    cin>>n>>k;
    int valid=0;
    for(int n_one=0;n_one<=n;n_one+=2){
        valid=(valid+ncr(n,n_one))%MD;
    }
    if(n&1)
        valid=(valid+1)%MD;
    else
        valid=(valid-1+MD)%MD;
    // cout<<valid<<" ";
    int ans=bin_power(valid,k,MD);
    if(n%2==0){
        int p=1;
        for(int rem=0;rem<k;rem++){
            ans=(ans+p*bin_power(2,(n*(k-rem-1))%(MD-1),MD))%MD;
            p=(p*valid)%MD;
        }
    }

    cout<<ans<<'\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0]=1;
    repe(i,MX-1)
        fact[i]=i*fact[i-1]%MD;
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