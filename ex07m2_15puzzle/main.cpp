#include<bits/stdc++.h>
using namespace std;
//   0
//3  x  1
//   2
vector<int> moveassistancex={0,1,0,-1},moveassistancey={-1,0,1,0};
vector<int> cantmove={2,3,0,1};
class bfsdata{
    public:
        int heuristic,moved,x,y,prevmove;
        vector<vector<int>> currentcell;
        bfsdata(int heuristic,int moved,vector<vector<int>> currentdata,int prevmove,int x,int y){
            this->heuristic=heuristic;
            this->moved=moved;
            this->x=x;
            this->y=y;
            this->prevmove=prevmove;
            this->currentcell=currentdata;
        }
};
class bfsComparator {
public:
    bool operator()(const bfsdata& a, const bfsdata& b) const {
        return a.heuristic>b.heuristic;
    }
};
vector<vector<int>> cell(4,vector<int> (4));
vector<int> expectedx={3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2},expectedy={3,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3};
vector<vector<int>> expected={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
priority_queue<bfsdata,vector<bfsdata>,bfsComparator> bfs;
set<vector<vector<int>>> visited;
int startx,starty;
int main(){
    int heucnt=0;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            cin>>cell[i][j];
            if (cell[i][j]==0) startx=j,starty=i;
            heucnt+=abs(i-expectedy[cell[i][j]]);
            heucnt+=abs(j-expectedx[cell[i][j]]);
        }
    }
    bfs.push(bfsdata(heucnt,0,cell,-1,startx,starty));
    while(!bfs.empty()){
        if (bfs.top().currentcell==expected){
            cout<<bfs.top().moved;
            return 0;
        }
        vector<vector<int>> currentdata=bfs.top().currentcell;
        if (visited.find(currentdata)!=visited.end()) continue;
        int movedcnt=bfs.top().moved;
        int cx=bfs.top().x;
        int cy=bfs.top().y;
        int premove=bfs.top().prevmove;
        //see all moves
        for(int i=0;i<4;++i){
            //not moving backward
            if (i!=-1 && cantmove[premove]==i) continue;
            int newx=cx+moveassistancex[i],newy=cy+moveassistancey[i];
            if (newx<0 || newx>3 || newy<0 || newy>3) continue;
            swap(currentdata[cy][cx],currentdata[newy][newx]);
            int errcnt=0;
            for(int k=0;k<4;++k){
                for(int j=0;j<4;++j){
                    errcnt+=abs(k-expectedy[currentdata[k][j]]);
                    errcnt+=abs(j-expectedx[currentdata[k][j]]);
                }
            }
            bfs.push(bfsdata(errcnt+movedcnt+1,movedcnt+1,currentdata,i,newx,newy));
            swap(currentdata[cy][cx],currentdata[newy][newx]);
        }
        bfs.pop();
    }
}
