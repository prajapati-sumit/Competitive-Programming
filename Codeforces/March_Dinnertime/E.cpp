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
 
 
 
int n,q;
vector<int> v[MX]; 
int subtree[MX];
int order[MX];
int parent[MX];
int segm[4*MX];
int LCA[MX][20];
int level[MX];

int dfs(ll node,ll par,ll lev){
    LCA[node][0]=par;
    level[node]=lev;
    subtree[node]=1;
    for(auto x:v[node])
        if(x!=par)
            subtree[node]+=dfs(x,node,lev+1);
    return subtree[node];
}
void init(){
    memset(LCA,-1,sizeof(LCA));
    dfs(1,-1,0);
    for(ll i=1;i<=19;i++){
        for(ll j=1;j<=n;j++){
            if(LCA[j][i-1]!=-1){
                ll par=LCA[j][i-1];
                LCA[j][i]=LCA[par][i-1];
            }
        }

    }
   

}
 
int getLCA(int a, int b){
    
    if(level[a]>level[b])
        swap(a,b);
    int d=level[b]-level[a];
    while(d>0){
        int jump=log2(d);
        b=LCA[b][jump];
        d-=(1<<jump);
    }
    if(a==b)
        return a;
    for(int i=19;i>=0;i--){
        if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i]))
            a=LCA[a][i],b=LCA[b][i];
    }
    return LCA[a][0];
}
void buildtree(int cur,int start,int end){
    if(start==end){
        segm[cur]=order[start];
        // cout<<cur<<" "<<order[start]<<'\n';
        return;
    }
    int mid=(start+end)>>1;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)+1,mid+1,end);
    segm[cur]=getLCA(segm[2*cur],segm[2*cur+1]);

}
int query(int cur,int start,int end,int qs,int qe){
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return -1;
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe);
    int B=query(2*cur+1,mid+1,end,qs,qe);
    if(A==-1)
        return B;
    if(B==-1)
        return A;
    return getLCA(A,B);
}

bool cmp(int x,int y){
    if(v[x].size()==v[y].size())
        return x<y;
    return v[x].size()<v[y].size();
} 
void solve(){
  
    cin>>n>>q;
    int x,y;
    repe(i,n-1)  
        cin>>x>>y,v[x].pb(y),v[y].pb(x);
    init();
    repe(i,n)
        order[i]=i;
    sort(order+1,order+n+1,cmp);
    // printar(order,1,n);
    // printar(subtree,1,n);
    // cout<<getLCA(5,7)<<'\n';
    buildtree(1,1,n);
    // repe(i,40)
    //     cout<<i<<"-> "<<segm[i]<<" \n";
    int ans;
    while(q--){
        cin>>x>>y;
        int l=x,r=x+y-1;
        ans=subtree[query(1,1,n,l,r)];
        cout<<ans<<'\n';
    }
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