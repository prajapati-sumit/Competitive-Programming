//CODED BY SUMIT KUMAR PRAJAPATI
#include <bits/stdc++.h>
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
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=2e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
 
int freq[MX][26];
 
void solve(){
  
    string s;
    cin>>s;
    vector<pair<char,int>> v;
    int n=s.length();
    //cout<<n<<"\n";
    rep(i,n){
        int cur=s[i]-'a';
        freq[i][cur]=1;
    }
    // rep(i,26){
    //     cout<<char(i+'a')<<": ";
    //     rep(j,n){
            
    //         cout<<freq[j][i]<<" ";
    //     }
    //     cout<<'\n';
    // }
    for(int i=n-2;i>=0;i--){
        repe(j,26){
            freq[i][j]+=freq[i+1][j];
        }
    }
    rep(i,n-2){
        if(s[i]==s[i+1] && s[i+1]!=s[i+2])
        {
            v.push_back({s[i],i+2});
        }
    }
    int sz=v.size();
    ll ans=0;
    // rep(i,26){
    //     cout<<char(i+'a')<<": ";
    //     rep(j,n){
            
    //         cout<<freq[j][i]<<" ";
    //     }
    //     cout<<'\n';
    // }
    char lastc='$';
    int lasti;
    for(int i=sz-1;i>=0;i--){
        char ch=v[i].ff;
        int ind=v[i].ss,temp;
        if(lastc==ch || lastc=='$'){
            temp=n-ind-freq[ind][ch-'a'];
        }
        else{
            //cout<<ind<<" "<<lasti<<'\n';
            temp=n-ind-freq[ind][ch-'a']+freq[lasti][ch-'a'];

        }
        ans+=temp;
        //cout<<ch<<" : "<<ind<<" "<<temp<<'\n';
        lastc=ch;
        lasti=ind;
    }
    cout<<ans<<'\n';
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    //cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}