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

 
 
struct Points{
    int x,y;
};
vector<Points>S,T; 
int n;
Points fn(int x,int y,int rot){
    if(rot==1){
        swap(x,y);
        x*=-1;
    }
    if(rot==2){
        x*=-1;
        y*=-1;
    }
    if(rot==3){
        swap(x,y);
        y*=-1;
    }
    return {x,y};
}

bool isvalid(vector<Points>&a,vector<Points>&b){
    int dx=a[0].x-b[0].x,dy=a[0].y-b[0].y;
    // for(auto &el:a)
    //     cout<<el.x<<" "<<el.y<<'\n';
    // cout<<'\n';
    for(int i=1;i<n;i++){
        int tx=a[i].x-b[i].x;
        int ty=a[i].y-b[i].y;
        if(tx==dx && ty==dy){

        }
        else
            return false;
    }
    return true;
}
void solve(){
  
    cin>>n;
    repe(i,n){
        int x,y;
        cin>>x>>y;
        S.pb({x,y});
    }

    repe(i,n){
        int x,y;
        cin>>x>>y;
        T.pb({x,y});
    }
    sort(all(T),[&](auto a,auto b){
        if(a.x==b.x)
            return a.y<b.y;
        return a.x<b.x;
    });
    vector<Points>v[4];

    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            v[i].pb(fn(S[j].x,S[j].y,i));
        }
    }
    

    for(int i=0;i<4;i++){
        sort(all(v[i]),[&](auto a,auto b){
            if(a.x==b.x)
                return a.y<b.y;
            return a.x<b.x;
        });
        if(isvalid(v[i],T)){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";

  
 
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