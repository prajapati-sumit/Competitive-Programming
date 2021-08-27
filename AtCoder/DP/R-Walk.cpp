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

 
int a[51][51];
int n;
int I[51][51]; 
void multiply(bool res){
    int temp[n+1][n+1];
    memset(temp,0,sizeof(temp));
    repe(i,n)
        repe(j,n)
            repe(k,n)
                temp[i][j]=(temp[i][j]+(res?I[i][k]:a[i][k])*a[k][j])%MD;
    repe(i,n)
        repe(j,n)
            if(res)
                I[i][j]=temp[i][j];
            else
                a[i][j]=temp[i][j];

}
void matrix_exp(int k){

    while(k){
        if(k&1)
            multiply(1);
        k>>=1;
        multiply(0);
    }
}
void solve(){
  
    int k;
    cin>>n>>k;
    repe(i,n)
        repe(j,n)
            cin>>a[i][j];
    repe(i,n)
        I[i][i]=1;


    matrix_exp(k);
    int ans=0;
    repe(i,n)
        repe(j,n)
            ans=(ans+I[i][j])%MD;
    cout<<ans<<'\n';

    
 
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