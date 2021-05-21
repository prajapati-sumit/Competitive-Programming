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
 
 
 
 
void solve(){
  
    ll n;
    cin>>n;
    ll u[n+1],s[n+1];
    repe(i,n)
        cin>>u[i];
    ll sum=0;
    repe(i,n){
        cin>>s[i];
        sum+=s[i];
    }
    map<ll,multiset<ll>>mp;
    repe(i,n)
        mp[u[i]].insert(s[i]);
    vector<ll> univ[n+1];
    for(auto el:mp)
        for(auto x:el.ss)
            univ[el.ff].pb(x);
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<univ[i].size();j++)
            univ[i][j]=(j==0)?univ[i][j]:univ[i][j]+univ[i][j-1];

    }
    vector <ll>ans(n+1,0);
    for(ll i=1;i<=n;i++){
        ll sz=univ[i].size();
        for(ll k=1;k<=sz;k++){
            ll to=sz%k;
            to--;
            if(to<0){
                ans[k]+=univ[i][sz-1];
                continue;
            }
            ans[k]+=univ[i][sz-1]-univ[i][to];
        }
        // repe(i,n)
        //     cout<<ans[i]<<" \n"[i==n];
    }
    repe(i,n)
        cout<<(ans[i])<<" ";
    cout<<endl;


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