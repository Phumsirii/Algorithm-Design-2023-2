#include<bits/stdc++.h>
using namespace std;
int n,t=0,tmp,visitedcount=0;
vector<bool> visited;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //cost and destination
vector<vector<int>> datas; //store distances between all nodes 
//Prim's Algorithm
int main(){
    cin>>n;
    datas.resize(n,vector<int> (n,-1));
    visited.resize(n,false);
    //get all datas
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            cin>>tmp;
            datas[i][j]=tmp;
            datas[j][i]=tmp;
        }
    }
    //start the first node
    visited[0]=true;visitedcount++;
    for(int i=1;i<n;++i){
        pq.push(make_pair(datas[0][i],i));
    }
    while(visitedcount<n){
        int newdestination=pq.top().second,newcost=pq.top().first;
        pq.pop();
        //if the node is visited
        if (visited[newdestination]) continue;
        //if the node has never been visited, visit it
        visited[newdestination]=true;
        visitedcount++;
        //insert all new paths
        for(int i=0;i<n;++i){
            if (i!=newdestination && !visited[i]) pq.push(make_pair(datas[i][newdestination],i));
        }
        t+=newcost;
    }
    cout<<t;
}