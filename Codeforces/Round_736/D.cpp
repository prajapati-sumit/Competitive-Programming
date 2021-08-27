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
const int MX=2e5+5;

 
int d[MX];
int a[MX];
int n;
int LOG[MX];
// #warning operating on array named 'a' of size n:1-base

const int MAXLOG=18;
int sparse[MX][MAXLOG];
void fillER(){
    for(int i=1;i<n;i++){
        sparse[i][0]=d[i];
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<n && i<n;i++){
            sparse[i][j]=__gcd(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        }
    }
}

int getGCD(int x,int y){
    if(x>y)
        return 0;
    int h=LOG[y-x+1];
    return __gcd(sparse[x][h],sparse[y-(1LL<<h)+1][h]);
}



 
void solve(){
  
    cin>>n;
    repe(i,n)
        cin>>a[i];

    repe(i,n-1)
        d[i]=abs(a[i+1]-a[i]);

    fillER();
    int ans=0;
    int l=1,r=1;
    int g=0;
    // repe(i,n-1)
    //     cout<<d[i]<<" \n"[i==n-1];
    while(r<n){
        while(r<n && getGCD(l,r)>1){
            r++;
        }
        // cout<<l<<" "<<r<<'\n';
        ans=max(ans,r-l+1);
        l++;
        // r=max(r,l);
    }
    cout<<ans+1<<'\n';


  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    LOG[1]=0;
    FOR(i,2,MX-1)
        LOG[i]=1+LOG[i/2];

    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}