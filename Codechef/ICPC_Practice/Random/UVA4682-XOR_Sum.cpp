// AUTHOR: SUMIT PRAJAPATI      
#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define TESTCASES 1

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
struct Node{
    bool val;
    Node* left_child;
    Node* right_child;

}; 
Node* Root=new Node;
void insert(int x){
    Node* cur=Root;
    for(int i=31;i>=0;i--){
        if(x&(1<<i)){
            if(cur->right_child==NULL){
                Node* temp=new Node;
                temp->val=1;
                cur->right_child=temp;
            }
            cur=cur->right_child;
        }
        else{
            if(cur->left_child==NULL){
                Node* temp=new Node;
                temp->val=0;
                cur->left_child=temp;
            }
            cur=cur->left_child;
            
        }
    }
}
 
int find_his_max(int x){
    int ans=0;
    Node* cur=Root;
    for(int i=31;i>=0;i--){

        if(x&(1<<i)){
            if(x==4){
                // cout<<1<<" ";
            }
            if(cur->left_child==NULL){
                if(cur->right_child==NULL)
                    break;
                else
                    cur=cur->right_child;
                // cout<<"went right\n";
            }
            else{
                ans|=(1<<i);
                cur=cur->left_child;
                // cout<<"went left\n";
            }
        }
        else{
            // cout<<0<<"\n";
            if(cur->right_child==NULL){
                if(cur->left_child==NULL)
                    break;
                else
                    cur=cur->left_child;
                // cout<<"went left\n";
            }
            else{
                ans|=(1<<i);
                cur=cur->right_child;
                // cout<<"went right\n";
            }
            
        }
        
    }
    return ans;
}
void display(Node* root)
{
    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
    if (root==NULL) 
    {   cout<<"--------------\n";
        return;
    }
    cout<<root->val<<"\n";
    display(root->left_child);
    display(root->right_child);
    
}
void solve(){
  
    int n;
    cin>>n;
    int a[n+1];
    a[0]=0;
    Root->val=0;
    Root->left_child=NULL;
    Root->right_child=NULL;
    insert(0);
    repe(i,n){
        cin>>a[i];
        a[i]^=a[i-1];
        insert(a[i]);
    }   
    int best_so_far=0; 
    repe(i,n){
        int cur_best=find_his_max(a[i]);
        // cout<<a[i]<<" "<<find_his_max(a[i])<<"\n";
        best_so_far=max(best_so_far,cur_best);
    }
    cout<<best_so_far<<'\n';

 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}