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
const int MX=3e5+5;
const int MD=1e9+7;
const int MDL=998244353;
const int BLK=550;
auto time0 = curtime;
#define TESTCASES 0 

struct Query{
    int id;
    int l;
    int r;     
}; 
bool cmp(Query X,Query Y){
    if(X.l/BLK!=Y.l/BLK)
        return X.l<Y.l;
    return X.r<Y.r;
}
int n,q,a[MX];
int here=0;
vector<int> indices[MX];
unsigned long long llrand() {
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
}
int getfreq(int x,int l,int r){
    int res=upper_bound(indices[x].begin(),indices[x].end(),r)-lower_bound(indices[x].begin(),indices[x].end(),l);

    return res;
}
int getx(int l,int r){
    int x=0;
    repe(i,40){
        int ind=(int)(llrand()%(r-l+1));
        x=max(x,getfreq(a[ind+l],l,r));
    }
    return x;
}
int get_answer(int x,int len){
    assert(x<=len);
    // cout<<x<<" "<<len<<"\n";
    if(x<=(len+1)/2)
        return 1;
    
    return 2*x-len;
}

 
void solve(){
    
    cin>>n>>q;
    repe(i,n){
        cin>>a[i];
        indices[a[i]].pb(i);
    }
    repe(i,q){
        int l,r;
        cin>>l>>r;
        cout<<get_answer(getx(l,r),r-l+1)<<"\n";
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
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}