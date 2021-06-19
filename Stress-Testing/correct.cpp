//~ author      : Sumit Prajapati
//~ mail ID     : sumitprajapati821@gmail.com
//~ codefoces   : sumitprajapati81, codechef: sumit141
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
// #define int                 long long
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
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0, 0xFFFFFFFFFFFFFFFF);

const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;




void solve(){
    // int n,k;
    // cin>>n>>k;
    // 2^n
    for(int n=1;n<=16;n++){
    for(int k=1;k<=n;k++){
       // assert(n<=20);
    
    int a[n+1];
    repe(i,n)
        a[i]=(i>(n-k));
    int max_xor=-1;
    vector<int> ans;
    do{
        // repe(i,n)
        //     cout<<a[i]<<" \n"[i==n];
        int res=0;
        repe(i,n)
            res=(res^(a[i]?i:0));
        if(res>max_xor){
            max_xor=res;
            ans.clear();
            repe(i,n)
                if(a[i])
                    ans.pb(i);

        }
    }
    while (next_permutation(a+1,a+n+1));
    // for(auto &el:ans)
    //     cout<<el<<" ";
    // cout<<'\n';
    cout<<n<<" "<<k<<"-> ";
    cout<<max_xor<<'\n';
    }
    }
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