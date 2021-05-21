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

vector<int> cost[2501];

int p,q;
vector<int>ones,zeroes;
int dp[5001][5001];

int fn(int i,int j){
    if(i==p)
        return 0;
    if(j==q)
        return INF;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int op1=fn(i,j+1),op2=abs(ones[i]-zeroes[j])+fn(i+1,j+1);
    return dp[i][j]=min(op1,op2);
}

void solve(){
  
    int n;
    cin>>n;
    int a;
    memset(dp,-1,sizeof(dp));
    rep(i,n){
        cin>>a;
        if(a==1)
            ones.pb(i);
        else
            zeroes.pb(i);
    }
    p=ones.size();q=zeroes.size();
    int ans=fn(0,0);
    cout<<ans;

  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    // cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}