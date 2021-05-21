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


const ll INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 1 
const ll tick=12*1e10;

 
const int three=3;
 
ll inp[three];

bool isvalid(ll dhr,ll dminute,ll dsec){
    ll hour=dhr/30;
    ll minute=dminute/6;
    ll sec=dsec/6;
    // cout<<hour<<" "<<minute<<" "<<sec<<'\n';

    ll newh=(hour*30 + minute/2 +sec/120);
    ll newm=(minute*6+sec/10);
    ll news=sec*6;
    // cout<<newh<<" "<<newm<<" "<<news<<'\n';
    return newh==dhr && newm==dminute && news==dsec;
}
void solve(){
    rep(i,three)
        cin>>inp[i];

    ll hour,minute,sec,n,total_sec=0;
    
    for(ll rot=0;rot<360;rot++){
        do{
        
        
            hour=(inp[0]/tick+rot)%360;
            minute=(inp[1]/tick+rot)%360;
            sec=(inp[2]/tick+rot)%360;
            if(isvalid(hour,minute,sec)){
                cout<<hour<<" "<<minute<<" _"<<sec<<" "<<(inp[2])<<'\n';
                n=(720-(inp[2]%720))%720;
                assert(n>=0);
                hour/=30;
                minute/=6;
                sec/=6;
                ll newh=(hour*30 + minute/2 +sec/120);
                ll newm=(minute*6+sec/10);
                ll news=sec*6;
                // cout<<newh<<" "<<newm<<" "<<news<<'\n';
                cout<<hour<<" "<<minute<<" "<<sec<<" ";
                cout<<n<<"\n";
                return;
            }
        
        
        }while(next_permutation(inp,inp+3));
    }
    

} 
void solve2(){
    ll A,B,C;
    cin>>A>>B>>C;
    ll iA=A,iB=A*12,iC=720*A;
    if(iA==0){
        iB=11;
        C=719;
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
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}