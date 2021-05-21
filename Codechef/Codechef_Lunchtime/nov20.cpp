#include <bits/stdc++.h>
using namespace std;

//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repe(i, n) for (ll i = 1; i <= n; i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define curtime chrono::high_resolution_clock::now()
#define timedif(start, end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX = 2e5 + 5;
const int MD = 1e9 + 7;
const int MDL = 99824453;
auto time0 = curtime;
ll n;
bool flag;
struct CAR{
    ll fuel;
    ll cost;
} car[MX];

bool cmp(CAR A, CAR B){
    return (A.cost<B.cost);
        
}
bool vis[MX];
ll dp(ll cur,ll dist){
    if(dist==n)
        return 0;
    else if(dist>n)
        return MD;
    if(car[cur].fuel==0)
        return MD;
    ll k=MD,ind;
    for(ll i=1;i<=car[cur].fuel;i++){
        ll temp=dp(i+cur,dist+cur);
        if(k>temp){
            k=temp;
            ind=i;
        }   
    }
    if(!vis[cur]){
        vis[cur]=1;
        return min(dp(cur,0),(ind*car[cur].cost+k));
    }
    else
        return (ind*car[cur].cost+k);
}

void solve(){
    repe(i,n)
        vis[i]=0;
    cin>>n;
    repe(i,n)
        cin>>car[i].fuel;
    repe(i,n)
        cin>>car[i].cost;
    ll ans=MD;
    cout<<dp(1,0)<<'\n';
   
}
int main()
{

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
    ll t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
