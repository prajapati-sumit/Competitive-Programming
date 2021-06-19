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
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9+2;
const int MX=2e6+5;

 
 
void solve(){

    int n;
    cin>>n;
    int b[n];

    rep(i,n)
        cin>>b[i];
    multiset<int>st;
    st.insert(b[0]);
    int previous=b[0];
    repe(i,n-1){
        int cur=b[i];
        auto itl=st.lower_bound(cur);
        auto itu=st.upper_bound(cur);
        // for(auto el:st)
        //     cout<<el<<" ";
        // cout<<'\n';
        // cout<<cur<<" "<<prev<<" "<<*itl<<" "<<*itu<<'\n';
        if((itl!=st.end() && *itl==previous) || (itl!=st.begin() && *prev(itl)==previous)){

            previous=cur;
            st.insert(cur);
        }
        else if((itu!=st.end() && *itu==previous) || (itu!=st.begin() && *prev(itu)==previous)){

            previous=cur;
            st.insert(cur);
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
  
    cout<<"YES\n";
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}