#include<bits/stdc++.h>
using namespace std;
int r,c,r1,r2,c1,c2; //initial and final coordinate
vector<vector<int>> datas; // [r][c] is the fees to [r][c]
vector<int> drodd={-1,1,0,0,-1,-1},dcodd={0,0,1,-1,1,-1},dreven={-1,1,0,0,1,1},dceven={0,0,1,-1,1,-1};
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;//distance and coordinate [r][c]
vector<vector<int>> dist; //[r][c]
int main(){
    cin>>r>>c;
    dist.resize(r+1,vector<int> (c+1,1e9));
    datas.resize(r+1,vector<int> (c+1));
    cin>>c1>>r1>>c2>>r2;
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j) cin>>datas[i][j];
    }
    pq.push(make_pair(datas[r1][c1],make_pair(r1,c1)));
    dist[r1][c1]=datas[r1][c1];
    while(!pq.empty()){
        int currentr=pq.top().second.first;
        int currentc=pq.top().second.second;
        int currentdis=pq.top().first;
        pq.pop();
        if (dist[currentr][currentc]<currentdis) continue;
        vector<int> tmpdr=drodd;
        vector<int> tmpdc=dcodd;
        //see if it's an odd or even col
        if (currentc%2==0){
            tmpdr=dreven;
            tmpdc=dceven;
        }
        //see all adj cells
        for(int i=0;i<6;++i){
            int targetr=currentr+tmpdr[i];
            int targetc=currentc+tmpdc[i];
            if (targetr<=0 || targetc<=0 || targetr>r || targetc>c) continue;
            //better case found
            if (dist[targetr][targetc]>currentdis+datas[targetr][targetc]){
                dist[targetr][targetc]=currentdis+datas[targetr][targetc];
                pq.push(make_pair(dist[targetr][targetc],make_pair(targetr,targetc)));
            }
        }
    }
    cout<<dist[r2][c2];
}
