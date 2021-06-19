//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;





void solve() {

    int n, m;
    cin >> n >> m;
    char a[n][m];
    rep(i, n)
    rep(j, m)
    cin >> a[i][j];
    while (true) {
        int cnt = 0;
        rep(i, n){
            rep(j, m) {
                if (a[i][j] == 'W') {
                    cnt++;
                    if (i > 0 )
                        if( a[i - 1][j] == 'W') {
                            cout << "NO\n";
                            return;
                        }
                        else{
                            a[i - 1][j] = 'R';
                        }
                    if (j > 0)
                        if(a[i][j - 1] == 'W') {
                            cout << "NO\n";
                            return;
                        }
                        else{
                            a[i][j - 1] = 'R';
                        }
                    if (i < n - 1)
                        if( a[i + 1][j] == 'W') {
                            cout << "NO\n";
                            return;
                        }
                        else{
                            a[i + 1][j] = 'R';
                        }
                    if (j < m - 1) 
                        if( a[i][j + 1] == 'W') {
                            cout << "NO\n";
                            return;
                        }
                        else{
                            a[i][j + 1] = 'R';
                        }
                }
                if (a[i][j] == 'R') {
                        // cout<<a[i][j]<<'\n';
                    if (i > 0 )
                        if( a[i - 1][j] == 'R') {
                            cout << "NO\n";
                            return;
                        }
                        else{
                            a[i - 1][j] = 'W';
                        }
                    if (j > 0)
                        if(a[i][j - 1] == 'R') {
                            cout << "NO\n";
                            return;
                        }
                        else{
                            a[i][j - 1] = 'W';
                        }
                    if (i < n - 1)
                        if( a[i + 1][j] == 'R') {
                            cout << "NO\n";
                            return;
                        }
                        else{
                            a[i + 1][j] = 'W';
                        }
                    if (j < m - 1) 
                        if( a[i][j + 1] == 'R') {
                            cout << "NO\n";
                            return;
                        }
                        else{
                            a[i][j + 1] = 'W';
                        }
                    cnt++;
                }
                
            }
        }
        // rep(i, n)
        //     rep(j, m)
        //         cerr << a[i][j] << " \n"[j == m - 1];
        if (cnt == (n * m))
            break;
        if(cnt==0)
            a[0][0]='W';
    }
    cout << "YES\n";
    rep(i, n){
        rep(j, m)
            cout << a[i][j];
        cout<<'\n';
    }

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}