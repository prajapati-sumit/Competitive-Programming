//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


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
#define trav(x,v)               for(auto &x:v)
#define rep(i,n)                for(int i=0;i<n;i++)
#define repe(i,n)               for(int i=1;i<=n;i++)
#define FOR(i,a,b)              for(int i=a;i<=b;i++)
#define curtime                 chrono::high_resolution_clock::now()
#define timedif(start,end)      chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define myshuffle(a,n)          FOR(i,1,n-1) swap(a[i], a[rand() % (i + 1)])
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;




string s;
int N;
int fn(int cur,vector<int> carry){
    if(cur==N){
        for(auto &el:carry){
            if(el)
                return 0;
        }
        return 1;
    }

    int x=(s[cur]-'0'-carry[cur]+20)%10;
    carry[cur]=0;
    // cout<<x<<" "<<n<<": ";
    // rep(i,5)
    //     cout<<carry[i]<<" ";
    // cout<<'\n';
    int direct=max(0LL,x+1);
    int indirect=9-x;
    vector<int>tmp=carry;
    tmp[cur+2]+=1;
    int res=0;
    if(direct)
        res+=direct*fn(cur+1,carry);
    if(indirect)
        res+=indirect*fn(cur+1,tmp);
    cout<<res<<" "<<cur<<" "<<s[cur]<<"\n";
    return res;
}
void solve() {
    cin>>s;
    int n=s.length();
    N=n;
    vector<int>carry(15,0);
    int ans=fn(0,carry);
    ans-=2;
    cout<<ans<<'\n';


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}