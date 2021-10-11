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





void solve(int s,int n) {

    if(n==0)
        return;
    vector<int>v;
    int tmp=s,pw=1;
    while(tmp>0){
        int h=(tmp%10)*pw;
        if(h)
            v.pb(h);
        tmp/=10;
        pw*=10;
    }
    int c=0,x=0;
    int sz=SZ(v);
    rep(i,sz){
        if((sz-c)+x>=n)
            break;
        c++;
        x+=v[i];
    }
    if(c==0){
        int sum=0;
        rep(i,sz){
            if(i<n-1)
                cout<<v[i]<<" ";
            else
                sum+=v[i];
        }
        cout<<sum<<" ";
    }
    else{

        if(c==sz){
            cout<<"1 ";
            solve(x-1,(n-1));
        }
        else{
            FOR(i,c,sz-1)
                cout<<v[i]<<" ";
            solve(x,n-(sz-c));
        }
    }

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        int s,n;
        cin>>s>>n;
        solve(s,n);
        cout<<"\n";
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}