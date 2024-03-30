#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj,bellford;
vector<pair<int,int>> edges;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    adj.resize(n,vector<int> (n));
    //n-1 rows, n columns
    bellford.resize(n-1,vector<int> (n,1e9));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>adj[i][j];
            if (adj[i][j]>0) edges.push_back(make_pair(i,j));
        }
    }
    bellford[0][0]=0;
    for(int i=1;i<n-1;++i){
        for(int j=0;j<n;++j) bellford[i][j]=bellford[i-1][j];
        for(pair<int,int> x :edges){
            bellford[i][x.second]=min(bellford[i][x.second],bellford[i-1][x.first]+adj[x.first][x.second]);
        }
    }
    int ans=-1;
    for(int i=0;i<n;++i) ans=max(ans,bellford[n-2][i]);
    if (ans==1e9) ans=-1;
    cout<<ans;
}