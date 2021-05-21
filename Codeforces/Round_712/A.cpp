// AUTHOR: SUMIT PRAJAPATI      
#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define TESTCASES 1

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 
bool ispalindrome(string s,int n){

    rep(i,n/2)
        if(s[i]!=s[n-1-i])
            return false;
    return true;
} 
 
 
void solve(){
  
    string s;
    cin>>s;
    int n=s.length();
    bool alla=true;
    rep(i,n){
        if(s[i]!='a'){
            alla=false;
            break;
        }

    }  
    if(ispalindrome(s,n)) {
        if(alla){
            cout<<"NO\n";
            return;
        }
        else{
            cout<<"YES\n";
            s.pb('a');
            cout<<s<<'\n';
            return;
        }
    }


    string res=s;
    s.pb('a');
    cout<<"YES\n";
    if(!ispalindrome(s,n+1))
        cout<<s<<'\n';
    else{
        res.insert(res.begin(),'a');
        cout<<res<<'\n';
    }


    

 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}