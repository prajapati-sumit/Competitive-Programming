//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long           
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

 
int a[55][55];
int n,m;

struct Node{
    int x1,y1,x2,y2;
};
vector<Node>ans; 
void query(int x1,int y1,int x2,int y2){
    // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<'\n';
    ans.pb({x1,y1,x2,y2});
    swap(a[x1][y1],a[x2][y1]);
    swap(a[x1][y2],a[x2][y2]);
} 
int count_inv(int x){
    int cnt=0;
    repe(i,n){
        FOR(j,i+1,n)
            cnt+=(a[i][x]>a[j][x]);
    }
    return cnt;
} 

void solve(){
  
    cin>>n>>m;
    ans.clear();
    // pos[j][i]=row-number of i in jth column
    int pos[m+1][n+1];
    repe(i,n)
        repe(j,m){
            cin>>a[i][j];
            pos[j][a[i][j]]=i;
        }

    int inv_cnt=0;
    repe(j,m)
        inv_cnt+=count_inv(j);
    if(inv_cnt&1){
        cout<<"-1\n";
        return;
    }
    repe(j,m-1){
        repe(i,n){
            int cur=a[i][j];
            if(cur==i)
                continue;
            query(i,j,pos[j][i],m);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto &el:ans)
        cout<<el.x1<<" "<<el.y1<<" "<<el.x2<<" "<<el.y2<<'\n';
    // repe(i,n)
    //     repe(j,m)
    //         cout<<a[i][j]<<" \n"[j==m];


 
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