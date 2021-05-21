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
#define INF                 1'000'000'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  15


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
string s,e;
map<string,ll>mp;
map<string,ll>vis;
ll fun(string a){
    if(mp.find(a)!=mp.end())
        return mp[a];
    if(vis[a])
        return mp[a];
    vis[a]=1;

    // cout<<a<<"\n";
    if(a==e)
        return mp[a]=0;
    if(a.length()>=MX)
        return INF;
    if(a=="0")
        return mp[a]=INF;
    string temp1=a,temp2;
    temp1.pb('0');
    bool flag=true;
    rep(i,a.length()){
        if(a[i]=='0')
            flag=false;
        if(!flag)
            temp2.pb(a[i]^('1'^'0'));
    }
    if(temp2.size()==0)
        temp2.pb('0');

    return mp[a]=1+min(fun(temp1),fun(temp2));



} 

void solve(){
    mp.clear();
    cin>>s>>e; 
    // string a=s,temp2;
    // bool flag=true;   
    // rep(i,a.length()){
    //     if(s[i]=='0')
    //         flag=false;
    //     if(!flag)
    //         temp2.pb(s[i]^('1'^'0'));
    // }
    // cout<<temp2<<'\n';
    ll ans=fun(s);
    cout<<ans<<'\n';
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}