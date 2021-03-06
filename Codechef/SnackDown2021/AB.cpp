//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;

//---------------------Macros----------------------------------------------------------------------------------
#define ull                     unsigned long long
#define ll                      long long
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
#define vec                     vector
#define trav(x,v)               for(auto &x:v)
#define rep(i,n)                for(int i=0;i<n;i++)
#define repe(i,n)               for(int i=1;i<=n;i++)
#define FOR(i,a,b)              for(int i=a;i<=b;i++)
#define curtime                 chrono::high_resolution_clock::now()
#define timedif(start,end)      chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define myshuffle(a,n)          FOR(i,1,n-1) swap(a[i], a[rand() % (i + 1)])
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)
// ------------------------------------------------------------------------------------------------------------


// -----------------------------Debugging----------------------------------------------------------------------
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
#else
#define dbg(...)
#endif
// -----------------------------------------------------------------------------------------------------------



// ------------------------------Global Variables-------------------------------------------------------------
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;
// -----------------------------------------------------------------------------------------------------------



// --------------------------------Let's Go!------------------------------------------------------------------
struct Testcase {


    void solve() {

        int n;
        cin>>n;
        int a[n+1];
        repe(i,n)
            cin>>a[i];
        sort(a+1,a+n+1);
        if(n==2){
            cout<<"0\n";
            return;
        }
        if(n==3){
            int ans;
            if(a[1]==a[2] || a[2]==a[3])
                ans=0;
            else
                ans=min(a[3]-a[2],a[2]-a[1]);
            cout<<ans<<"\n";
            return;           
        }
        int target=a[1]+a[n];
        int cand[n-2];
        FOR(i,2,n-1){
            cand[i-2]=a[i];
        }
        int ans=INF;
        int sz=n-2;
        rep(i,sz){
            int rem=target-cand[i];
            // int j=lower_bound(cand,cand+i-1,rem)-cand;
            // if(j==i){
            //     if(i>0)
            //         ans=min(ans,abs(rem-cand[i-1]));
            // }
            // else{
            //     ans=min(ans,abs(rem-cand[j]));
            //     if(j>0)
            //         ans=min(ans,abs(rem-cand[j-1]));
            // }
            int l=0,r=i-1,mid,ind=-1;
            while(l<=r){
                mid=(l+r)>>1;
                if(cand[mid]>=rem){
                    ind=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            if(i>0)
                ans=min(ans,abs(rem-cand[i-1]));
            if(ind!=-1){
                ans=min(ans,abs(rem-cand[ind]));
                if(ind>0)
                    ans=min(ans,abs(rem-cand[ind-1]));
            }


        }
        cout<<ans<<"\n";
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        Testcase T;
        T.solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}