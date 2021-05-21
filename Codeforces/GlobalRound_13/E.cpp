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
const int MX=2e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
set<int>s{1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418};
double phi=(1.0+sqrt(5))/2.0;
vector<int>v[MX];
set<int>subtree;
pair<pair<int,int>,int>edges;
int dfs(int cur,int par){
    int res=1;
    for(auto child:v[cur])
        if(child!=par)
            res+=dfs(child,cur);
    subtree.insert(res);
    return res;
} 
int prev(int n){
    return round((1.0*n)/phi);
}
bool fn(int n){
    bool res=true;
    int f1,f2;
    if(s.find(n)==s.end())
        return false;
    for(;;n=f1){
        if(n==1)
            return true;
        f1=prev(n);
        f2=n-f1;
        if(subtree.find(f1)==subtree.end() && subtree.find(f2)==subtree.end())
            return false;

    }

    return true;

} 
void solve(){
  
    int n;
    cin>>n;
    int x,y;
    repe(i,n-1)
        cin>>x>>y,v[x].pb(y),v[y].pb(x);
    dfs(1,-1);
    bool res=fn(n);
    cout<<(res?"YES":"NO");
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    //cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}