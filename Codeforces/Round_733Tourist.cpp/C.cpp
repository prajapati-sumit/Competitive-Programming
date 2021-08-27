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

 
 
 
 
void solve(){
  
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    repe(i,n)
        cin>>a[i];
    repe(i,n)
        cin>>b[i];
    sort(a+1,a+n+1,greater<int>());
    sort(b+1,b+n+1,greater<int>());
    int k=n-n/4;
    int sumA=0,sumB=0;
    for(int i=1;i<=k;i++){
        sumA+=a[i];
        sumB+=b[i];
    }   
    if(sumA>=sumB){
        cout<<"0\n";
        return;
    }   
    vector<int>bestA(n+1,0),bestB(n+1,0);
    repe(i,n){
        bestA[i]=bestA[i-1]+a[i];
        bestB[i]=bestB[i-1]+b[i];
    }
    int ans=-1;
    int l=0,r=MX,mid;
    while(l<=r){
        mid=(l+r)>>1;
        
        int kt=(n+mid)-(n+mid)/4;
        int rem=max(0LL,kt-mid);
        assert(kt-mid<=n);
        int suma=100*mid+bestA[rem],sumb=bestB[min(n,kt)];
        // if(mid<=10)
        //     cerr<<suma<<" "<<sumb<<" "<<mid<<'\n';
        if(suma>=sumb){
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    assert(ans!=-1);
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
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}