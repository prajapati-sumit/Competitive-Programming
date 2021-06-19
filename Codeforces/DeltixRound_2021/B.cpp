// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
// #define int                 long long           
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

int a[1002];
int cnt=0;
vector<pair<int,pii>>v; 
void change(int type,int i,int j){
    assert(cnt<=5000);
    v.pb({type,{min(i,j),max(i,j)}});
    cnt++;
    // cout<<type<<" "<<i<<" "<<j<<'\n';
    if(type==1)
        a[i]=a[i]+a[j];
    
    if(type==2)
        a[i]=a[i]-a[j];
} 
 
void solve(){
  
    int n;
    cin>>n;
    cnt=0;  
    v.clear();     
    repe(i,n)
        cin>>a[i];
    for(int i=1;i<=n;i+=2){
        change(1,i,i+1);
        change(2,i+1,i);
        change(2,i+1,i);
        change(1,i,i+1);
        change(2,i+1,i);
        change(2,i+1,i);
    }
    cout<<v.size()<<'\n';
    for(auto& el:v)
        cout<<el.ff<<" "<<el.ss.ff<<" "<<el.ss.ss<<'\n';

    // repe(i,n)
    //     cout<<a[i]<<" \n"[i==n];
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}