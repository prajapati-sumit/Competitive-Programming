//CODED BY SUMIT KUMAR PRAJAPATI
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
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e6+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 
 
ll n;
ll a[MX]; 
ll brute(){
    ll res=0,cur_and=1,cur_or=0,XOR,MAX=-1;
    repe(i,n){
        cur_and=a[i];
        cur_or=a[i];
        MAX=a[i];
        FOR(j,i,n){
            cur_and&=a[j];
            cur_or|=a[j];
            MAX=max(a[j],MAX);
            XOR=cur_and^cur_or;
            //cout<<i<<" "<<j<<": "<<XOR<<" "<<MAX<<'\n';
            if(MAX<=XOR){
                cout<<i<<" "<<j<<'\n';
                res++;
            }

        }
    }
    return res;
}
ll brute2(){
    ll res=0,cur_and=1;
    repe(i,n){
        cur_and=a[i];
        FOR(j,i,n){
            cur_and&=a[j];
           
            if(cur_and==0){
                cout<<i<<" "<<j<<'\n';
                res++;
            }

        }
    }
    return res;
}
void solve(){
  
    cin>>n;
    ll ans=(n * (n + 1))/2;
    vector<ll> v;
    repe(i,n)
        cin>>a[i];
    if(n==1){
        if(a[1]==0)
            cout<<"1\n";
        else 
            cout<<"0\n";
        return;
    }
    ll prev=a[1],cnt=1;
    FOR(i,2,n){
        if(a[i]==prev)
            cnt++;
        else{
            prev=a[i];
            v.pb(cnt);
            cnt=1;

        }
    }
    v.pb(cnt);
    trav(v){
        ans-=(el*(el+1))/2;
       // cout<<el<<" ";
    }
    //cout<<'\n';
    cout<<brute()<<" ";
    cout<<brute2()<<" ";
    cout<<ans<<'\n';

// 110
// 100

// 100

// 110

// 010 
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}