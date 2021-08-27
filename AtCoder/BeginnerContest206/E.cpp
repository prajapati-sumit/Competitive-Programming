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
const int MX=1e6+2;

int LPF[MX];
int mobius[MX];
int ffR[MX];
int ffL[MX];
int l,r;

void init(){
    repe(i,MX-1)
        LPF[i]=i;
    for (int i = 2LL; i*i <MX; i++){
        if(LPF[i]==i){
            for(int j=i*i;j<MX;j+=i)
                LPF[j]=i;

        }
    }

    mobius[1]=1LL;
    for (int i = 2LL; i < MX; i++) {
        if (LPF[i / LPF[i]] == LPF[i])
            mobius[i] = 0;
        else
            mobius[i] = -1LL * mobius[i / LPF[i]];
        
    }
    for(int i=1LL;i<MX;i++)
        for(int j=i;j<MX;j+=i){
            ffR[j]+=(mobius[i]*(r/i));
            ffL[j]+=(mobius[i]*((j-1)/i));
        }

 
}
 

int count(int x){
    int divis=r/x;
    // cout<<divis<<" "
    // 7-(1+1)
    // 7 8 9 10 5-(5+())
    return (r-x+1LL)-(divis+ffR[x]-ffL[x]);
}
 
 
void solve(){
  
    int ans=0;
    cin>>l>>r;
    init();
    for(int x=max(2LL,l);x<=r;x++){
        // cout<<x<<" -> "<<ffL[x]<<" "<<ffR[x]<<" "<<count(x)<<'\n';
        ans+=count(x);
    }
    ans<<=1LL;
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
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}