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
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 2e5 + 5;


int fact[MX];
int ifact[MX];

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
    return (fact[n]*ifact[n-r]%MDL)*ifact[r]%MDL;

}
void solve() {

    int n;
    cin>>n;
    int a[n+1];
    int f=-1,s=-1;
    repe(i,n){
        cin>>a[i];
        if(a[i]>f)
            s=f,f=a[i];
        else if(a[i]>s)
            s=a[i];
    }
    if(f-s>1){
        cout<<"0\n";
        return;
    }
    if(f==s){
        cout<<fact[n]<<"\n";
        return;
    }
    int k=0;
    repe(i,n)
        k+=(a[i]==s);
    int ans=fact[n];
    ans=(ans+MDL-(ncr(n,k+1)*fact[k]%MDL)*fact[n-k-1]%MDL)%MDL;
    cout<<ans<<"\n";
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    fact[0]=1;
    ifact[0]=1;
    repe(i,MX-1){
        fact[i]=(i*fact[i-1])%MDL;
        ifact[i]=bin_power(fact[i],MDL-2,MDL);

    }
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}