// AUTHOR: SUMIT PRAJAPATI
#include "bits/stdc++.h"
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
#define TESTCASES 1

const int INF = 1e9;
const int MX = 1e5 + 5;
const int MD = 1e9 + 7;
const int MDL = 998244353;
auto time0 = curtime;




int n;
int PASCAL[35][35];
void init() {
    repe(i, 33) {
        repe(j, i) {
            if (j == 1 || j == i)
                PASCAL[i][j] = 1;
            else
                PASCAL[i][j] = PASCAL[i - 1][j] + PASCAL[i - 1][j - 1];
        }
    }
}
void solve() {

    cin >> n;
    vector<pair<int, int>>v[35];
    vector<int>zeroes(33, 0);
    int temp = n, dir = 1, cnt = 0;
    for (int i = 0; i < 32; i++) {
        if (temp & (1 << i)) {
            if (dir == 1) {
                for (int j = 1; j <= (i + 1); j++) {
                    v[i].pb({i + 1, j});
                }
            }
            else {
                for (int j = i + 1; j >= 1; j--) {
                    v[i].pb({i + 1, j});
                }
            }
            dir *= -1;
            zeroes[i] = cnt;
            cnt = 0;
        }
        else
            cnt++;
    }
    // trav(v) {
    //     for (auto x : el) {
    //         cout << "{ " << x.ff << " " << x.ss << "} ";
    //     }
    //     cout << '\n';
    // }
    for (int i = 31; i >= 0; i--) {
        if (zeroes[i] > 0) {
            int x = zeroes[i];
            dir = v[i].back().ss == 1 ? -1 : 1;

            for (int j = x; j > 0; j--) {
                v[i].pop_back();
                int cur = i - x + j;
                if (dir == 1) {
                    if((x-j)%2==0){
                        for (int k = cur-j+1; k <=cur; k++) {
                            // cout<<cur<<" "<<k<<"\n";
                            v[cur-1].pb({cur, k});
                        }
                    }
                    else{
                        for (int k = cur; k >(cur-j); k--) {
                            // cout<<cur<<" "<<k<<"\n";
                            v[cur-1].pb({cur, k});
                        }
                    }
                }
                else {
                    if((x-j)%2==0){
                        for (int k = j; k >=1; k--) {
                            // cout<<cur<<" "<<k<<"\n";
                            v[cur-1].pb({cur, k});
                        }
                    }
                    else{
                        for (int k = 1; k <= j; k++) {
                            // cout<<cur<<" "<<k<<"\n";
                            v[cur-1].pb({cur, k});
                        }
                    }
                }
            }
        }
    }
    // trav(v) {
    //     for (auto x : el) {
    //         cout << "{ " << x.ff << " " << x.ss << "} ";
    //     }
    //     cout << '\n';
    // }
   
    vector<pair<int,int>> ans;
    for(int i=32;i>=0;i--){
        for(int j=0;j<v[i].size();j++)
            ans.pb(v[i][j]);
    }
    reverse(ans.begin(),ans.end());
    int brutesum=0;
    trav(ans){
        brutesum+=PASCAL[el.ff][el.ss];
        cout<<el.ff<<" "<<el.ss<<"\n";
    }
    // cout<<ans.size()<<" ";
    assert(brutesum==n);
    // cout<<brutesum<<" "<<n<<'\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0));
    time0 = curtime;
    init();
    ll t = 1;
    if (TESTCASES)cin >> t;
    repe(tt, t) {
        n = tt;
        cout<<"Case #"<<tt<<": \n";
        solve();
    }

    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}