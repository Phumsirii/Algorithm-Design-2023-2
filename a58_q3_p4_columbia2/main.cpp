#include <bits/stdc++.h>
using namespace std;
int r,c;
vector<vector<int>> fees;
vector<vector<vector<int>>> dijk; //each [r][c] contains 3 elements, cost if 0,1,2 tears are left the last element store the best
priority_queue<vector<int>> pq; //cost,coordinate r,coordinate c,tears left
vector<int> dx={-1,1,0,0},dy={0,0,-1,1},dxs{2,-2,0,0,1,1,1,-1,-1,-1,0,0},dys={0,0,2,-2,1,0,-1,1,0,-1,1,-1};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>r>>c;
    fees.resize(r,vector<int> (c));
    dijk.resize(r,vector<vector<int>> (c,vector<int> (4,1e9)));
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j) cin>>fees[i][j];
    }
    dijk[0][0][0]=dijk[0][0][1]=dijk[0][0][2]=dijk[0][0][3]=0;
    //initialize first move
    pq.push({0,0,0,2});
    while(!pq.empty()){
        //cost,coordinate r,coordinate c,tears left
        vector<int> current=pq.top();
        pq.pop();
        int currentr=current[1],currentc=current[2],currentleft=current[3],currentcost=current[0];
        if (currentcost>dijk[currentr][currentc][currentleft]) continue;
        //if the incoming is better than the prev
        //normal move
        for(int i=0;i<4;++i){
            //in case it comes over edge
            if (currentc+dx[i]<0 || currentc+dx[i]>=c || currentr+dy[i]<0 || currentr+dy[i]>=r) continue;
            if (currentcost+fees[currentr+dy[i]][currentc+dx[i]]<dijk[currentr+dy[i]][currentc+dx[i]][currentleft]){
                dijk[currentr+dy[i]][currentc+dx[i]][currentleft]=currentcost+fees[currentr+dy[i]][currentc+dx[i]];
                //update the best one for currentr+dy[i] and currentc+dx[i]
                dijk[currentr+dy[i]][currentc+dx[i]][3]=min(dijk[currentr+dy[i]][currentc+dx[i]][currentleft],dijk[currentr+dy[i]][currentc+dx[i]][3]);
                pq.push({currentcost+fees[currentr+dy[i]][currentc+dx[i]],currentr+dy[i],currentc+dx[i],currentleft});
            }
        }
        //special case
        if (currentleft>0){
            for(int i=0;i<12;++i){
                //in case it comes over edge
                if (currentc+dxs[i]<0 || currentc+dxs[i]>=c || currentr+dys[i]<0 || currentr+dys[i]>=r) continue;
                if (currentcost<dijk[currentr+dys[i]][currentc+dxs[i]][currentleft-1]){
                    dijk[currentr+dys[i]][currentc+dxs[i]][currentleft-1]=currentcost;
                    //update the best one for currentr+dy[i] and currentc+dx[i]
                    dijk[currentr+dys[i]][currentc+dxs[i]][3]=min(dijk[currentr+dys[i]][currentc+dxs[i]][currentleft-1],dijk[currentr+dys[i]][currentc+dxs[i]][3]);
                    pq.push({currentcost,currentr+dys[i],currentc+dxs[i],currentleft-1});
                }
            }
        }
    }
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j) cout<<dijk[i][j][3]<<" ";
        cout<<"\n";
    }
}