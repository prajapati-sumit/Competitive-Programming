// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long           
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
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  100'005
#define left                leftone
#define right               rightone

auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
 
 
void solve(){
  
    int n,l,r;
    cin>>n>>l>>r;
    
    pii color[n+1];
    repe(i,n)
        color[i]={0,0};
    repe(i,n){
        int x;
        cin>>x;
        if(i<=l)
            color[x].ff++;
        else 
            color[x].ss++;
    }
    if(l<r)
        repe(i,n)
            swap(color[i].ff,color[i].ss);

    // repe(i,n)
    //     cout<<color[i].ff<<' '<<color[i].ss<<'\n';
    int to_transfer=abs(l-r)/2;
    int cnt=0;
    int matched=0;
    repe(i,n){
        int cl=color[i].ff,cr=color[i].ss;
        int can=(cl-cr)/2;
        if(can<=0)
            matched+=min(cl,cr);
        else{
            matched+=cr;
            assert(cl-can>=cr+can);
            if(cnt<to_transfer){
                if(cnt+can>to_transfer){
                    matched+=(to_transfer-cnt);
                    cnt=to_transfer;
                }
                else
                {
                    cnt+=can;
                    matched+=can;
                }
                
            }
        }



    }
    assert(cnt<=to_transfer);
    // cout<<to_transfer<<" "<<matched<<'\n';
    int ans=to_transfer+(n/2 - matched);
    cout<<ans<<'\n';
  
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}