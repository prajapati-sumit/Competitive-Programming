// AUTHOR: SUMIT PRAJAPATI      
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()


const ll INF=1e15;
const int MX=2e3+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 0 
 
ll n;
ll a[MX]; 
ll nice=INF;
bool cmp(pl X,pl Y){
    if(X.ss==Y.ss)
        return X.ff<X.ss;
    return X.ss>Y.ss;
}
vector<ll> brute(){
    
    vector<ll> res(n);
    do {
        ll ans=0;
        ll mn=INF,mx=-1;
        rep(i,n){
            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
            // cout<<mn<<" "<<mx<<"\n";
            ans+=(mx-mn);

        }
        if(ans<nice){
            nice=ans;
            rep(i,n)
                res[i]=a[i];        }

    } while (next_permutation(a, a + n));

    return res;
}

void solve(){
  
    cin>>n;
    ll ans=0;
    rep(i,n)
        cin>>a[i];
    sort(a,a+n);
    vector<ll> best=brute();
    map<ll,ll>mp;
    vector<ll> final;
    rep(i,n){
        mp[a[i]]++;
    }
    
    // int cur=*mp.begin(); 
    // vect<ll>can;
    // cout<<cur<<"\n";   
    // trav(final)
    //     cout<<el<<" ";
    // cout<<"\n";
    trav(best)
        cout<<el<<" ";
    cout<<'\n';
    // ll mn=INF,mx=-1;
    // rep(i,n){
    //     mn=min(mn,a[i]);
    //     mx=max(mx,a[i]);
    //     cout<<mn<<" "<<mx<<"\n";
    //     ans+=(mx-mn);
    // }
    cout<<nice<<'\n';
} 
 
/*

4->3
5->1
7->1
8->3
2->2

6
1 3 3 3 6 6
1 6 3 3 6 3
0 1 5 2 2 5 2 
0 3 3 0 3
0 0 3 0
0 3
0 0 0
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}