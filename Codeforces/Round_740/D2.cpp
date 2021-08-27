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
const int MX = 4e6 + 5;

int m;
int N;
int dp[MX];

void solve() {

    cin>>N>>m;    
    dp[N]=1;
    int cur=0;
    for(int i=N-1;i>=1;i--){
        int op1=dp[i+1];
        int op2=0;
        int l,r,z=2;
        while(true){

            l=z*i;
            r=z*i+z-1;
            if(l>N)
                break;
            r=min(N,r);
            int sum=dp[l]-(r<N?dp[r+1]:0);
            sum=(sum+m)%m;
            op2=(op2+sum)%m;
            z++;
        }
        cur=(op1+op2)%m;
        dp[i]=(cur+dp[i+1])%m;

    }
    cout<<cur<<'\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}