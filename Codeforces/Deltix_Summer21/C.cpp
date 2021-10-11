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



int inter(pii A,pii B){
    if(A.ff>A.ss)
        swap(A.ff,A.ss);
    if(B.ff>B.ss)
        swap(B.ff,B.ss);
    int l=max(A.ff,B.ff),r=min(A.ss,B.ss);
    if(r<l)
        return 0;
    return r-l+1;
}

void solve() {

    int n;
    cin>>n;
    int a[n+1];
    repe(i,n)
        cin>>a[i];

    int ans=0;
    for(int i=1;i<=n;i+=2){
        int cur=0;
        for(int j=i+1;j<=n;j++){
            if(j%2==0){
                int my=a[i],his=a[j];
                ans+=inter({1+cur,my+cur},{1,his});
            }
            if(j%2==0){
                cur-=a[j];
            }
            else
                cur+=a[j];
            if(cur+a[i]<0)
                break;
        }
    }

    cout<<ans<<'\n';
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