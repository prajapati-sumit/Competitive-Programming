// Kahn's Algorithm

const int MX=1e5+5;
int in_degree[MX];
vector<int>v[MX];
int n;
bool top_sort(vector<int>& ans){

    queue<int>Q;
    for(int i=1;i<=n;i++)
        if(in_degree[i]==0)
            Q.push(i);
    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        ans.push_back(cur);
        for(auto &el:v[cur]){
            in_degree[el]--;
            if(in_degree[el]==0)
                Q.push(el);
        }
    }
    return (int)ans.size()==n;

}