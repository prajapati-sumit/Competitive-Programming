// AUTHOR: Sumit Prajapati      
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
#define MX                  200'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
struct Projects{
    int s;
    int e;
    int r;
};
Projects a[MX]; 
int n;
vector<int>dp(MX,-1);
int fn(int i){
    if(i>=n)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int s=a[i].s,e=a[i].e,rew=a[i].r;
    int ind=n,l=i,r=n-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(a[mid].s>e){
            ind=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    if(i+1==ind)
        return dp[i]=rew+fn(ind);
    return dp[i]=max(rew+fn(ind),fn(i+1));
}
void solve(){
  
    
    cin>>n;
    
    map<int,int>mp;
    int cnt=1;
    vector<int> cord;
    rep(i,n)
        cin>>a[i].s>>a[i].e>>a[i].r;       
    

    
    sort(a,a+n,[&](auto& x,auto& y){
        if(x.s==y.s)
            return x.e<y.e;
        return x.s<y.s;
    });
    // rep(i,n)
    //     cout<<a[i].s<<" "<<a[i].e<<'\n';
    int ans=fn(0);
    // rep(i,n)
    //     cout<<dp[i]<<" \n"[i==n-1];
    cout<<ans;
    
 
} 
 
 
int32_t main() {
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