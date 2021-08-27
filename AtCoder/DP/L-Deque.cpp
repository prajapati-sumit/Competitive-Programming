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
const int INF=1e15;
const int MX=1e5+5;

int a[3001];
pii dp[3001][3001][2];
pii fn(int l,int r,bool turn){
    if(l>r)
        return {0,0};
    // minimize
    if(dp[l][r][turn].ff>-INF)
        return dp[l][r][turn];
    pii res;
    if(turn){
        pii temp1=fn(l+1,r,turn^1);
        pii temp2=fn(l,r-1,turn^1);
        int X1=temp1.ff,X2=temp2.ff;
        int Y1=a[l]+temp1.ss,Y2=a[r]+temp2.ss;
        if(X1-Y1<X2-Y2){
            res={X1,Y1};
        }
        else
            res={X2,Y2}; 
    }
    //maximize 
    else{
        pii temp1=fn(l+1,r,turn^1);
        pii temp2=fn(l,r-1,turn^1);
        int X1=a[l]+temp1.ff,X2=a[r]+temp2.ff;
        int Y1=temp1.ss,Y2=temp2.ss;
        if(X1-Y1>X2-Y2){
            res= {X1,Y1};
        }
        else
            res= {X2,Y2};


    }
    return dp[l][r][turn]=res;
} 
 
 
void solve(){
  
    int n;
    cin>>n;
    repe(i,n)
        cin>>a[i];
    repe(i,n)
        FOR(j,i,n)
            dp[i][j][0]={-INF,0},dp[i][j][1]={-INF,0};
    pii ans=fn(1,n,0);
    // cout<<ans.ff<<" "<<ans.ss<<'\n';
    cout<<ans.ff-ans.ss<<'\n';
 
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