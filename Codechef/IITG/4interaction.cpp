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




bool isvalid(int x){
    string res;
    if(x==0)
        return false;
    while(x){
        res.pb('0'+x%2);
        x>>=1;
    }
    reverse(all(res));
    string tmp="1011";
    if(SZ(res)<4)
        return false;
    for(int i=0;i+3<SZ(res);i++)
        if(res.substr(i,4)==tmp)
            return true;
    return false;
}

void solve() {

    
    int n=64;
    // int cnt=1;
    // repe(x,n){
    //     if(isvalid(x)){
    //         cout<<cnt++<<" "<<x<<" "<<bitset<6>(x)<<"\n";
    //     }
    // }
    for(int i=0;i<=56;i++){
        cout<<(1LL<<i)*(i+1)<<'\n';
    }
    return;
    // // {1011}
    int l=1,r=56,ans=0,mid;
    while(l<=r){
        mid=(l+r)>>1;
        int cur=(1LL<<mid)*(mid+1);
        if(cur>=n){
            r=mid-1;
            ans=mid;
        }
        else{
            l=(mid+1);
        }
    }
    int max_h=(1LL<<ans)*(ans+1);
    int which=(n+ans)/(ans+1);
    int rem=n-((which-1)*(ans+1));
    cout<<ans<<" "<<rem<<" "<<which<<'\n';
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

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}