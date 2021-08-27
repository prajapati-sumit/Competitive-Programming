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



priority_queue<int,vector<int>,greater<int>>pq;
int helper(vector<int>& v){
    int n=v.size();
    int cnt=1;
    int res=0;
    vector<int>consider;
    FOR(i,1,n-1){
        // cerr<<cnt<<" "<<i<<'\n';
        if(v[i]>=v[i-1]){
            cnt++;
        }
        else{
            consider.pb(cnt);
            cnt=1;
        }
    }
    consider.pb(cnt);
    int tmp1=0,tmp2=0;
    int len=0;
    int sz=consider.size();

    rep(i,sz-1){
        len+=consider[i];
        tmp1+=min(consider[i],n-len);
    }
    len=0;
    for(int i=sz-1;i>0;i--){
        len+=consider[i];
        tmp2+=min(consider[i],n-len);
    }
    res=min(tmp1,tmp2);

    rep(i,sz)
        pq.push(consider[i]); 


    // cout<<tmp1<<" "<<tmp2<<'\n';
    // for(auto &el:consider){
    //     cout<<el<<" ";
    // }
    // cout<<"->"<<res;
    return res;
}
int ans=0;
void solve() {

    int n;
    cin>>n;
    vector<int>v[n];
    ans=0;
    rep(i,n){
        int k;
        cin>>k;
        rep(j,k){
            int x;
            cin>>x;
            v[i].pb(x);
        }
        ans+=helper(v[i]);
    }
    while(pq.size()!=1){
        int p1=pq.top();
        pq.pop();
        int p2=pq.top();
        pq.pop();
        ans+=(p1+p2);
        pq.push(p1+p2);

    }
    pq.pop();
    // for(auto &el:gl)
    //     cout<<el<<" ";
    // cout<<'\n';

    cout<<ans<<'\n';
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