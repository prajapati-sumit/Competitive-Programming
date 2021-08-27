//~ author      : Sumit Prajapati
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
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

 
 
map<int,int>mp;
int ans=0;
void fn(int x,int y,bool flag,int other){
    if(abs(x+y)%2==1)
        return;
    // cout<<x<<" "<<(x+y)/2<<" "<<y<<" "<<flag<<"\n";
    if(!flag)
        ans+=(((x+y)/2)==other);
    else
        mp[(x+y)/2]++;
}
void solve(){
  
    int n=3;
    int a[4][4];
    mp.clear();
    ans=0;
    repe(i,n)
        cin>>a[1][i];
    cin>>a[2][1]>>a[2][3];
    repe(i,n)
        cin>>a[3][i];

    // rows
    fn(a[1][1],a[1][3],0,a[1][2]);
    fn(a[2][1],a[2][3],1,0);
    fn(a[3][1],a[3][3],0,a[3][2]);

    // columns
    fn(a[1][1],a[3][1],0,a[2][1]);
    fn(a[1][2],a[3][2],1,0);
    fn(a[1][3],a[3][3],0,a[2][3]);

    // diag
    fn(a[1][1],a[3][3],1,0);
    fn(a[1][3],a[3][1],1,0);

    int tmp=0;
    for(auto &el:mp)
        tmp=max(tmp,el.ss);
    ans+=tmp;
    cout<<ans<<'\n';
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}