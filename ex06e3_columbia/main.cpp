#include <bits/stdc++.h>
using namespace std;
int r,c;
vector<vector<int>> datas,dist; //[y][x]
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> dijk; //pair of time and pair of coordinate (y,x)
int main(){
    cin>>r>>c;
    datas.resize(r,vector<int> (c)); dist.resize(r,vector<int> (c,1e9));
    for(int i=0;i<r;++i){ //y coordinate
        for(int j=0;j<c;++j) cin>>datas[i][j];
    }
    dijk.push(make_pair(0,make_pair(0,0)));
    dist[0][0]=0;
    while(!dijk.empty()){
        int t=dijk.top().first;
        int cy=dijk.top().second.first;
        int cx=dijk.top().second.second;
        dijk.pop();
        //top
        if (cy-1>=0 && dist[cy-1][cx]>dist[cy][cx]+datas[cy-1][cx]){
            //replace the smaller value
            dist[cy-1][cx]=dist[cy][cx]+datas[cy-1][cx];
            //push the set of smaller value
            dijk.push(make_pair(dist[cy-1][cx],make_pair(cy-1,cx)));
        }
        //bottom
        if (cy+1<r && dist[cy+1][cx]>dist[cy][cx]+datas[cy+1][cx]){
            //replace the smaller value
            dist[cy+1][cx]=dist[cy][cx]+datas[cy+1][cx];
            //push the set of smaller value
            dijk.push(make_pair(dist[cy+1][cx],make_pair(cy+1,cx)));
        }
        //left
        if (cx-1>=0 && dist[cy][cx-1]>dist[cy][cx]+datas[cy][cx-1]){
            //replace the smaller value
            dist[cy][cx-1]=dist[cy][cx]+datas[cy][cx-1];
            //push the set of smaller value
            dijk.push(make_pair(dist[cy][cx-1],make_pair(cy,cx-1)));
        }
        //right
        if (cx+1<c && dist[cy][cx+1]>dist[cy][cx]+datas[cy][cx+1]){
            //replace the smaller value
            dist[cy][cx+1]=dist[cy][cx]+datas[cy][cx+1];
            //push the set of smaller value
            dijk.push(make_pair(dist[cy][cx+1],make_pair(cy,cx+1)));
        }
    }
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j) cout<<dist[i][j]<<" ";
        cout<<"\n";
    }
}