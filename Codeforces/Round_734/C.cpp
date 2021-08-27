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
const int MX=2e5+5;

 
int freq[MX][5]={0};
int n;

int doit(int ind,vector<string>& v,int main_freq[]){

    
    vector<pii>now;
    repe(i,n){
        int cur=0,rest=0;
        rep(j,5)
            if(j==ind)
                cur+=freq[i][j];
            else
                rest+=freq[i][j];
        now.pb({cur,rest});
    }
    sort(all(now),[&](auto p,auto q){
        if(p.ff-p.ss==q.ff-q.ss){

            if(p.ss==q.ss)
                return p.ff<q.ff;
            return p.ss<q.ss;
           
        }
        return p.ff-p.ss<q.ff-q.ss;
    });
    int cur=0,rest=0,i=0;
    rep(j,5){
        if(j==ind){
            cur+=main_freq[j];
        }
        else{
            rest+=main_freq[j];
        }
    }
    int ans=n;
    while(cur<=rest){
        if(i>=now.size())
            return 0;
        if(ans==0)
            break;
        // cout<<ind<<" "<<cur<<" "<<rest<<" "<<ans<<"\n";
        cur-=now[i].ff;
        rest-=now[i].ss;
        i++;
        ans--;
    }
    // cout<<ind<<" "<<ans<<'\n';
    return ans;
}
 
void solve(){
  
    cin>>n;

    vector<string>v(n+1);
    memset(freq,0,sizeof(freq));
    int main_freq[5]={0};
    repe(i,n){
        cin>>v[i];
        for(auto &el:v[i]){
            main_freq[el-'a']++;
            freq[i][el-'a']++;
        }
    }     
    int ans=0;
    rep(i,5){
        if(main_freq[i])
        ans=max(ans,doit(i,v,main_freq));
    }
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
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}