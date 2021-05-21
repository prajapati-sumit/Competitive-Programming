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
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 
 
 
bool check(string s){
    stack<char>st;
    trav(s){
        if(el=='(')
            st.push(el);
        else
            if(!st.empty() && st.top()=='(')
                st.pop();
            else
                st.push(')');

    }
    return st.empty();
}
void solve(){
  
    string s;
    cin>>s;
    int n=s.length();
    if(s[0]==s[n-1]){
        cout<<"NO\n";
        return;
    }
    string s1=s,s2=s;
    char extra=('A'^'B'^'C'^s[0]^s[n-1]);

    rep(i,n){
        if(s[i]==s[0]){
            s1[i]='(';
            s2[i]='(';
        }
        else if(s[i]==s[n-1]){
            s1[i]=')';
            s2[i]=')';
        }
        else{
            s1[i]='(';
            s2[i]=')';
        }
    }
    bool flag=check(s1)|check(s2);
    if(flag)
        cout<<"YES\n";
    else cout<<"NO\n";

 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}