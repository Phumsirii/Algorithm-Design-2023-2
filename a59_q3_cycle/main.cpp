#include <bits/stdc++.h>
using namespace std;
int n,tmp1,tmp2,ans;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> previ;
//expect to return a number in the loop
int loopdetector(int x,int parent){
    if(visited[x]) return x;
    visited[x]=true;
    previ[x]=parent;
    vector<int> tmp=adj[x];
    for(int i:tmp){
        if (i!=parent){
            if (loopdetector(i,x)!=-1){
                ans++;
                return i;
            }
        }
    }
    //if no loop found, return -1
    return -1;
}
int main(){
    cin>>n;
    adj.resize(n);
    visited.resize(n,false);
    previ.resize(n,-1);
    for(int i=0;i<n;++i){
        cin>>tmp1>>tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }  
    for(int i=0;i<n;++i){
        //for all nodes not visited, do the recursion
        if (!visited[i]){
            loopdetector(i,-1);
        }
    }
    
    cout<<ans;
}