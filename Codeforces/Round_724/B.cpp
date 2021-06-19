//~ author      : Sumit Prajapati
//~ mail ID     : sumitprajapati821@gmail.com
//~ codefoces   : sumitprajapati81, codechef: sumit141   
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
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
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

string s; 
 
bool one[26];
bool two[26][26];
bool three[26][26][26];

 
void solve(){
  
    int n;
    cin>>n;
    memset(one,0,sizeof(one));
    memset(two,0,sizeof(two));
    memset(three,0,sizeof(three));
    cin>>s;
    for(int len=1;len<=min(3,n);len++){
        for(int i=0;i<=(n-len);i++){
            if(len==1){
                one[s[i]-'a']=1;
            }
            if(len==2){
                two[s[i]-'a'][s[i+1]-'a']=1;
            }
            if(len==3){
                three[s[i]-'a'][s[i+1]-'a'][s[i+2]-'a']=1;
            }
        }
    }
    bool found=false;
    string temp;
    rep(i,26)
        if(!one[i]){
            found=true;
            temp+=char(i+'a');
            break;
        }
    if(found){
        cout<<temp<<'\n';
        return;
    }
    rep(i,26){
        rep(j,26){
            if(!two[i][j]){
                found=true;
                temp+=char(i+'a');
                temp+=char(j+'a');
                break;
            }
        }
        if(found)
            break;
    }
    if(found){
        cout<<temp<<'\n';
        return;
    }
    rep(i,26){
        rep(j,26){
            rep(k,26){
                if(!three[i][j][k]){
                    found=true;
                    temp+=char(i+'a');
                    temp+=char(j+'a');
                    temp+=char(k+'a');
                    break;
                }
            }
            if(found)
                break;
        }
        if(found)
            break;
    }
    cout<<temp<<'\n';
 
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