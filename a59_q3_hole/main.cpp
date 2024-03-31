#include <bits/stdc++.h>
using namespace std;
int n,hx,hy,tx,ty;
vector<vector<bool>> holes(1001,vector<bool> (1001,false)); //[x][y] for location
vector<vector<int>> overall(1001,vector<int> (1001,1e9)); //distance from house to each cell
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; //{distance,{x,y}}
vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
int main(){
    cin>>n>>hx>>hy;
    while(n--){
        cin>>tx>>ty;
        holes[tx][ty]=true;
    }
    pq.push(make_pair(0,make_pair(hx,hy)));
    while(!pq.empty()){
        int dist=pq.top().first,cx=pq.top().second.first,cy=pq.top().second.second;
        pq.pop();
        //the edge is reached
        if (cx==1 || cx==1000 || cy==1 || cy==1000){
            cout<<dist;
            return 0;
        }
        //if the new data is better than the previous, edit it and its neighbors
        if (dist<overall[cx][cy]){
            overall[cx][cy]=dist;
            //iterate through all neighbors
            for(int i=0;i<4;++i){
                //if the neighbor has holes, distance to reach that is distance to this + 1 
                if (holes[cx+dx[i]][cy+dy[i]]) pq.push(make_pair(dist+1,make_pair(cx+dx[i],cy+dy[i])));
                else pq.push(make_pair(dist,make_pair(cx+dx[i],cy+dy[i])));
            }
        }
    }
}