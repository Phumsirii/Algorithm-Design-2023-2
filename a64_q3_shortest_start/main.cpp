#include<bits/stdc++.h>
using namespace std;
//reverse direction
int n,m,k,goal,startp,a,b,w;
vector<bool> starts; //true if it's a starting point
vector<vector<pair<int,int>>> adj; //pair of cost and destination
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //pair of total cost and destination
vector<int> dist;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>k>>goal;
    starts.resize(n,false);
    dist.resize(n,1e9);
    for(int i=0;i<k;++i){
        cin>>startp;
        starts[startp]=true;
    }
    adj.resize(n);
    for(int i=0;i<m;++i){
        cin>>a>>b>>w;
        (adj[b]).push_back(make_pair(w,a));
    }
    //initialize all nodes from the goal
    for(auto x: adj[goal]){
        int &weight=x.first,&destination=x.second;
        pq.push(make_pair(weight,destination));
    }
    while(!pq.empty()){
        int totalcost =pq.top().first;
        int currentn=pq.top().second;
        pq.pop();
        //if totalcost exceed what we have done
        if (totalcost>dist[currentn]) continue;
        dist[currentn]=totalcost;
        //x is pair of cost and destination
        for(auto x: adj[currentn]){
            pq.push(make_pair(totalcost+x.first,x.second));
        }
    }
    int ans=1e9;
    for(int i=0;i<n;++i){
        if (starts[i]) ans=min(ans,dist[i]);
    }
    cout<<ans;
}