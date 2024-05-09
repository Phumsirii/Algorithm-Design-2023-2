#include <bits/stdc++.h>
using namespace std;
int n,m,t1,t2,ans=0,currentstart;
vector<int> values;
vector<bool> visited;
vector<vector<int>> adj;
void dfs(int no){
    visited[no]=true;
    ans=max(ans,values[no]-values[currentstart]);
    for(int &x:adj[no]){
        if (visited[x]) continue;
        dfs(x);
    }
}
int main(){
    cin>>n>>m;
    values.resize(n);
    adj.resize(n);
    for(int i=0;i<n;++i) cin>>values[i];
    for(int i=0;i<m;++i){
        cin>>t1>>t2;
        adj[t1].push_back(t2);
    }
    for(int i=0;i<n;++i){
        visited=vector<bool> (n,false);
        currentstart=i;
        dfs(i);
    }
    cout<<ans;
}