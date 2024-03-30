#include <bits/stdc++.h>
using namespace std;
int r,c,t,ans=0;
vector<vector<int>> datas;
queue<pair<int,pair<int,int>>> q; //time and coordinates y and x
int main(){
    cin>>r>>c>>t;
    datas.resize(r,vector<int> (c));
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cin>>datas[i][j];
            if (datas[i][j]==1){
                q.push(make_pair(0,make_pair(i,j)));
                ++ans;
            }
        }
    }
    while(!q.empty()){
        int time=q.front().first;
        pair<int,int> coo=q.front().second;
        q.pop();
        //left
        //if valid location and datas[y][x]==0
        if (coo.second-1>=0 && datas[coo.first][coo.second-1]==0){
            if (time+1<t) q.push(make_pair(time+1,make_pair(coo.first,coo.second-1)));
            datas[coo.first][coo.second-1]=1;
            ++ans;
        }
        //top
        if (coo.first+1<r && datas[coo.first+1][coo.second]==0){
            if (time+1<t) q.push(make_pair(time+1,make_pair(coo.first+1,coo.second)));
            datas[coo.first+1][coo.second]=1;
            ++ans;
        }
        //bottom
        if (coo.first-1>=0 && datas[coo.first-1][coo.second]==0){
            if (time+1<t) q.push(make_pair(time+1,make_pair(coo.first-1,coo.second)));
            datas[coo.first-1][coo.second]=1;
            ++ans;
        }
        //right
        if (coo.second+1<c && datas[coo.first][coo.second+1]==0){
            if (time+1<t) q.push(make_pair(time+1,make_pair(coo.first,coo.second+1)));
            datas[coo.first][coo.second+1]=1;
            ++ans;
        }
    }
    cout<<ans;
}