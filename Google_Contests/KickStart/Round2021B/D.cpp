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
const int MX=2e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 1 
 
struct Node{
    ll id;
    ll L;
    ll A;
};
struct Query{
    ll id;
    ll w;  
};
ll segm[4*MX]; 
ll GCD[MX];
ll n,q;
vector<Node> v[MX];
vector<Query>queries[MX];
vector<ll> answers(MX);
ll query(ll cur,ll start,ll end,ll qs,ll qe){
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    ll mid=(start+end)>>1;
    ll A=query(2*cur,start,mid,qs,qe);
    ll B=query(2*cur+1,mid+1,end,qs,qe);
    ll res= __gcd(A,B);      //MERGING STEP  

    return res;
}
void update(ll cur,ll start,ll end,ll ind,ll val){
    if(start==ind && start==end){
        //DO UPDATE
        segm[cur]=val;
        return;
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    ll mid=(start+end)>>1;
    update(cur<<1,start,mid,ind,val);
    update((cur<<1)^1,mid+1,end,ind,val);
    //MERGING STEP
    segm[cur]=__gcd(segm[2*cur],segm[2*cur+1]);
}
 
ll cnt=0; 

void dfs(ll cur,ll par){
    for(auto &this_q:queries[cur]){
        ll g=query(1,1,MX-1,1,this_q.w);
        
        answers[this_q.id]=g;
    }
    for(auto child:v[cur]){
        if(child.id==par)
            continue;

        GCD[child.L]=child.A;
        update(1,1,MX-1,child.L,child.A);
        dfs(child.id,cur);
        GCD[child.L]=0;
        update(1,1,MX-1,child.L,0);
    }


}
void solve(){
  
    cin>>n>>q;
    ll x,y,l,a;
    repe(i,n)
        v[i].clear(),queries[i].clear();
    repe(i,n-1){
        cin>>x>>y>>l>>a;
        v[x].push_back(Node{y,l,a});  
        v[y].push_back(Node{x,l,a});  
    }
    repe(i,q){
        ll c,w;
        cin>>c>>w;
        queries[c].push_back(Query{i,w});
    }
    dfs(1,-1);
    repe(i,q)
        cout<<answers[i]<<" ";
    cout<<"\n";

    //reset
    rep(i,4*MX)
        segm[i]=0;
    rep(i,MX)
        GCD[i]=0;


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