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


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
int n;
string s;

void B1(int alice,int bob){
    
    bool ok=true;
    int cnt0=0;
    rep(i,n){
        if(s[i]=='0')
            ok=false;
        cnt0+=(s[i]=='0');
    }
    if(n%2==1 && s[n/2]=='0'){
        alice+=1;
        bob+=cnt0-1;
    }
    else
        alice+=cnt0;
    cout<<alice<<" "<<bob<<' ';
    if(alice==bob)
        cout<<"DRAW\n";
    else if(alice>bob)
        cout<<"BOB\n";
    else
        cout<<"ALICE\n";
 
} 
 
void solve(){
  
    cin>>n;
    cin>>s;  
    int dif=0;
    rep(i,n/2){
        if(s[i]!=s[n-i-1]){
            dif++;
            if(s[i]=='0')
                s[i]='1';
            else
                s[n-i-1]='1';
        }
    }
    if(n%2==1 & s[n/2]=='0')
    B1(alice,bob);
  
 
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