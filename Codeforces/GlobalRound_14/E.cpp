// AUTHOR: Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  100'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?

ll fact[MX];

// ((2*n)!/(n!)^2)

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

ll inv(ll x,ll md){
    return bin_power(x,md-2,md);
}

void solve(){

    ll n,M;
    cin>>n>>M;
    n--;

    ll a[n+1];
    a[0]=1;
    a[1]=2;
    for(ll i=2;i<=n;i++){
        a[i] = 2*(a[i-1] + (i-1)*a[i-2]);
        // cout<<a[i]<<" ";
        a[i]%=M; 
    }
    cout<<a[n]<<'\n';

    // n--;
    // fact[0]=1;
    // repe(i,MX-1)
    // fact[i]=(i*fact[i-1])%M;
    // ll ans=fact[2*n];
    // ans=(((ans * inv(fact[n],M)) % M) * inv(fact[n],M) ) % M;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;


    solve();

    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}