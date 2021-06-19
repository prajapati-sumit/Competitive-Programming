//~ author      : Sumit Prajapati
//~ mail ID     : sumitprajapati821@gmail.com
//~ codefoces   : sumitprajapati81, codechef: sumit141   
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define int                 long long           
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
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

string gl1,gl2,gl3;
 

int ans; 
int fillfor(string &s,string &G,int n){

    int res=0;
    int cnt=0;
    rep(i,n){
        if(s[i]=='?' || s[i]==G[i])
            cnt++;
        else{
            // cout<<cnt<<'\n';
            res+=(cnt*(cnt+1))/2;
            cnt=0;
        }
    }
    res+=(cnt*(cnt+1))/2;
    return res;

}
void solve(){
  
    string s;
    cin>>s;
    int n=s.length();
    int ques=0;
    rep(i,n)
        ques+=(s[i]=='?');
    if(ques==n){
        ques=(n*(n+1))/2;
        cout<<ques<<'\n';
        return;
    }
    ans=0;
    // cout<<ans<<'\n';
    ans+=fillfor(s,gl1,n);
    // cout<<ans<<'\n';
    ans+=fillfor(s,gl2,n);
    // cout<<ans<<'\n';
    ans-=fillfor(s,gl3,n);

    cout<<ans<<'\n';
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char cur='0';
    repe(i,2*MX){
        gl1.pb(cur);
        cur=cur^'1'^'0';
        gl2.pb(cur);
        gl3.pb('?');
    }
    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}