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
const int MX=5e4+5;

int a[MX][6]; 

int n;

bool check(int ind){
    int ans[n+1]={0};
    repe(j,5){
        repe(i,n){
            if(i==ind)
                continue;
            if(a[i][j]>a[ind][j])
                ans[i]++;
        }
    }
    bool ok=true;
    repe(i,n){
        // cout<<i<<" "<<ans[i]<<'\n';
        if(i!=ind && ans[i]<3){
            ok=false;
            break;
        }

    }
    return ok;
} 
 
void solve(){
  
    cin>>n;
    
    repe(i,n)
        repe(j,5){
            cin>>a[i][j];           
        }

    int order[n+1];
    repe(i,n){
        order[i]=i;
    }
    sort(order+1,order+n+1,[&](int p,int q){
        vector<int>tmp1(a[p]+1,a[p]+5+1);
        vector<int>tmp2(a[q]+1,a[q]+5+1);
        int cnt1=0,cnt2=0;
        rep(j,5){
            if(tmp1[j]<tmp2[j]){
                cnt1++;
            }
            else if(tmp1[j]>tmp2[j])
                cnt2++;
        }
        return cnt1>cnt2;
    });
    repe(i,min(n,31)){
        
        if(check(order[i])){
            cout<<order[i]<<"\n";
            return;
        }
    }
    cout<<"-1\n";

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