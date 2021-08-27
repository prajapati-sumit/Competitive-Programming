//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long
#define ld                  long double
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;

const ld inf = 1e-9;

ld v;


bool is_zero(ld& x){
    return x<inf;
}
void distribute(ld& a,ld& b,ld& x){
    if(is_zero(a)){
        b+=x;
        return;
    }
    else if(is_zero(b)){
        a+=x;
        return;
    }
    a+=x/2.0;
    b+=x/2.0;
}
void solve() {

    ld c, m, p;
    cin >> c >> m >> p >> v;
    ld ans=p;

    for(int i=1;i<=18;i++){
        int mask=(1<<i);
        ld here=0;
        rep(j,mask){
            ld cur=1,ct=c,mt=m,pt=p;
            rep(z,i){
                if(j&(1<<z)){
                    cur*=ct;
                    if(ct>v){
                        ct=ct-v;
                        distribute(mt,pt,v);
                    }
                    else if(!is_zero(ct)){
                        distribute(mt,pt,ct);
                        ct=0;
                    }
                    else
                        break;

                }
                else{
                    cur*=mt;
                    if(mt>v){
                        mt=mt-v;
                        distribute(ct,pt,v);
                    }
                    else if(!is_zero(mt)){
                        distribute(ct,pt,mt);
                        mt=0;
                    }
                    else
                        break;

                }
            }
            cur*=pt;
            // if(i==3)
            //     cout<<cur<<" "<<j<<'\n'; 
            here+=cur;
            // cout<<j<<" "<<cur<<" "<<pt<<"\n";
        }
        // cout<<i+1<<" "<<here<<'\n';
        ans+=(i+1)*here;
    }
    cout<<ans<<'\n';


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    cin >> t;
    cout << setprecision(9) << fixed;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}