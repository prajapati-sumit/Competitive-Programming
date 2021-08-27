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
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 2e5 + 5;

int segm[4*MX];
int query(int cur, int start, int end, int qs, int qe) {
    if (start >= qs && end <= qe)
        return segm[cur];
    if (start > qe || end < qs)
        return 0;          //INVALID RETURN
    int mid = (start + end) >> 1;
    int A = query(2 * cur, start, mid, qs, qe);
    int B = query(2 * cur + 1, mid + 1, end, qs, qe);
    //MERGING STEP
    int res = max(A, B);

    return res;
}
void update(int cur, int start, int end, int ind, int val) {
    if (start == ind && start == end) {
        //DO UPDATE
        segm[cur]=val;
        return;
    }
    if (start > ind || end < ind)
        return;          //OUT OF RANGE
    int mid = (start + end) >> 1;
    update(cur << 1, start, mid, ind, val);
    update((cur << 1) ^ 1, mid + 1, end, ind, val);
    //MERGING STEP
    segm[cur] = max(segm[2 * cur], segm[2 * cur + 1]);
}



void solve() {

    int n;
    cin >> n;
    int a[n + 1], h[n + 1];
    repe(i, n)
    cin >> h[i];
    repe(i, n)
    cin >> a[i];

    pii dp[n + 1];
    // {value,last}
    dp[0] = {0, 0};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        pii res = { -1, -1};
        res.ff=query(1,1,n,1,h[i]);
        // for (int j = 0; j < i; j++) {
        //     if (dp[j].ss < h[i]) {
        //         res.ff = max(res.ff, dp[j].ff);
        //     }
        // }
        res.ss = h[i];
        res.ff += a[i];
        update(1,1,n,h[i],res.ff);
        dp[i] = res;
        ans = max(ans, dp[i].ff);
    }
    // repe(i, n)
    //     cout << i << " ->" << dp[i].ff << " " << dp[i].ss << '\n';
    cout << ans << '\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    // cin>>t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}