//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                     unsigned long long
#define ll                      long long
#define int                     long long
#define pii                     pair<int, int>
#define pll                     pair<ll, ll>
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define SZ(x)                   ((int)x.size())
#define set_bits                __builtin_popcountll
#define all(a)                  a.begin(),a.end()
#define trav(x,v)               for(auto &x:v)
#define rep(i,n)                for(int i=0;i<n;i++)
#define repe(i,n)               for(int i=1;i<=n;i++)
#define FOR(i,a,b)              for(int i=a;i<=b;i++)
#define curtime                 chrono::high_resolution_clock::now()
#define timedif(start,end)      chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define myshuffle(a,n)          FOR(i,1,n-1) swap(a[i], a[rand() % (i + 1)])
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)
#define ld                      long double

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e10;
const int MX = 1e5 + 5;
const ld eps=1e-7;
ld area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
  
/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{  
   /* Calculate area of triangle ABC */
   ld A = area (x1, y1, x2, y2, x3, y3);
  
   /* Calculate area of triangle PBC */ 
   ld A1 = area (x, y, x2, y2, x3, y3);
  
   /* Calculate area of triangle PAC */ 
   ld A2 = area (x1, y1, x, y, x3, y3);
  
   /* Calculate area of triangle PAB */  
   ld A3 = area (x1, y1, x2, y2, x, y);
    
   /* Check if sum of A1, A2 and A3 is same as A */
   return (abs(A-A1- A2- A3))<eps;
}
struct Point{
    int x;
    int y;

}P[301];
ld dist(Point A,Point B){
    ld di=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    di=sqrt(di);
    return di;
}
ld perimeter(Point a,Point b,Point c){
    ld res=dist(a,b)+dist(a,c)+dist(b,c);
    return res;
}


void solve() {

    int n;
    cin>>n;
    rep(i,n)
        cin>>P[i].x>>P[i].y;
    int sx,sy;
    cin>>sx>>sy;
    ld ans=INF;
    bool ok=false;
    rep(i,n){
        FOR(j,i+1,n-1){
            FOR(k,j+1,n-1){
                // cout<<P[i].x<<" "<<P[i].y<<" "
                // <<P[j].x<<" "<<P[j].y<<" "
                // <<P[k].x<<" "<<P[k].y<<"\n";
                if(isInside(P[i].x,P[i].y,P[j].x,P[j].y,P[k].x,
                    P[k].y,sx,sy))
                    ans=min(ans,perimeter(P[i],P[j],P[k]));
                    ok=true;

                }
        }

    }
    if(!ok)
        cout<<"IMPOSSIBLE\n";
    else
        cout<<ans<<"\n";


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<setprecision(8)<<fixed;
    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}