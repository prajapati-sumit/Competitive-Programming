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



bool isprime(int x){

    if(x==1)
        return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)
            return false;
    }
    return true;
}

void solve() {

    int n;
    cin>>n;
    string s;
    cin>>s;
    set<int>st{'2','3','5','7'};

    bool ok=false;
    char ch='%';
    rep(i,n){
        if(st.find(s[i])==st.end()){
            ch=s[i];
            ok=true;
            break;
        }
    }   

    if(ok){
        cout<<1<<"\n"<<ch<<'\n';
        return;
    }
    int x=0;
    rep(i,n){
        for(int j=1;j<n;j++){
            x=(10*(s[i]-'0')+s[j]-'0');
            if(!isprime(x)){
                cout<<2<<"\n"<<x<<'\n';
                return;
            }
        }
    }
    assert(0);



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