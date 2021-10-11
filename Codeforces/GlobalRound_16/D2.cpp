//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                     unsigned long long
#define ll                      long long
// #define int                     long long
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


int n,m;
int a[305][305];
bool seats[305][305];
void solve() {

    
    cin>>n>>m;
    vector<int>org;
    map<int,int>mp;
    map<int,vector<pii>>mp2;
    repe(i,n)
        repe(j,m)
            cin>>a[i][j],org.pb(a[i][j]),mp[a[i][j]]++,seats[i][j]=0;
    int p=1;
    for(auto &el:mp){
        vector<pii>tmp;
        int L=p,R=p+el.ss-1;
        int r1=((L)/m)+(L%m!=0);
        int c1=L-(m*(r1-1));
        int r2=((R)/m)+(R%m!=0);
        int c2=R-(m*(r2-1));
        
        if(r1==r2){
            for(int col=c1;col<=c2;col++)
                tmp.pb({r1,col});
        }
        else{
            for(int col=1;col<=c2;col++)
                tmp.pb({r2,col});
            for(int col=1;col<=m;col++)
                for(int row=r1+1;row<=r2-1;row++){
                    tmp.pb({row,col});
            }
            for(int col=c1;col<=m;col++)
                tmp.pb({r1,col});
        }

        mp2[el.ff]=tmp;
        p=p+el.ss;
    }
    int ans=0;
    for(auto &el:org){
        // [last+1,last+el+1]
        pii best=mp2[el].back();
        mp2[el].pop_back();
        int r=best.ff;
        int c=best.ss;
        assert(!seats[r][c]);
        repe(i,c-1)
            ans+=seats[r][i];
        seats[r][c]=1;
        // cout<<el<<":"<<r<<" "<<c<<"->"<<ans<<"\n";

    }
    cout<<ans<<"\n";

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