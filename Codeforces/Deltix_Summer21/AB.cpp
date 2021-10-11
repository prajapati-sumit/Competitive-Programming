//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long
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
const int INF = 1e16;
const int MX = 1e5 + 5;

int a[MX];
vector<int>odd;
vector<int>ev;

int n;
int one_first(){
    int cur=1;
    int o=0,e=0;
    vector<int>tmp(n+1);
    repe(i,n)
        tmp[i]=a[i];

    int ans=0;
    repe(i,n){
        if(tmp[i]!=cur){
            if(cur==0){
                while(ev[e]<i)
                    e++;
                swap(tmp[i],tmp[ev[e]]);
                ans+=abs(i-ev[e]);
                e++;
            }
            else{
                while(odd[o]<i)
                    o++;

                swap(tmp[i],tmp[odd[o]]);
                ans+=abs(i-odd[o]);
                o++;
            }
        }
        
        cur^=1;
    }
    return ans;

}
int zer_first(){

    int cur=0;
    int o=0,e=0;
    vector<int>tmp(n+1);
    repe(i,n)
        tmp[i]=a[i];

    int ans=0;
    repe(i,n){
        if(tmp[i]!=cur){
            if(cur==0){
                while(ev[e]<i)
                    e++;
                // cout<<i<<" "<<ev[e]<<'\n';
                swap(tmp[i],tmp[ev[e]]);
                ans+=abs(i-ev[e]);
                e++;
            }
            else{
                while(odd[o]<i)
                    o++;
                ans+=abs(i-odd[o]);
                swap(tmp[i],tmp[odd[o]]);
                o++;
            }
        }
        // repe(j,n)
            // cout<<tmp[j]<<" \n"[j==n];
        // if(i==5)
            // return -1;
        cur^=1;
    }
    return ans;
}

void solve() {

    cin>>n;
    odd.clear();
    ev.clear();
    repe(i,n){
        int x;
        cin>>x;
        if(x%2)
            odd.pb(i);
        else
            ev.pb(i);
        a[i]=x%2;
    }
    if(n==1){
        cout<<"0\n";
        return;
    }
    if(abs(SZ(odd)-SZ(ev))>1){
        cout<<"-1\n";
        return;
    }
    int op1=INF,op2=INF;
    if(SZ(odd)>=SZ(ev))
        op1=one_first();
    if(SZ(odd)<=SZ(ev))
        op2=zer_first();
    // cout<<op1<<" "<<op2<<'\n';
    int ans=min(op1,op2);
    cout<<ans<<'\n';
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}