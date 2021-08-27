// AUTHOR: SUMIT PRAJAPATI      
#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll>  pii;
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
#define TESTCASES 1

const ll INF=1e9;
const ll MX=1e6;
const ll MD=1e9+7;
const ll MDL=998244353;
auto time0 = curtime;
const ll nax=1e3+2;


string s;
ll n;


void simulate(){
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<float> distr(0, 1) ;   
    float total=0;
    repe(i,MX){
        float x1=distr(eng),x2=distr(eng),x3=distr(eng),x4=distr(eng);
        float res=max(x1,min(x3,x4));
        total+=res;
    }    
    total/=MX;
    cout<<total<<'\n';
    // max(min(x,x),max(x,x));
    //
} 
 
 
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    ll sz1=a.size(),sz2=b.size();
    vector<ll> res(sz1+sz2,0);

    rep(i,sz1){
        rep(j,sz2){
            res[i+j]+=a[i]*b[j];
        }
    }
    return res;

}

void oneminusx(vector<ll>& v){
    for(ll i=0;i<v.size();i++)
        v[i]=-v[i];
    v[0]+=1;
}
vector<ll> evaluate(ll &ind,bool ineq){
    vector<ll> cur{0,0};

    if(s[ind]=='x'){
        if(ineq){
            cur[0]=1;
            cur[1]=-1;
        }
        else{
            cur[1]=1;
        }
        return cur;  
    }

    if(s[ind]=='M'){
        if(ineq){
            ind++;
            cur=evaluate(ind,ineq^1);
            ind++;
            cur=multiply(cur,evaluate(ind,ineq^1));
            oneminusx(cur);
        }
        else{
            ind++;
            cur=evaluate(ind,ineq);
            ind++;
            cur=multiply(cur,evaluate(ind,ineq));
        }
    }
    else{
        if(ineq){
            ind++;
            cur=evaluate(ind,ineq);
            ind++;
            cur=multiply(cur,evaluate(ind,ineq));
        }
        else{
            ind++;
            cur=evaluate(ind,ineq^1);
            ind++;
            cur=multiply(cur,evaluate(ind,ineq^1));
            oneminusx(cur);
        }

    }
    
    return cur;
}
void solve(){

    cin>>s;
    n=s.length();
    ll ind=0;
    double ans=0;
    vector<ll> res=evaluate(ind,1);
    for(ll i=0;i<res.size();i++){
        ans+=((1.0*res[i])/(i+1));
    }
    printf("%0.9f\n",ans);
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
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}