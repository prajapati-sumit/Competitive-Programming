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
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
int n,a,b,c;
vector<int>v[MX];
int dist[3][MX];
bool vis[MX];

void bfs(int node,int which){
    dist[which][node]=0;
    vis[node]=true;
    queue<int>Q;
    Q.push(node);
    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        for(auto el:v[cur]){
            if(!vis[el]){
                Q.push(el);
                vis[el]=true;
                dist[which][el]=dist[which][cur]+1;
            }
        }
    }
}
 
void solve(){
 
    cin>>n>>a>>b>>c;
    int x,y;
    repe(i,n-1)
        cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
    memset(dist,0,sizeof(dist));
    bfs(a,0);
    memset(vis,0,sizeof(vis));
    bfs(b,1);
    memset(vis,0,sizeof(vis));
    bfs(c,2);
    int ans=MD,indx=-1;
    
  
    repe(i,n){
        bool flag1=(dist[0][i]&1)&(dist[1][i]&1)&(dist[2][i]&1);
        bool flag2=(dist[0][i]%2==0)&(dist[1][i]%2==0)&(dist[2][i]%2==0);
        if(!flag1 && !flag2)
            break;
        int val=max(dist[0][i],max(dist[1][i],dist[2][i]));
        if(ans>val){
            ans=val;
            indx=i;
        }
    }
    if(indx==-1)
        cout<<"-1\n";
    else cout<<indx<<" "<<ans<<'\n';
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
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
 
    return 0;
 
}
