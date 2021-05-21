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
const int MX=2e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
struct Range{
    int l;
    int r;
    int i;    
};  
set<int>st;
int n,m,x,y;
int dist[MX];
Range To[MX],from[MX];
Range src,dest;
int res;


void fastscan(int &x)
{
    
    int c;
    x =0;
    c=getchar();
   
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    
}
bool iscommon(Range& A,Range& B){
   return (A.l<=B.r && B.l<=A.r);
}
void printRange(Range& P){
    cout<<"{ "<<P.i<<": "<<P.l<<" "<<P.r<<"} ";
}

void print_queue(queue<Range> q)
{
  while (!q.empty())
  {
    printRange(q.front());
    q.pop();
  }
  cout << '\n';
}

bool BFS(){

    queue<int>Q;
    repe(i,m){
        if(iscommon(from[i],src)){
            Q.push(i);
            dist[i]=1;
            st.erase(i);
            if(iscommon(To[i],dest)){
                res=dist[i];
                return true;
            }
        
        }
        
    }
   
    //print_queue(Q);
    while(!Q.empty()){

       
        int temp=Q.front();
        Q.pop();
        // if(iscommon(To[temp],dest)){
        //     res=dist[temp];
        //     return true;
        // }
        
        vector<set<int>::iterator> v;
        for (auto it=st.begin();it!=st.end();it++) {
            int el=*it;
            if(iscommon(from[el],To[temp])){
                dist[el]=1+dist[temp];
                Q.push(el);
                v.pb(it); 
                if(iscommon(To[el],dest)){
                    res=dist[el];
                    return true;
                }
                  
            }             
        }
        for(int i=(int)v.size()-1;i>=0;i--){
            st.erase(v[i]);
        }

    }
    
    return false;

}




void solve(){
   
    // cin>>n>>m>>x>>y;
    fastscan(n);
    fastscan(m);
    fastscan(x);
    fastscan(y);

    st.clear();
    int x1,x2,x3,x4;
    src={x,x,0};
    dest={y,y,0};
    for(int i=1;i<=m;i++){
        // cin>>x1>>x2>>x3>>x4;
        fastscan(x1);
        fastscan(x2);
        fastscan(x3);
        fastscan(x4);
        dist[i]=INF;
       
        st.insert(i);

        from[i].l=x1;
        from[i].r=x2;
        from[i].i=i;
       
        To[i].l=x3;
        To[i].r=x4;
        To[i].i=i;
       
    }
    if(x==y){
        cout<<"0\n";
        return;
    }
    // cout<<x<<"-> "<<y<<'\n';
    if(BFS()){
        cout<<res<<'\n';
    }   
    else
        cout<<"-1\n";
} 
 
 
int main() {
   
    srand(time(0)); 
    

    
   
    int t=1;
    fastscan(t);
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}