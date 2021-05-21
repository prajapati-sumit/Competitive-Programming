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
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const ll INF=1e18;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
string X; 
 
ll maxCanGo(ll base){
    ll ans=(log2(INF)/log2(base))+1;
    //cout<<ans<<" ^ \n";
    return ans;
} 

ll evaluate(ll base,ll n){
    ll res=0;
    ll cur_power=1;
    for(ll i=n-1;i>=0;i--){
        res+=(cur_power*(X[i]-'0'));
        cur_power*=base;
    }
    return res;
}
 
void solve(){
  
    
    ll M;
    cin>>X>>M;
    ll n=X.length();
    if(n==1){
        ll one=X[0]-'0';
        if (one<=M){
            cout<<"1";

        }
        else cout<<"0";
        return;
    }
    char max_digit;
    for(auto ch:X)
        if(max_digit<ch)
            max_digit=ch;

    ll cur_digit=max_digit-'0'+1;
    //cout<<cur_digit<<'\n';
    ll cur_value;
    ll ans=0;
    ll l=cur_digit,r=1e18,mid;
    while(l<=r){
        mid=(l+r)>>1;

        if(maxCanGo(mid)>=n && evaluate(mid,n)<=M){
            //cout<<mid<<" "<<ans<<" "<<evaluate(mid,n)<<'\n';
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;

    }
    //cout<<ans<<'\n';
    if(ans!=0){
        ans=(ans-(cur_digit)+1);

    }

    cout<<ans<<'\n';
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    //cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}