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

 
 
 
int ar[501][501]; 
void solve(){

    int n,k;
    cin>>n>>k;
    if(k%2==0 && n%2==1){
        cout<<"-1\n";
        return;
    }
    // qk=n+e
    if(n==k){
        cout<<"? ";
        repe(i,n)
            cout<<i<<" ";
        cout<<'\n';
        int resp;
        cin>>resp;
        cout<<"! "<<resp;
        return;
    }
    int q=3;
    while((q*k-n)<0 || (q*k-n)%2==1 ){
        q++;
    }
    cout<<q<<" "<<k<<'\n';
    int e=(q*k-n);
    int cnt=1;
    queue<int>Q;

    
    for(int i=0;i<q;i++){
        for(int j=0;j<k;j++){
            ar[i][j]=cnt++;
            if(cnt>n)
                break;
        }
        if(cnt>n)
            break;
    }
    cout<<cnt<<'\n';
    cnt=1;
    int each=e/2;
    repe(i,e){
        cerr<<cnt<<" ";
        Q.push(cnt++);
        if(cnt>each)
            cnt=1;

    }
    cout<<'\n';
    for(int i=0;i<q;i++){
        vector<bool>vis(k+1,0);
        for(int j=0;j<k;j++){
            if(ar[i][j]==0){
                while(vis[Q.front()])
                {
                    Q.push(Q.front());
                    Q.pop();
                }
                ar[i][j]=Q.front();
                Q.pop();
                
                
            }
            cerr<<ar[i][j]<<" \n";
            vis[ar[i][j]]=true;
        }
    }
    // assert(Q.empty());
    int ans=0;
    rep(i,q){
        cout<<"? ";
        rep(j,k)
            cout<<ar[i][j]<<" \n"[j==k-1];
        int resp;
        cin>>resp;
        ans^=resp;
    }
    cout<<"! "<<ans<<'\n';

}   
 
 
int32_t main() {

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