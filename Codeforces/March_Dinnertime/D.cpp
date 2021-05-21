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
const int MX=1e2+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 

ll P[MX],R[MX]; 
map<pair<ll,ll>,ll>mp;
pair<ll,ll>val[MX];

ll fn(ll n,ll G){
    //cout<<n<<" "<<G<<" "<<cnt<<"-> \n";
    if(G<0)
        return -INF;
    if(n==0 || G==0)
        return 0;
    
    if(mp.find({n,G})!=mp.end())
        return mp[{n,G}];

    ll res=max(fn(n-1,G),val[n].ff+fn(n-1,G-P[n]));
    
    
    return mp[{n,G}]=res;

}

void solve(){
    
    ll n,G;
    cin>>n>>G;
    repe(i,n)
        cin>>P[i];
    repe(i,n)
        cin>>R[i],val[i].ff=R[i]-P[i],val[i].ss=P[i];
    sort(val+1,val+n+1);
    ll cnt=2;
    ll ans1=0,total1=-1;
    repe(i,n){
        repe(j,n)
        {
            if((val[i].ss+val[j].ss)<=G && (val[i].ff+val[j].ff)>ans1)
            {
                total1=(val[i].ss+val[j].ss);
                ans1=val[i].ff+val[j].ff;

            }
        }
    }
    ll ind=1;
    while(ind<=n && val[ind].ff<=1000 )ind++;
    ind--;
    ll ans2=fn(n,G),total2=-1;
    for(ll i=n;i>=1 && val[i].ff>1000;i--){
        if((val[i].ss)<=G )
        {
            ll cur_ans=fn(ind-1,G-val[i].ss)+val[i].ff;
            ans2=max(ans2,cur_ans);

        }
    }
    ll ans=max(ans1,ans2);
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