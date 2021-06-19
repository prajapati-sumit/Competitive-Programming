// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define int                 long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

 
 
 
 
void solve(){
    
    int n,k;
    cin>>n>>k;
    pii a[n];
    rep(i,n)
        cin>>a[i].ff>>a[i].ss;
    sort(a,a+n,[&](auto x,auto y){return x.ff==y.ff?x.ss>y.ss:x.ff<y.ff;});
    int cur=k;
    int vil=0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(a[i].ff>cur+vil)
            break;
        cur-=(a[i].ff-vil);
        vil=a[i].ff;
        cur+=a[i].ss;
    }
    vil+=cur;
    cout<<vil<<'\n';
    return;

    for(int i=1;i<n;i++){
        a[i].ss+=a[i-1].ss;
    }
    // for(int i=0;i<n;i++)
    //     cout<<a[i].ff<<" "<<a[i].ss<<" \n";
    // cout<<'\n';
    while(cur>0){
        int canGo=vil+cur;
        int ind=-1,l=vil,r=n-1,mid;
        // cout<<canGo<<" "<<vil<<" ->";
        while(l<=r){
            mid=(l+r)>>1;
            if(a[mid].ff<=canGo){
                ind=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        // cout<<ind<<" ";
        int sum;
        if(ind==-1)
            sum=0;
        else
            sum=a[ind].ss-(vil==0?0:a[vil-1].ss);
        // cout<<sum<<'\n';
        cur=sum;
        vil=canGo;
    }
    cout<<vil<<'\n';
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    // cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}