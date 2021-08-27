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
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

struct query {
    int idx, l, r;
} Q[MX];
const int nax=26,B=400;
int n, q,freq[nax],ans[MX];
string s;
int gl_ans=0;

void add_element(int x){
    gl_ans+=(s[x]-'a'+1);
    // freq[s[x]-'a']++;
}
void remove_element(int x){
    // freq[s[x]-'a']--;
    gl_ans-=(s[x]-'a'+1);
}
void MO_S() {

    for (int L = 0, R = -1, i = 1; i <= q; i++) {
        while(R<Q[i].r)
            add_element(++R);
        while(L>Q[i].l)
            add_element(--L);
        while(R>Q[i].r)
            remove_element(R--);
        while(L<Q[i].l)
            remove_element(L++);
        // cout<<Q[i].l<<" "<<Q[i].r<<'\n';
        // rep(i,5)
        //     cout<<freq[i]<<" ";
        // cout<<'\n';
        ans[Q[i].idx]=gl_ans;
    }
}

 
void solve(){
  
    cin>>n>>q;
    cin>>s;
    repe(i, q){
        cin >> Q[i].l >> Q[i].r ;
        Q[i].idx = i;
        Q[i].l--;
        Q[i].r--;
    }

    sort(Q + 1, Q + q + 1, [&](auto p, auto q) {
        if (p.l / B == q.l / B)
            return p.r < q.r;
        return p.l < q.l;
    });
    MO_S();
    repe(i, q)
        cout << ans[i] << "\n";
    
  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}