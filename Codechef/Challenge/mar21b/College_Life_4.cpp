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

const ll INF=1e15;
const ll MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
struct Point
{
    ll x;
    ll y;
}; 
 
vector<Point> P;
vector<pair<ll,ll>>dif;
ll N,E,H,A,B,C;
bool isvalid(Point R){
    bool flag=true;
    flag&=(2*R.x+R.y)>=3*N;
    if(!flag)
        return 0;
    flag&=(R.x+R.y)>=2*N;
    if(!flag)
        return 0;
    flag&=(3*R.x+2*R.y)<=6*N;
    if(!flag)
        return 0;
    flag&=(R.x>=0 && R.x<=E);
    if(!flag)
        return 0;
    flag&=(R.y>=0 && R.y<=H);
    return flag;
} 
ll evaluate(Point R){
    ll a=-3*N+2*R.x+R.y;
    ll b=-2*N+R.x+R.y;
    ll c=6*N-3*R.x-2*R.y;
    ll res=A*a+B*b+C*c;
    cout<<R.x<<" "<<R.y<<" -> ";
    cout<<a<<" "<<b<<" "<<c<<" "<<res<<'\n';
    return res;
}
 
ll brute(){
   
  
    
    ll c=6*N-3*E-2*H;
    ll a=-3*N+2*E+H;
    ll b=-2*N+E+H;
    if(a<0 || b<0){
        return -1;
        
    } 
   // cout<<E<<" "<<H<<'\n';
    ll ans=INF;
    for(ll i=0;i<=a;i++){
        for(ll j=0;j<=b;j++){
            ll k=N-i-j;
            double tm=timedif(time0,curtime)*1e-9;
            // if(tm>0.95){
            //     cout<<"Time Limit "<<" ";
            //     return;
            // }
            
            ll E_used=(2*i+k),H_used=(3*j+k);
            //cout<<i<<" "<<j<<" "<<k<<" : "<<E_used<<" "<<H_used<<" "<<ans<<'\n';
            if(k<0 )
                break;
            if(H_used>H || E_used>E)
                continue;
            ll cost=i*A+j*B+k*C;
            if(cost==17)cout<<i<<" "<<j<<" "<<k<<'\n';
            ans=min(ans,cost);
        }
    }
    return ans;
}
void fill(Point R){
    trav(dif){
        P.pb({R.x+el.ff,R.y+el.ss});
    }
}
void solve(){
  
    P.clear();
    cin>>N>>E>>H>>A>>B>>C;
    // N=rand()%MX+1;
    // E=rand()%MX;
    // H=rand()%MX;
    // A=rand()%MX+1;
    // B=rand()%MX+1;
    // C=rand()%MX+1;
    // cout<<N<<" "<<E<<" "<<H<<" "<<A<<" "<<B<<" "<<C<<":";
    

    P.pb({E,3*N-2*E});
    P.pb({E,2*N-E});
    fill({E,(6*N-3*E)/2});

    fill({(3*N-H)/2,H});
    P.pb({2*N-H,H});
    fill({(6*N-2*H)/3,H});

    P.pb({N,N});
    P.pb({E,H});
    P.pb({2*N,0});
    P.pb({0,3*N});

    ll ans=INF;
    //cout<<P.size()<<'\n';
    trav(P){
        if(isvalid(el)){
            ans=min(ans,evaluate(el));
        }

    }
    if(ans==INF)
        ans=-1;
    cout<<ans<<'\n';
    // ll ans2=brute();
    // cout<<ans2<<'\n';
    // if(ans!=ans2){
        
    //     cout<<" Found \n";
    // }
    // else
    //     cout<<" \n";

} 
 
//6 10 9 7 2 3: 17 18 Found:14:46 
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    for(ll i=0;i<=3;i++){
        for(ll j=0;j<=3;j++){
            dif.pb({i,j});
            dif.pb({i,-j});
            dif.pb({-i,j});
            dif.pb({-i,-j});
        }
    }
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
// 23696 24447 24649 11854 19337 13492:318476294
// 29321 22842 24580 2233 20058 6510:-1
// 4791 19451 21181 246 24645 12321:1178586
// 13343 22180 2055 31664 20787 10085:-1
// 10253 17930 20258 463 23135 12196:33948675
// 16621 4089 14215 27244 24071 913:-1
// 25173 9870 3140 2089 218 14174:-1
// 16636 12240 18101 1164 32104 3562:-1
// 29848 7069 27210 29753 28930 30109:-1
// 22231 1593 24140 17678 7886 5815:-1

