//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define SZ(x)               ((int)x.size())
#define set_bits            __builtin_popcountll
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;


int cost(string &s){
    int n=s.length();
    int res=0;
    rep(i,n-1)
        res+=(s[i]==s[i+1]);
    return res;
}


void solve() {

    int n;
    cin>>n;
    string s;
    cin>>s;
    string res(n,'^');
    string best;
    int cnt=INF;
    if(s[0]=='?'){
        res[0]='B';
        FOR(i,1,n-1){
            if(s[i]=='?')
                res[i]='B'^'R'^res[i-1];
            else
                res[i]=s[i];
        }
        int tmp=cost(res);
        if(cnt>tmp){
            cnt=tmp;
            best=res;
        }

        res[0]='R';
        FOR(i,1,n-1){
            if(s[i]=='?')
                res[i]='B'^'R'^res[i-1];
            else
                res[i]=s[i];
        }
        tmp=cost(res);
        if(cnt>tmp){
            cnt=tmp;
            best=res;
        }
    }
    else{
        res[0]=s[0];
        FOR(i,1,n-1){
            if(s[i]=='?')
                res[i]='B'^'R'^res[i-1];
            else
                res[i]=s[i];
        }
        int tmp=cost(res);
        if(cnt>tmp){
            cnt=tmp;
            best=res;
        }
    }
    cout<<best<<'\n';

    // cout<<min(dp[n][0],dp[n][1])<<'\n';
    


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