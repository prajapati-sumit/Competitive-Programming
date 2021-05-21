#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;

#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define PI 3.1415926535897932384626
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
const int INF=1e9+18;
auto time0 = curtime;
 
 
 
 
 
int n,x;
int a[MX];
void execute(){
    queue<int>q[32];
    rep(i,32)
        repe(j,n)
            if(a[j]&(1<<i))
                q[i].push(j);
  
    for(int i=1;i<=(n-1);i++){
    
        int sz=log2(a[i]);
        for(int bit=sz;bit>=0;bit--){
            int dd=(1<<bit);
            if(a[i]==0)
                break;
            if(a[i]&dd){
                
                if(x<=0){
                   return;
                }
                //cout<<a[i]<<" "<<bit<<'\n';
                if(q[bit].size()==1){
                    int fir=q[bit].front();
                    q[bit].pop();
                    a[fir]^=dd;
                    int sec=n;
                    a[sec]^=dd;
                    q[bit].push(sec);
                    

                }
                else{
                    int fir=q[bit].front();
                    q[bit].pop();
                    int sec=q[bit].front();
                    q[bit].pop();
                    a[fir]^=dd;
                    a[sec]^=dd;
                    

                }
                x--;
            }
        }
        

    }
}

void solve(){
    cin>>n>>x;


    repe(i,n)
        cin>>a[i];
    execute();
    if(x&1 && n==2){
        a[n]^=1;
        a[n-1]^=1;
    }
    repe(i,n)
        cout<<a[i]<<" ";
    cout<<'\n';
}
 
 int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
     #else
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
          cout.tie(NULL);
     #endif

    srand(time(0));	

    time0 = curtime;
    int t=1;
    cin>>t;
    while(t--)
        solve();
 
    return 0;
 
}
