// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
// #define int                 long long           
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
  
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    bool ok=false;
    rep(i,n)
        if(s[i]=='1'){
            ok=true;
            break;
        }
    if(!ok){
        cout<<s<<'\n';
        return;
    }
    int cnt=0;
    while(true){
        if(m<=0)
            break;
        cnt=0;
        // cerr<<s<<"\n";
        string temp=s;
        for(int i=0;i<n;i++){
            
            if(temp[i]=='0'){
                if(i==0 && temp[i+1]=='1' ){
                    // cout<<"Ww\n";
                   s[i]='1';
                }
                else if(i==n-1 && temp[i-1]=='1')
                    s[i]='1';
                else{
                    if((temp[i-1]=='1' && temp[i+1]!='1') || (temp[i-1]!='1' && temp[i+1]=='1'))
                    {  
                      s[i]='1';
                    }
                }
            }
           
        }
        
        rep(i,n)
            cnt+=(s[i]=='1');
        if(cnt==n)
            break;
        m--;
    } 
    cout<<s<<"\n";
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}