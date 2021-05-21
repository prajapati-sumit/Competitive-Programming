#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;

#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const ll MD=1e9+7;
const ll MX=1e4+4;
ll n,fact[2*MX],arr[2*MX];
ll power(ll base, ll exp,ll mod) {
  base %= mod;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
ll modinverse(ll x){
    return power(x,MD-2,MD);
}
ll ncr(ll p,ll q){

    ll ans=((fact[p]*modinverse(fact[p-q])%MD)*modinverse(fact[q]))%MD;
    return ans;
}
void init(){
    fact[0]=1;
    repe(i,2*MX-1){
        fact[i]=(i*fact[i-1])%MD;
    }
}

void solve(){
    
    cin>>n;
    repe(i,n-1){
        arr[i]=i;
    }
    arr[n]=n;
    repe(i,n-1)
        arr[i+n]=n-i;
    // repe(i,2*n-1)
    //     cout<<arr[i]<<" ";
    // cout<<'\n';
    ll ans=0,mul=ncr(2*(n-1),n);
    repe(i,n-1){
        ll cur=(mul*i)%MD;
        ans=(ans+cur)%MD;
    }
    ans=(2*ans)%MD;
    ll cur=(n*mul)%MD;
    ans=(ans+cur)%MD;

   
    cout<<ans<<'\n';

 
} 
 
 
 int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #else
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
          cout.tie(NULL);
     #endif

    srand(time(0));	
    init();
    
    ll t=1;
    cin>>t;
    while(t--)
        solve();
 
    return 0;
 
}
