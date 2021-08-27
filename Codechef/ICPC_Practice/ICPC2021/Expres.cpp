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





void solve() {

    int n,x;
    cin>>n>>x;
    if(x==0 && n%2==1){
        cout<<"-1\n";
        return;
    }
    int ans=0;
    bool used=false;
    vector<int>cnt(31,0);
    rep(i,31){
        if((1LL<<i)&n){
            if(i%2==0){
                if(i==0)
                    cnt[i]++;
                else
                    cnt[i-1]+=2;
            }
            else
                cnt[i]++;
        }
        
    }    
    rep(i,31){
        int cur=(1LL<<i);
        int ind=0;
        for(int j=cnt[i];j>=0;j--){
            if(j*cur<=x){
                ind=j;
                break;
            }
        }
        if(ind>0)
            used=true;
        x-=(ind*cur);
        // cout<<x<<"\n";
        ans+=(cnt[i]-ind);
    }
    cout<<ans+used<<'\n';
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