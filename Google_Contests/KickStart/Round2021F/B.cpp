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
const int MX = 3e5 + 5;

struct Ride{
    int s;
    int e;
    int w;
}R[MX];

vector<int>start[MX];
vector<int>khatam[MX];
int D,N,K;


void solve() {

    cin>>D>>N>>K;
    repe(i,D)
        start[i].clear(),khatam[i].clear();
    repe(i,N){
        cin>>R[i].w>>R[i].s>>R[i].e;
        start[R[i].s].pb(i);
        khatam[R[i].e].pb(i);
    }    
    multiset<int>st;
    multiset<int>st2;//helper
    int sum=0;
    int ans=0;
    int sz;
    repe(i,D){

        for(auto &el:start[i]){
            sz=st.size();
            if(sz<K){
                st.insert(R[el].w);
                sum+=R[el].w;
            }
            else if(sz==K){
                auto it=st.begin();
                if((*it)<R[el].w){
                    sum-=(*it);
                    st2.insert(*it);
                    st.erase(it);
                    sum+=(R[el].w);
                    st.insert(R[el].w);
                }
                else
                    st2.insert(R[el].w);
            }
        }
        ans=max(sum,ans);

        for(auto &el:khatam[i]){
            auto it=st.lower_bound(R[el].w);
            if(it!=st.end() && (*it==R[el].w)){
                st.erase(it);
                sum-=R[el].w;
                if(st2.size()){
                    auto it2=st2.end();
                    it2--;
                    st.insert(*it2);
                    sum+=(*it2);
                    st2.erase(it2);
                }
            }
            else{
                it=st2.lower_bound(R[el].w);
                assert(it!=st2.end());
                st2.erase(it);
            }

        }
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
        cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}