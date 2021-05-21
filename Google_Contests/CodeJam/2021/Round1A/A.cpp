// AUTHOR: SUMIT PRAJAPATI      
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
#define all(a) a.begin(),a.end()
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()


const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 1 
 
 
bool islessequal(string s1,string s2){
    if(s1.length()<s2.length())
        return true;
    else if(s1.length()>s2.length())
        return false;
    int n=s1.length();
    rep(i,n)
        if(s1[i]<s2[i])
            return true;
        else if (s1[i]>s2[i])
            return false;
    return true;

} 
void helper(string &his,string &my){
    int mylen=my.length(),hislen=his.length();
    if(mylen>hislen)
        return;
    bool alreadygreater=false,alreadyless=false;
    rep(i,mylen){

        if(my[i]>his[i]){
            alreadygreater=true;break;
        }
        if(my[i]<his[i]){
            alreadyless=true;break;
        }
    }
    if(alreadygreater){
        while(my.length()<his.length())
            my.pb('0');
        return;
    }
    if(alreadyless){
        while(my.length()<=his.length())
            my.pb('0');
        return;
    }
    bool allnine=true;
    FOR(i,mylen,hislen-1){
        if(his[i]!='9'){
            allnine=false;break;
        }
    }
    if(allnine){
        while(my.length()<=his.length())
            my.pb('0');
        return;
    }
    FOR(i,mylen,hislen-1)
        my.pb(his[i]);
        
    for(int i=hislen-1;i>=mylen;i--)
        if(my[i]!='9'){
            my[i]+=1;
            return;
        }
        else
            my[i]='0';
    

} 

void solve(){
    ll n;
    cin>>n;
    ll a[n+1];
    string s[n+1];
    repe(i,n){
        cin>>a[i];
        s[i]=to_string(a[i]);
    }
    ll ans=0;
    FOR(i,2,n){
        string temp=s[i];
        helper(s[i-1],s[i]);
        ans+=s[i].length()-temp.length();
    }
    // repe(i,n)
    //     cout<<s[i]<<" ";
    // cout<<"\n";
    cout<<ans<<"\n";


} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}