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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const ll INF=1e12+2;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
vector<ll> cubes; 
 
ll sz;
void init(){

    ll cur=1;
    while(cur*cur*cur<=INF){
        cubes.pb(cur*cur*cur);
        cur++;
    }
    sz=cubes.size();

}

bool ispresent(ll key){
    ll l=0,r=sz-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(cubes[mid]==key)
            return true;
        else if (cubes[mid]>key){
            r=mid-1;
        }
        else 
            l=mid+1;
    }
    return false;
}
void solve(){

    
    ll x;
    cin>>x;
    for(auto cur : cubes){
        if(x>cur){
            ll second=x-cur;
            if(ispresent(second)){
                cout<<"YES\n";
                return;
            }
        }
    }  
    cout<<"NO\n";    
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    init();
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}