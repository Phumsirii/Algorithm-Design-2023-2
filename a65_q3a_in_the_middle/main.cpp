#include<bits/stdc++.h>
using namespace std;
int n,tmp1,tmp2,k;
vector<int> t(3);
vector<vector<int>> adj; //adjacency list
vector<vector<int>> result; //[person][town]
int main(){
    cin>>n>>t[0]>>t[1]>>t[2];
    adj.resize(n+1);
    result.resize(3,vector<int> (n+1,1e9));
    for(int i=1;i<=n;++i){
        cin>>k;
        adj[i].resize(k);
        for(int j=0;j<k;++j){
            cin>>adj[i][j];
        }
    }
    //iterate from town 1 to 3 as starting point to fill the table
    for(int i=0;i<3;++i){
        vector<int> visited(n+1,false);
        queue<pair<int,int>> q; //level and destination
        visited[t[i]]=true; //set the starting point
        q.push(make_pair(0,t[i]));
        while(!q.empty()){
            int town=q.front().second;
            int dist=q.front().first;
            q.pop();
            result[i][town]=dist;
            //for all adjacent towns
            for(int x: adj[town]){
                if (!visited[x]){
                    visited[x]=true;
                    q.push(make_pair(dist+1,x));
                }
            }
        }
    }
    int ans=1e9;
    //brute force all destination
    for(int i=1;i<=n;++i){
        ans=min(ans,max({result[0][i],result[1][i],result[2][i]}));
    }
    cout<<ans;
}