//CODED BY SUMIT KUMAR PRAJAPATI
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 

map<pair<int,int>,bool>mp;
bool fn(int u,int v){
    if(mp.find({u,v})!=mp.end())
        return mp[{u,v}];
    cout<<u<<" "<<v<<'\n';
    if(u==v)
        return true;
    if(u>v)
        return false;
    bool res=false;
    for(int s=u;s;s=(s-1)&u){
        res|=fn(u+s,v);
        
    }
    return mp[{u,v}]=res;

}
 
 
 
 
void solve(){
  
   
    int ui,vi;
    
    cin>>ui>>vi;
    if(fn(ui,vi))
        cout<<"YES";
    else
        cout<<"NO";
    cout<<'\n';   
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}