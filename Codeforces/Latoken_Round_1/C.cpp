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
const int MX=4e5+5;

 
 
int n;
int parent[MX];

int find_set(int x){
    return parent[x]==x?x:parent[x]=find_set(parent[x]);
}
void merge(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
        parent[b]=a;
}
int bin_power(int a,int b,int md){
    int res=1;
    while (b){
        if (b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
}
void solve(){
    
    
    cin>>n;
    repe(i,n)
        parent[i]=i;
    int a[n+1],b[n+1];
    repe(i,n)
        cin>>a[i];
    repe(i,n)
        cin>>b[i];
    repe(i,n){
        merge(a[i],b[i]);
    }
    int ans=0;
    repe(i,n){
        ans+=(parent[i]==i);
    }
    ans=bin_power(2,ans,MD);
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
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}