//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#include <sys/resource.h>
#endif
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
const int INF = 1e12;
const int MX = 1e5 + 5;




void solve() {


    int n;
    cin>>n;
    int a[n+1];
    stack<int>st;
    int nmleft[n+1];
    repe(i,n)
        cin>>a[i];

    repe(i,n){
        while(!st.empty() && a[st.top()]<=a[i])
            st.pop();
        if(st.empty())
            nmleft[i]=0;
        else
            nmleft[i]=st.top();
        st.push(i);
        // cout<<nmleft[i]<<" \n"[i==n];
    }
    int dp[n+1];
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int lef=nmleft[i];
        if(lef==0 && a[i]>a[1]){
            dp[i]=INF;
        }
        else
            dp[i]=1+dp[lef];
        // cout<<i<<" "<<dp[i]<<'\n';
    }
    if(dp[n]>=INF-1e9)
        cout<<"-1\n";
    else
        cout<<dp[n]<<'\n';


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ONLINE_JUDGE
    rlimit R;
    getrlimit(RLIMIT_STACK, &R);
    R.rlim_cur = R.rlim_max;
    setrlimit(RLIMIT_STACK, &R);
    #endif
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