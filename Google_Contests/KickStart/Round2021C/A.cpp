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
 
 
string s; 
ll n,k,temp; 
ll dp[MX][30];
ll bin_power(ll a,ll b,ll md){
    ll res=1;
    while (b){
        if (b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
}
ll fn(ll cur,ll ch){

    // cerr<<cur<<" "<<ch<<'\n';
    if(dp[cur][ch]!=-1)
        return dp[cur][ch];
    if(ch>s[cur]-'a' )
        return 0;
    if(cur==temp)
        return dp[cur][ch]=1;
    

    ll res=0;
    if(ch==s[cur]-'a'){
        rep(i,k)
            res=(res+fn(cur+1,i))%MD;
    }
    else if(ch<s[cur]-'a'){
        res=bin_power(k,temp-cur,MD); 
    }
    else
        assert(false);
    return dp[cur][ch]=res;
    
}
void solve(){
  
    cin>>n>>k;  
    cin>>s;
    temp=(n&1)?n/2:n/2-1;
    ll ans=0;
    bool can=true;
    memset(dp,-1,sizeof(dp));
    rep(i,k)
        ans=(ans+fn(0,i))%MD;
    bool ok=true;
    ll cnt=0;
    ll len=(n+1)/2;
    string t1=s.substr(0,len),t2=s.substr(n/2,len);
    reverse(all(t1));
    // cout<<t1<<" "<<t2<<'\n';
    rep(i,len){
        if(t1[i]<t2[i])
            break;
        else if(t1[i]>t2[i]){
            ok=false;
            break;
        }
        else cnt++;
    }
    if(!ok || cnt==len)
        ans=(ans-1+MD)%MD;
    cout<<ans<<'\n';
    // rep(i,n/2+1)
    //     rep(j,k)
    //         cout<<dp[i][j]<<" \n"[j==k-1];
    // cout<<'\n';

} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}