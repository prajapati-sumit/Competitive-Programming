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
const int INF=1e18+;
const int MX=1e5+5;

 
 
 
 
void solve(){
  
    int n,m;
    cin>>n>>m;
    int skill;
    set<pii>s;
    repe(i,n){
        int l,r;
        cin>>l>>r;
        s.insert({l,0});
        s.insert({r,1});
    }
    s.insert({-INF,-1});
    s.insert({INF,-1});
    repe(i,n){
        cin>>skill;
        auto it=s.lower_bound({skill,1});
        auto lef=*prev(it);
        auto rig=*it;
        int left_best,right_best,here;
        if(lef.ss==-1)
            left_best=-1;
        else{
            if(left_best.ss==0)
                left_best=0;
            
            else
                left_best=abs(skill-lef.ff);
        }
        if(rig.ss==-1)
            right_best=-1;
        else{
            if(right_best.ss==1){
                right_best=0;
            }
            else
                right_best=abs(skill-rig.ff);
        }

        if(left_best>=right_best){
            here=left.ff;
            if(here==0)
                
            s.insert()
            s.erase()
        }
        else{

        }



            
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