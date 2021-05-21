// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  300'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?

struct Ball{
    int indx;
    int pos;
    char dir;
};
int n,m;
vector<Ball> odds,evens;
int ans[MX];
 
void helper(vector<Ball>& v){

    vector<Ball>here;
    for(auto el:v){
        if(el.dir=='R')
            here.pb(el);
        else
        {
            if(here.size() && here.back().dir=='R')
            {
                int fir=here.back().indx,sec=el.indx;
                int time=abs(here.back().pos-el.pos)/2;
                here.pop_back();
                ans[fir]=time;
                ans[sec]=time;
            }
            else
                here.pb(el);
        }
    }
    int sz=here.size(),lastR=-1,lastL=-1;
    for(int i=0;i+1<sz;i+=2){
        if(here[i].dir=='R' ){
            lastR=i;
            break;
        }
        if(here[i+1].dir=='R'){
            lastR=i+1;
            break;
        }
        int fir=here[i].indx,sec=here[i+1].indx;
        int time=(here[i+1].pos+here[i].pos)/2;
        ans[fir]=time;
        ans[sec]=time;

    }
    for(int i=sz-1;i>=1;i-=2){
        if(here[i].dir=='L' ){
            lastL=i;
            break;
        }
        if(here[i-1].dir=='L'){
            lastL=i-1;
            break;
        }
        int fir=here[i].indx,sec=here[i-1].indx;
        int time=m-(here[i].pos+here[i-1].pos)/2;
        ans[fir]=time;
        ans[sec]=time; 
    }
    if(lastL!=-1 && lastR!=-1 && lastL%2==0 && (sz-lastR)&1){
        int fir=here[lastL].indx,sec=here[lastR].indx;
        int p1=here[lastL].pos,p2=here[lastR].pos;
        assert(p2>p1);
        int time=m-(p2-p1)/2;
        ans[fir]=time;
        ans[sec]=time; 
    }



} 
void solve(){
  
    cin>>n>>m;
    odds.clear();
    evens.clear();
    int a[n+1];
    repe(i,n)cin>>a[i];
    repe(i,n){
        char ch;
        cin>>ch;
        if(a[i]&1)
            odds.pb(Ball{i,a[i],ch});
        else
            evens.pb(Ball{i,a[i],ch});
    }
    repe(i,n)
        ans[i]=-1;
    sort(all(odds),[](auto x,auto y){return x.pos<y.pos;});
    sort(all(evens),[](auto x,auto y){return x.pos<y.pos;});
    helper(odds);
    helper(evens);
    repe(i,n)
        cout<<ans[i]<<" \n"[i==n];

  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}