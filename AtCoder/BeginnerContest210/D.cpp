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

const int MX=1e5+5,MAXLOG=18;
int sparsemax[MX][MAXLOG];
void fill(){
    for(int i=1;i<=n;i++){
        sparsemax[i][0]=a[i];
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparsemax[i][j]=max(sparsemax[i][j-1],sparsemax[i+(1<<(j-1))][j-1]);
        }
    }
}

int getmin(int x,int y){
    if(x>y)
        return INF;
    int h=(int)log2(y-x+1);
    return min(sparsemin[x][h],sparsemin[y-(1<<h)+1][h]);
}

int getmax(int x,int y){
    if(x>y)
        return -INF;
    int h=(int)log2(y-x+1);
    return max(sparsemax[x][h],sparsemax[y-(1<<h)+1][h]);
}
 
 
int n,m;

void solve(){
  
    int n,m,c;
    cin>>n>>m>>c;
    int a[n+1][m+1];
    repe(i,n)
        repe(i,m)
            cin>>a[i][j];
    
    // (i,j)
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}