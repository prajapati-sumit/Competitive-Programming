//Coded by Sumit Prajapati

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int MD=1e9+7;
#define MX 100005
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)

ll n,d;
ll a[MX];
map<int,int>mp;

void solve(){
    
    mp.clear();
    memset(a,0,sizeof(a));

    
    cin>>n>>d;
    repe(i,n)
        cin>>a[i],mp[a[i]]++;
    ll ans;
    if(d==2){
        ans=1;
        for(auto x:mp){
            if(x.second>=2){
                ans=0;
                break;
            }

        }
        
    }
    else if( d==3){
        ans=2;
        ll max_count=0,val2=MD;
        for(auto x:mp){
            if(max_count<x.second)
                    max_count=x.second,val2=x.first;
            if(x.second>=3)
            {
                ans=0;
                break;
            }

        }

        if(ans!=0){
            if(max_count==2){   
                for(auto x : mp){
                    if(x.first>val2){
                        ans=1;
                        break;
                    }
                }

            }
            else{
                for(auto x:mp){
                    auto it =mp.find(2*x.first);
                    if(it!=mp.end()){
                        ans=1;
                        break;
                    }
                    }

            }
        }
    }
    cout<<ans<<'\n';


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    cin>>t;
    for(ll tt=1;tt<=t;tt++){
        cout<<"Case #"<<tt<<": ";
       solve();
    }

}

