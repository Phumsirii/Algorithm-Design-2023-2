#include <bits/stdc++.h>
using namespace std;
int n,e,k,tmp1,tmp2,ans=0;
vector<bool> visited;
queue<pair<int,int>> q; //destination and level
vector<vector<int>> adj;
int main(){
    cin>>n>>e>>k;
    visited.resize(n+1,false);
    adj.resize(n+1);
    for(int i=0;i<e;++i){
        cin>>tmp1>>tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    q.push(make_pair(0,0));
    visited[0]=true;
    while(!q.empty()){
        int dest=q.front().first;
        int level=q.front().second;
        if (level==k) ans++;
        for(int &x:adj[dest]){
            if (!visited[x] && level<k){
                visited[x]=true;
                q.push(make_pair(x,level+1));
            }
        }
        q.pop();
    }
    cout<<ans;
}