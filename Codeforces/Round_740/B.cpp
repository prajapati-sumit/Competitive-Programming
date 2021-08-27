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



void solve(){
    int n=8;
    int nax=(1<<n);
    map<pii,set<int>>mp;
    for(int i=0;i<nax;i++){
        int A=0,B=0,k=0;
        rep(j,n){
            if(i&(1<<j)){
                if(j%2==0)
                    A+=1;
                else
                    B+=1;
            }
            else{
                k++;
                if(j%2==0)
                    B+=1;
                else
                    A+=1;
            }
        }
        mp[{min(A,B),max(A,B)}].insert(k);
    }
    for(auto &el:mp){
        cout<<"{ "<<el.ff.ff<<" "<<el.ff.ss<<"} : ";
        for(auto &el2:el.ss)
            cout<<el2<<" ";
        cout<<'\n'; 
    }
}

void solve2() {

    int a,b;
    cin>>a>>b;
    int n=a+b;
    if(a>b)
        swap(a,b);
    int h=n/2;
    vector<int>v;
    if(n&1){
        int A=h-a;
        int d=1;
        int N=2*(a+1);
        while(N--){
            v.pb(A);
            A+=d;
        }
    }
    else{
        int A=h-a;
        int d=2;
        int N=(a+1);
        while(N--){
            v.pb(A);
            A+=d;
        }
    }
    cout<<SZ(v)<<"\n";
    for(auto &el:v)
        cout<<el<<" ";
    cout<<'\n';
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