#include<bits/stdc++.h>
using namespace std;
int v,e,ans=0,tmp1,tmp2;
vector<vector<int>> adj;
vector<bool> visited;
//check linearity
bool check(int x,int parent){
    if(visited[x]) return false;
    visited[x]=true;
    vector<int> &next=adj[x];
    //if degree is greater than 2
    if (next.size()>2) return false;
    for(int i:next){
        //found a loop
        if (visited[i] && i!=parent) return false;
        if (i!=parent && !check(i,x)) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>v>>e;
    adj.resize(v);
    visited.resize(v,false);
    while(e--){
        cin>>tmp1>>tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    for(int i=0;i<v;++i){
        //the visited are already in a connected component
        if (!visited[i] && check(i,-1))ans++;
    }
    cout<<ans;
}