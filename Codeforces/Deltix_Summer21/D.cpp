//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define SZ(x)               ((int)x.size())
#define set_bits            __builtin_popcountll
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;


int hidden[]={-1,2,6,3,5,9,2,7};
int n=7;
int a[MX];

int cnt=0;
int query(string a,int i,int j){
    assert(cnt<=2*n);
    cnt++;
    cout<<a<<" "<<i<<" "<<j<<"\n";
    int resp;
    cin>>resp;
    return resp;
    if(a=="and")
        return (hidden[i]&hidden[j]);
    
    return (hidden[i]|hidden[j]);
}
void find(int x,int y,int z){
    int xpy=query("or",x,y)+query("and",x,y);
    int xpz=query("or",x,z)+query("and",x,z);
    int ypz=query("or",y,z)+query("and",y,z);
    a[x]=(xpy+xpz-ypz)/2;
    a[y]=(xpy+ypz-xpz)/2;
    a[z]=(xpz+ypz-xpy)/2;
}
void solve() {

    int k;
    cin>>n>>k;

    for(int i=1;i+2<=n;i+=3){
        int x=i,y=i+1,z=i+2;
        find(x,y,z); 
    }
    if(n%3==1){
        int xpy=query("or",n-1,n)+query("and",n-1,n);
        a[n]=xpy-a[n-1];
    }
    if(n%3==2){
        int xpy=query("or",n-2,n)+query("and",n-2,n);
        int xpz=query("or",n-2,n-1)+query("and",n-2,n-1);
        a[n]=xpy-a[n-2];
        a[n-1]=xpz-a[n-2];
    }
    // repe(i,n)
    //     cout<<a[i]<<" \n"[i==n];
    sort(a+1,a+n+1);
    cout<<"finish "<<a[k]<<'\n';


}


int32_t main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}