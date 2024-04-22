#include<bits/stdc++.h>
using namespace std;
vector<int> goals(8);
int n,m,tmpa,tmpb,tmpw;
vector<bool> visited,usededge;
//weight and destination
vector<vector<pair<int,int>>> adj;
//weightleft is weight to reach goals
bool recur( int it, int weightleft){
    if (weightleft==0) return true;
    //too large
    if (weightleft<0) return false;
    //to small
    int maxfromthis=0;
    for(int i=0;i<n;++i){
        if (!visited[i] && !adj[i].empty()) maxfromthis+=adj[i][0].first;
    }
    if (maxfromthis<weightleft) return false;
    //for all adj nodes
    for(pair<int,int> &x:adj[it]){
        if (visited[x.second]) continue;
        visited[x.second]=true;
        bool pass=recur(x.second,weightleft-x.first);
        visited[x.second]=false;
        if (pass) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<8;++i) cin>>goals[i];
    visited.resize(n,false);
    adj.resize(n);
    for(int i=0;i<m;++i){
        cin>>tmpa>>tmpb>>tmpw;
        adj[tmpa].push_back(make_pair(tmpw,tmpb));
        adj[tmpb].push_back(make_pair(tmpw,tmpa));
    }
    for(int i=0;i<n;++i) sort(adj[i].begin(),adj[i].end(),greater<pair<int,int>> ());
    for(int i=0;i<8;++i){
        bool pass=false;
        for(int j=0;j<n;++j){
            visited[j]=true;
            pass=recur(j,goals[i]);
            visited[j]=false;
            if (pass) break;
        }
        if (pass) cout<<"YES\n";
        else cout<<"NO\n";
    }
}