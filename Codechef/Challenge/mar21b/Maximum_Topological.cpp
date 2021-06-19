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

const int INF = 1e9;
const ll MX = 5e5 + 5;
const ll MD = 1e9 + 7;
const int MDL = 998244353;
auto time0 = curtime;

vector<ll>v[MX];
ll fact[MX];
long double lnfact[MX];
ll subtree[MX];
long double sz[MX];
ll dp[MX];
ll n, k;
vector< pair<ll, ll> > final;
vector< pair<long double, ll> > order;
long double tr=1e-9;

void fastscan(ll &x)
{
    ll c;
    x =0;
    c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    
}

bool cmp(pair<long double, ll>A, pair<long double, ll> B) {

    if ( abs(A.ff - B.ff) <=tr)
        return A.ss > B.ss;
    return A.ff > B.ff;
}
bool cmp2(pl A, pl B) {
    if (A.ff == B.ff)
        return A.ss > B.ss;
    return A.ff > B.ff;
}

ll bin_power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % MD;
        a = (a * a) % MD;
        b >>= 1;
    }
    return res;
}
ll modInverse(ll x) {
    return bin_power(x, MD - 2);
}
long double calc(ll cur) {
    return lnfact[cur];
}

ll dfs(ll node, ll par) {
    subtree[node] = 1;
    trav(v[node]) {
        if (el != par)
            subtree[node] += dfs(el, node);

    }
    return subtree[node];
}


ll NoS(ll node, ll par) {
    ll coeff = fact[subtree[node] - 1], res = 1;
    trav(v[node]) {
        if (el != par) {
            ll temp = NoS(el, node);
            res = (res * temp) % MD;
            coeff = (coeff * modInverse(fact[subtree[el]])) % MD;

        }
    }
    return dp[node] = (coeff * res) % MD;

}
long double NoS2(ll node,ll par){
    long double c2 = calc(subtree[node] - 1), r2 = 0;
    trav(v[node]) {
        if (el != par) {
            long double temp = NoS2(el, node);
            c2 = (c2 - calc(subtree[el]));
            
            if(temp!=0)
                r2 = (r2 + temp);

        }
    }
    return sz[node] = c2 + r2;

}
void reRoot(ll cur, ll next) {

   
    dp[cur] = (dp[cur] * modInverse(dp[next])) % MD;
    dp[cur] = (((dp[cur] * fact[subtree[next]]) % MD) * fact[subtree[cur] - subtree[next] - 1]) % MD;
    dp[cur] = (dp[cur] * modInverse(fact[subtree[cur] - 1])) % MD;
    sz[cur] = (sz[cur] - sz[next]);
    sz[cur] = (sz[cur] + calc(subtree[next]) + calc(subtree[cur] - subtree[next] - 1));
    sz[cur] = (sz[cur] - calc(subtree[cur] - 1));
   
    subtree[cur] = subtree[cur] - subtree[next];


    dp[next] = (dp[next] * fact[n - 1]) % MD;
    dp[next] = (dp[next] * dp[cur]) % MD;
    dp[next] = (dp[next] * modInverse(fact[subtree[cur]])) % MD;
    dp[next] = (dp[next] * modInverse(fact[subtree[next] - 1])) % MD;
    sz[next] = (sz[next] + calc(n - 1));
    sz[next] = (sz[next] + sz[cur]);
    sz[next] = (sz[next] - calc(subtree[cur]));
    sz[next] = (sz[next] - calc(subtree[next] - 1));
   
    subtree[next] = n;


}
void fn(ll cur, ll prev) {
    final.pb({dp[cur], cur});
    order.pb({sz[cur], cur});
    trav(v[cur]) {
        if (el != prev) {
            reRoot(cur, el);
            fn(el, cur);
            reRoot(el, cur);
        }
    }
}



void solve() {


    repe(i, MX - 1)
        v[i].clear();
    order.clear();
    final.clear();
    fastscan(n);fastscan(k);

    ll x, y;
    repe(i, n - 1){
        fastscan(x);fastscan(y);
        v[x].pb(y);v[y].pb(x);
    }
    dfs(1, -1);
    NoS(1, -1);
    NoS2(1,-1);
    // repe(i,n)
    //     cout<<i<<"-> "<<sz[i]<<" \n";
    // cout<<'\n';
    fn(1, -1);

    if(n<=10){
        sort(final.begin(), final.end(),cmp2);
        cout << final[k-1].ss << " " << final[k-1].ff << '\n';
        return;
    }
    sort(order.begin(), order.end(), cmp);
    // trav(order){
    //     cout<<el.ff<<" "<<el.ss<<"\n";
    // }
    // cout<<'\n';
    
    ll ind = order[k - 1].ss;
    trav(final) {
        if (el.ss == ind) {
            cout << el.ss << " " << el.ff << '\n';
            break;
        }
    }
}
// 792446474 3
// 730751790 15
// 624124528 1
// 617407993 19
// 617407993 16
// 610431734 4
// 515391923 7
// 385727853 14
// 376191986 17
// 348991867 13
// 328829158 10
// 328829158 2
// 310271832 8
// 279487993 9
// 147647685 12
// 140926782 11
// 138111818 20
// 32127986 6
// 32127986 5
// 18367993 18

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0));
    time0 = curtime;

    fact[0] = 1;
    lnfact[0]=0;
    repe(i, MX - 1){
        fact[i] = (i * fact[i - 1]) % MD;
        lnfact[i]=log(i)+lnfact[i-1];
    }
    //cout<<lnfact[5]<<" "<<lnfact[MX-1]<<'\n';
    ll t = 1;
    fastscan(t);
    repe(tt, t) {
        //cout<<"Case #"<<tt<<": ";
        solve();
    }

    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}