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
const ll MX=18;
const ll INF=1e18+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
 
ll n,m,k; 
ll happiness[MX][MX];
bool conf_prizes[MX][MX];
ll dp[65326][MX];
ll fn(ll bit_mask,ll last){

    if(last!=-1 && dp[bit_mask][last]!=-INF)
        return dp[bit_mask][last];

    if(bit_mask==0)
        return dp[bit_mask][last]=0;

    ll ans=-INF,person,prize;
    repe(i,n){
        repe(j,m){
            ll that_bit=(1<<(i-1));
            if(bit_mask&that_bit && (last==-1 || !conf_prizes[last][j])){
                ll cur=happiness[i][j]+fn(bit_mask^that_bit,j);
                if(cur>ans){
                    ans=cur;
                    prize=j;
                    person=i;
                }

            }
        }
    }
    
    return dp[bit_mask][last]=ans;
}

void solve(){
    
    cin>>n>>m>>k;
    repe(i,n)
        repe(j,m)
            cin>>happiness[i][j];
    rep(i,65326)
        repe(j,m)
            dp[i][j]=-INF;
    ll x,y;
    repe(i,k)
        cin>>x>>y,conf_prizes[x][y]=true;

    ll bit_mask=(1LL<<n)-1;
    ll ans=fn(bit_mask,-1);
    
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

    time0 = curtime;
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
 
    return 0;
 
}
