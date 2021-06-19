// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  100'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
int X,W,E;
int D=60;

vector<char> my(D+1),his(D+1);
vector<char>moves{'P','R','S'};
int nax=61;
pair<double,int>dp[61][61][61];


double total=0;
void solve(){
  
    my.clear();
    his.clear();
    cin>>W>>E;
    rep(i,nax)
        rep(j,nax)
            rep(k,nax)
                dp[i][j][k]={-1,-1};
    fn(0,0,0);
    // cout<<dp[0][0][0].ff<<" "<<dp[0][0][0].ss<<'\n';
    int p=0,r=0,s=0;
    while(true){
        if(p+r+s==60)
            break;
        double PP=dp[p+1][r][s].ff;
        double PR=dp[p][r+1][s].ff;
        double PS=dp[p][r][s+1].ff;
        // cout<<p<<" "<<r<<" "<<s<<" "<<PP<<" "<<PR<<" "<<PS<<'\n';
        if(PP>=PR && PP>=PS){
            my.pb('P');
            p++;
        }
        else if(PR>=PP && PR>=PS){
            my.pb('R');
            r++;
        }
        else if(PS>=PR && PS>=PP){
            my.pb('S');
            s++;
        }
        else
            assert(false);
    }
    assert(my.size()==60);
    for(auto &el:my)
        cout<<el;
    cout<<'\n';
    // total+=dp[0][0][0].ff;
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(0));
    int t=1;
    cin>>t;
    cin>>X;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    // cout<<total<<'\n';
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}