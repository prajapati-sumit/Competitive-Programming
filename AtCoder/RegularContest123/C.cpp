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


int to_int(string x){
    int res=0;
    for(auto &el:x)
        res=(10*res)+el-'0';
    return res;
}
int calc(int x){
    string res=to_string(x);
    int sz=res.size();
    if(res[0]>'3'){
        rep(i,sz)
            res[i]='3';
    }
    int i=0;
    while(i<sz && res[i]>='1' && res[i]<='3'){
        i++;
    }
    if(i!=sz){
        if(res[i]=='0'){
            res[i-1]--;
            FOR(j,i,sz-1)
                res[j]='3';
        }
        else{
            FOR(j,i,sz-1)
                res[j]='3';
        }
        
    }
    return to_int(res);
} 
int fn(int n){
    if(n==0)
        return 0;
    int best=calc(n);
    cout<<n<<" "<<best<<" \n";
    return 1+fn(n-best);
} 
bool isvalid(int x){
    string res=to_string(x);
    for(auto &el:res)
        if(el!='1' && el!='2' && el!='3')
            return false;
    return true;
}
 
void solve(){
  
    int n;
    cin>>n;
    int max_n=1000;
    int dp[max_n+1];
    dp[0]=0;
    repe(i,max_n){
        if(isvalid(i)){
            dp[i]=1;
            continue;
        }
        int here=INF;
        for(int j=1;j<i;j++){
            if(isvalid(j) && i-j>0)
                here=min(here,dp[i-j]);
        }
        dp[i]=1+here;
    }
    repe(i,max_n){
        if(dp[i]>4)
            cout<<i<<"-> "<<dp[i]<<'\n';
    }

 
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