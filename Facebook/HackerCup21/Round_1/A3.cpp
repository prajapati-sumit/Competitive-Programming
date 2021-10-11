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


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;



struct Node{
    char f;
    char l;
    int fi;
    int li;
    int n;
    int ans;

};
Node get_Node(char ch){
    Node res;
    res.n=1;
    if(ch=='F'){
        res.f='$';
        res.l='$';
        res.fi=0;
        res.li=0;
        res.ans=0;
    }
    else{
        res.f=ch;
        res.l=ch;
        res.fi=1;
        res.li=1;
        res.ans=0;
    }
    res.n=1;
    return res;

}
Node merge(Node A,Node B){

    Node res;
    if(A.f=='$'){
        res.f=B.f;
        res.fi=(A.n+B.fi)%MD;
    }
    else{
        res.f=A.f;
        res.fi=A.fi;
    }
    if(B.l=='$'){
        res.l=A.l;
        res.li=(B.n+A.li)%MD;
    }
    else{
        res.l=B.l;
        res.li=B.li;

    }
    
    res.n=(A.n+B.n)%MD;

    res.ans=(A.ans+B.ans)%MD;
    if(A.li!='$' && B.li!='$' && A.li!=B.fi){
        int x=(A.n+MD-A.li+1)%MD;
        int y=(B.n+MD-B.fi+1)%MD;
        res.ans=(res.ans+x*y)%MD;
    }
    return res;

}
void print(Node X){
    cout<<"{ ";
        cout<<"(X.f"<<" "<<X.f<<"),";
        cout<<"(X.l"<<" "<<X.l<<"),";
        cout<<"(X.fi"<<" "<<X.fi<<"),";
        cout<<"(X.li"<<" "<<X.li<<"),";
        cout<<"(X.ans"<<" "<<X.ans<<"),";
    cout<<"}\n";
}

void solve() {

    int n;
    cin>>n;
    char ch;
    cin>>ch;
    Node cur=get_Node(ch);
    print(cur);
    repe(i,n-1){
        cin>>ch;
        if(ch=='.'){
            cur=merge(cur,cur);
        }
        else
            cur=merge(cur,get_Node(ch));
        print(cur);
    }
    cout<<cur.ans<<"\n";


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