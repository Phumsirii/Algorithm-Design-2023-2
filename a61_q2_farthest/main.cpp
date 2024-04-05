#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> bellford;
vector<pair<int,int>> edges;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    adj.resize(n,vector<int> (n));
    //n-1 rows, n columns
    bellford.resize(n,1e9);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>adj[i][j];
            if (adj[i][j]>0) edges.push_back(make_pair(i,j));
        }
    }
    bellford[0]=0;
    for(int i=0;i<n-1;++i){
        for(auto x: edges){
            int a=x.first,b=x.second;
            if (bellford[b]>bellford[a]+adj[a][b]) bellford[b]=bellford[a]+adj[a][b];
        }
    }
    int ans=-1;
    for(int i=0;i<n;++i) ans=max(ans,bellford[i]);
    if (ans==1e9) ans=-1;
    cout<<ans;
}