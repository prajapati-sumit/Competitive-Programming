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
const ll MX=5e5+10;
const ll MD=1e9+7;
const ll MDL=998244353;
auto time0 = curtime;
 
 
 
ll n,p;
ll a[MX],C[MX]; 
vector<int>v[MX];
ll cnt;
bool flag;

void fastscan(ll &x)
{
   
    register ll c;
    x =0;
    c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    
}

ll pow_mod(ll base, ll exp,ll mod=MD) {
  base %= mod;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
bool isquad(ll k,ll p){
    return pow_mod(k,(p-1)/2,p)==1;
}

ll TShank(ll n, ll p) {
    if(p%4==3){
        ll r = pow_mod(n, (p+1)/4, p);
        return r;
    }
    ll s = 0;
    ll q = p - 1;
    while ((q & 1) == 0) { q /= 2; ++s; }
    if (s == 1) {
    long r = pow_mod(n, (p+1)/4, p);
    if ((r * r) % p == n) return r;
    return 0;
    }
    // Find the first quadratic non-residue z by brute-force search
    ll z = 1;
    while (pow_mod(++z, (p-1)/2, p) != p - 1);
    ll c = pow_mod(z, q, p);
    ll r = pow_mod(n, (q+1)/2, p);
    ll t = pow_mod(n, q, p);
    ll m = s;
    while (t != 1) {
    ll tt = t;
    ll i = 0;
    while (tt != 1) {
        tt = (tt * tt) % p;
        ++i;
        if (i == m) return 0;
    }
    ll b = pow_mod(c, pow_mod(2, m-i-1, p-1), p);
    ll b2 = (b * b) % p;
    r = (r * b) % p;
    t = (t * b2) % p;
    c = b2;
    m = i;
    }
    if ((r * r) % p == n) return r;
    return 0;
}
ll dfs(ll cur){

    
    if(v[cur].size()==0){
        if(C[cur]!=0 && !isquad(C[cur],p)){
            
            flag=false;
            return 0;
        }
       

        if(C[cur]!=0)
            cnt=(cnt*2)%MDL;
        if(cur==8){
           
        }
        return  a[cur]=TShank(C[cur],p);
    }

    ll temp=0,sumsq=0;
    for(auto child:v[cur]){
        ll chv=dfs(child)%p;
        temp=(temp+chv)%p;
        sumsq=(sumsq+(chv*chv))%p;
    }
    
    if(!flag)
        return 0;
    sumsq=(sumsq+C[cur])%p;
    
    
    if(sumsq!=0 && !isquad(sumsq,p)){
          
            flag=false;
            return 0;
    }
    if(sumsq!=0)
        cnt=(cnt*2)%MDL;
    a[cur]=(p+TShank(sumsq,p)-temp)%p;
    return (a[cur]+temp)%p;






}
void solve(){
    fastscan(n);
    fastscan(p);

    cnt=1;
    flag=true;

    repe(i,n)
        v[i].clear();

    ll el;
    FOR(i,2,n)
        fastscan(el),v[el].pb(i);
    
    repe(i,n)
        fastscan(C[i]);
  
    dfs(1);
    
    if(flag){
        cout<<cnt<<"\n";
        repe(i,n)
            cout<<a[i]<<" ";
    }
    else{
        cout<<"0\n-1";
    }
    cout<<'\n';
    
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

    time0 = curtime;
    ll t=1;
    fastscan(t);
    while(t--)
        solve();
 
    return 0;
 
}
