//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long           
#define ld                  long double           
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
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

 
 
 
 
void solve(){
  
    // TO learn ExpectedValue
    int n;
    cin>>n;
    ld dp[n+1][n+1][n+1];
    // dp[a][b][c]= probability to get to this state.
    int A=0,B=0,C=0;
    repe(i,n){
        int x;
        cin>>x;
        A+=(x==1);
        B+=(x==2);
        C+=(x==3);
    }
    memset(dp,0,sizeof(dp));
    for(int c=C;c>=0;c--){
        for(int b=B+C;b>=0;b--){
            for(int a=A+B+C;a>=0;a--){
                if(a+b+c>A+B+C)
                    continue;
                if(a>0){
                    ld pr=(ld)n/a;
                    dp[a-1][b][c]+=dp[a][b][c]+pr;
                    cout<<a<<" "<<b<<" "<<c<<" "<<dp[a-1][b][c]<<'\n';
                }
                if(b>0){
                    ld pr=(ld)n/b;
                    dp[a+1][b-1][c]+=dp[a][b][c]+pr;
                }
                if(c>0){
                    ld pr=(ld)n/c;
                    dp[a][b+1][c-1]+=dp[a][b][c]+pr;
                }
            }
        }
    }
    cout<<dp[0][0][0]<<'\n';

  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}