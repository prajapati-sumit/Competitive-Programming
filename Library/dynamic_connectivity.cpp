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

int gcd(int a,int b) {return a*b==0?a^b:__gcd(a,b);}
template<class T> 
void remDup(vector<T>& v) { // sort and remove duplicates
    sort(all(v)); v.erase(unique(all(v)),end(v)); }
    ll power(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
    ll inv(int x,int mod){return power(x,mod-2,mod);}


/*-----------------Debugging---------------------*/

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
        template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
        template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
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
const int MX = 3e5 + 5;
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;



/*-----------------Let's Go----------------------*/




// #warning works on array from 1...n
// with path compression and union by rank.
// Disjoint Set Union
class DSU{

public:
    vector<int>parent;
    vector<pii>stk;
    int cc;
    DSU(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
            parent[i]=-1;
    }
    int find_set(int x){
        return parent[x]<0?x:find_set(parent[x]);
    } 
    void union_set(int a,int b){
        int pa=find_set(a);
        int pb=find_set(b);
        if(pa==pb){
            stk.push_back({-1,parent[pb]});
            return;
        }
        if(parent[pa]>parent[pb])
            swap(pa,pb);
        stk.push_back({pb,parent[pb]});
        parent[pa]+=parent[pb];
        parent[pb]=pa;
        cc--;
    } 
    int getCC(){
        return cc;
    }
    void rollback(){

        assert(stk.size());
        pii last = stk.back();
        stk.pop_back();
        if(last.ff==-1)
            return;
        parent[parent[last.ff]] -=last.ss; 
        parent[last.ff] = last.ss;
        cc++;
    }
    bool same_set(int a,int b){
        return find_set(a)==find_set(b);
    }

};
int n,q;
DSU D(MX);
vector<pii>segm[4*MX];
void addRange(int cur,int start,int end,int qs,int qe,int x,int y){
    if (start >= qs && end <= qe){
        segm[cur].push_back({x,y});
        return;
    }
    if(start>qe || end<qs)
        return;
    int mid = (start + end) >> 1;
    addRange((cur << 1) , start, mid, qs, qe,x,y);
    addRange((cur << 1) ^ 1, mid + 1, end, qs, qe,x,y);
}

struct Query{
    char ty;
    int x,y;
    int cc;
    Query(){

    }
    Query(char ch,int a=-1,int b=-1){
        ty = ch;
        x = a;
        y = b;
        cc = 0;
    }
}Q[MX];

void dfs(int cur,int start,int end){
    // dbg(cur,segm[cur],D.stk);
    for(auto &el:segm[cur])
        D.union_set(el.ff,el.ss);
    // dbg(cur,segm[cur],start,end,D.getCC());
    if(start==end){
        Q[start].cc = D.getCC();
    }
    else{
        int mid = (start+end)/2;
        dfs(2*cur,start,mid);
        dfs(2*cur+1,mid+1,end);
    }
    for(auto &el:segm[cur]){
        
        D.rollback();
    }
    // dbg(cur,segm[cur],D.stk);
}
void solve() {
    int m;
    cin>>n>>m>>q;
    set<tuple<int,int,int>>st;
    D.cc = n;
    q+=m;
    FOR(i,1,q){
        char ch;
        int x,y;
        if(i<=m)
            ch='1';
        else
            cin>>ch;
        cin>>x>>y;
        if(x>y)
            swap(x,y);
        if(ch=='1')
            st.insert({x,y,i});
        else{
            auto it = st.lower_bound({x,y,-1});
            assert(it!=st.end());
            int l =  get<2>(*it);
            int r = i-1;
            st.erase(it);
            // dbg(l,r,x,y);
            addRange(1,1,q,l,r,x,y);
        }
    
        Q[i] = Query(ch,x,y);
    }
    for(auto &el:st){
       int l = get<2>(el);
       int r = q;
       int x = get<0>(el);
       int y = get<1>(el);
       // dbg(l,r,x,y);
       addRange(1,1,q,l,r,x,y);
    }
    dfs(1,1,q);
    FOR(i,m,q)
            cout<<Q[i].cc<<" ";


}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
        // auto time0 = curtime;
    #endif

    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    #ifdef LOCAL
        // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    #endif

    return 0;

}