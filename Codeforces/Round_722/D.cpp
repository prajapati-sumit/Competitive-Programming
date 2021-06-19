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
const ll MDL=998244353;
#define MX                  100'0002


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 


ll trailing(ll n){
    ll cnt=0;
    while(n%2==0)
        n/=2,cnt++;
    return cnt;
}
ll LPF[MX+1];
ll factors(ll n){
    ll ans=1,prev=LPF[n];
    ll cnt=0;
    while(n>1){
        if(LPF[n]==prev){
            cnt++;
        }
        else{
            ans*=(cnt+1);
            cnt=1;
            prev=LPF[n];
        }
        n/=LPF[n];
    }
    ans*=(cnt+1);
    return ans;
}
 

void solve(){
  
    ll n;
    cin>>n;
    ll dp[n+1];
    dp[0]=1;
    ll sum=1;
    for(ll i=1;i<=n;i++){
  
        ll temp=factors(i)-1;
        dp[i]=(sum+temp)%MDL;
        sum=(sum+dp[i])%MDL;
    }   
    ll ans=dp[n]%MDL;
    cout<<dp[n]<<'\n';
    // repe(i,n)
    //     cout<<dp[i]<<'\n';
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    rep(i,MX-1)
        LPF[i]=i;
    for(ll i=2;i*i<=MX;i++){
        for(ll j=2*i;j<MX;j+=i)
            if(LPF[j]==j)
                LPF[j]=i;
    }
    int t=1;
    // cin>>t;
    // cout<<LPF[6]<<'\n';
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}