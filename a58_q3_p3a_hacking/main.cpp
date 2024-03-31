#include <bits/stdc++.h>
using namespace std;
vector<int> hacktime,initiallyhacked;
vector<bool> hacked; //true if hacked[i] is hacked
int n,m,k,ini,hackcnt,tmp1,tmp2;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//time hacked and server address
vector<vector<int>> adj; //adjacency list
int main(){
    cin>>n>>m>>k;
    hacked.resize(n,false);
    hacktime.resize(n);
    initiallyhacked.resize(k);
    adj.resize(n);
    //get all servers initially hacked
    for(int i=0;i<k;++i) cin>>initiallyhacked[i];
    //get hacktime of each element
    for(int i=0;i<n;++i) cin>>hacktime[i];
    while(m--){
        cin>>tmp1>>tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    //initialize the hacked server
    for(int x:initiallyhacked) pq.push(make_pair(hacktime[x],x));
    while(!pq.empty()){
        int t=pq.top().first;
        int server=pq.top().second;
        pq.pop();
        if (!hacked[server]){
            hacked[server]=true;
            hackcnt++;
            //if all servers are hacked
            if (hackcnt==n){
                cout<<t;
                return 0;
            }
            //see all neighbors
            for(int x:adj[server]){
                //if the neighbor is not hacked, insert it in pq
                if (!hacked[x]) pq.push(make_pair(t+hacktime[x],x));
            }
        }
    }
}