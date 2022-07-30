//~ author      : Sumit Prajapati



/*         Optimisations        */

// #pragma GCC optimize("O3")
// #pragma GCC target ("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;



/*-----------------Ordered Set-------------------*/

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



/*-----------------Macros------------------------*/

#define ull                     unsigned long long
#define ll                      long long
#define ld                      long double
#define int                     long long
#define pii                     pair<int, int>
#define pll                     pair<ll, ll>
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define SZ(x)                   ((int)x.size())
#define set_bits                __builtin_popcountll
#define all(a)                  a.begin(),a.end()
#define rep(i,n)                for(int i=0;i<n;i++)
#define repe(i,n)               for(int i=1;i<=n;i++)
#define rev(i,n)                for(int i=n-1;i>=0;i--)
#define reve(i,n)               for(int i=n;i>=1;i--)
#define FOR(i,a,b)              for(int i=(a);i<=(b);i++)
#define curtime                 chrono::high_resolution_clock::now()
#define timedif(start,end)      chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)


/*-----------------Utility Functions-------------*/

int gcd(int a, int b) {return a * b == 0 ? a ^ b : __gcd(a, b);}
template<class T>
void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)), end(v));
}
ll power(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll inv(int x, int mod) {return power(x, mod - 2, mod);}


/*-----------------Debugging---------------------*/

template<class Fun> class y_combinator_result {
	Fun fun_;
public:
	template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type > ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename TT, typename... UU> void dbg_out(TT H, UU... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define stop(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);cerr<<"exited\n";exit(0);
#else
#define dbg(...)
#define stop(...)
#endif

/*-----------------Global Variables--------------*/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const ll INFLL = 1e18;
const int MX = 1e3 + 5;
const int dx[4] {1, 0, -1, 0}, dy[4] {0, 1, 0, -1};
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;



/*-----------------Let's Go----------------------*/


int freq[MX];
int vis[MX];
int sentinel = 0;

void solve() {

	int n;
	cin >> n;
	sentinel++;
	rep(i, n) {
		int x;
		cin >> x;
		if (vis[x] == sentinel)
			freq[x]++;
		else {
			vis[x] = sentinel;
			freq[x]++;
		}
	}
	for (int d = 1; d <= 1000; d++) {
		int here = 0;
		for (int j = MX - d - 1; j >= 1; j--) {
			here +=
		}
	}
}



int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifdef LOCAL
	// auto time0 = curtime;
#endif

	int t = 1;
	cin >> t;

	repe(tt, t) {
		// cout<<"Case #"<<tt<<": ";
		solve();
	}

#ifdef LOCAL
	// cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
#endif

	return 0;

}