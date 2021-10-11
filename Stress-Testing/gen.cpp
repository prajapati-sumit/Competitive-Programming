// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n)            for(int i=0;i<n;i++)
#define int                 long long
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define pb                  push_back
#define all(a)              a.begin(),a.end()
#define mtrand(a,b)         uniform_int_distribution<int>(a, b)(rng)


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD=1e9+7;
const int INF=1e6;

int rand(int a, int b) {
    if(a>b)
        return 0;
    return a + rand() % (b - a + 1);
}
int randprime(){
    vector<int>primes{2,3,5,7,11,13,17,19,23};
    int ind=rand(0,(int)primes.size()-1);
    return primes[ind];
}
void print_array(int n,int L=1,int R=10){
    repe(i,n)
        cout<<rand(L,R)<<" \n"[i==n];
}
void print_queries(int q,int n){
    while(q--){   
        int ty=(rand()%3)+1;
        cout<<ty<<" ";
        if(ty==1){
            int l=rand(1,n);
            int r=rand(l,n);
            int x=rand(1,9);
            cout<<l<<" "<<r<<" "<<x<<"\n";
        }
        else if(ty==2){
            int l=rand(1,n);
            int r=rand(l,n);
            int x=rand(1,9);
            cout<<l<<" "<<r<<" "<<x<<"\n";
        }
        else{
            int l=rand(1,n);
            int r=rand(l,n);
            cout<<l<<" "<<r<<"\n";
        }
    }
}
void print_string(int n){
    rep(i,n)
        cout<<char('a'+rand(0,25));
    cout<<'\n';
}

int32_t main(int32_t argc, char* argv[]) {
    srand(atoi(argv[1]));
    int t=10;
    cout<<t<<"\n";
    while(t--){
        int n = mtrand(1, INF);
        int d = mtrand(0,9);
        cout<<n<<" "<<d<<"\n";
    }
    
    
        
}