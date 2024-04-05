#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<vector<int>> adj;
vector<int> previ;
vector<bool> visited;
queue<int> bfs;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}