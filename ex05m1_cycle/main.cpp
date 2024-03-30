#include<bits/stdc++.h>
using namespace std;
int N,v,e,tmp1,tmp2;
vector<vector<int>> adj;
vector<bool> visited;
bool check(int s,int parent){
    if (visited[s]) return true;
    visited[s]=true;
    for(int a:adj[s]){
        if (a!=parent && check(a,s)) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>N;
    while(N--){
        //no. of vertices and edges of a graph
        cin>>v>>e;
        adj=vector<vector<int>> (v);
        visited=vector<bool> (v,false);
        for(int i=0;i<e;++i){
            cin>>tmp1>>tmp2;
            adj[tmp1].push_back(tmp2);
            adj[tmp2].push_back(tmp1);
        }
        bool done=false;
        for(int i=0;i<v;++i){
            // not visited, loops found
            if (visited[i]==false && check(i,-1)){
                cout<<"YES\n";
                done=true;
                break;
            }
        }
        if (!done) cout<<"NO\n";
    }
}