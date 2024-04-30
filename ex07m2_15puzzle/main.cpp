#include <bits/stdc++.h>
using namespace std;
//  0
//3 x 1
//  2
vector<int> oppomove={2,3,0,1,4},movassistx={0,1,0,-1},movassisty={-1,0,1,0};
class state{
    public:
    vector<vector<int>> board;
    int stepsdone;
    int prevmove;
    int errcnt;
    int x,y;
    //constructor
    state(){};
    state(int stdo,int prevm,vector<vector<int>> b){
        stepsdone=stdo;
        board=b;
        prevmove=prevm;
        errcnt=0;
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                //[y][x]
                int tmpdata=b[i][j];
                if (tmpdata==0){
                    x=j,y=i;
                    continue;
                }
                errcnt+=(abs(i-(tmpdata-1)/4)+abs(j-(tmpdata-1)%4));
            }
        }
    }
    //consider ones with less err first
    bool operator<(const state &other)const{
        return errcnt+stepsdone>other.errcnt+other.stepsdone;
    }
};
priority_queue<state> pq;
int ans=1e9;
int main(){
    vector<vector<int>> firstboard(4,vector<int>(4));
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j) cin>>firstboard[i][j];
    }
    state firstdata(0,4,firstboard);
    pq.push(firstdata);
    while(!pq.empty()){
        state candistate=pq.top();
        pq.pop();
        //cannot be better than ans
        if (candistate.errcnt+candistate.stepsdone>=ans) continue;
        //see all possible moves from this state
        for(int i=0;i<4;++i){
            //avoid repeating same state
            if (i==oppomove[candistate.prevmove]) continue;
            int newx=candistate.x+movassistx[i],newy=candistate.y+movassisty[i];
            //invalid move
            if (newx>=4 || newx<0 || newy>3 || newy<0) continue;
            vector<vector<int>> newboard=candistate.board;
            swap(newboard[candistate.y][candistate.x],newboard[newy][newx]);
            state newstate(candistate.stepsdone+1,i,newboard);
            //if the new state is perfect
            if (newstate.errcnt==0){
                ans=min(ans,newstate.stepsdone);
            } //if new state can create better ans
            else if(newstate.errcnt+newstate.stepsdone<ans){
                pq.push(newstate);
            }
            swap(newboard[candistate.y][candistate.x],newboard[newy][newx]);
        }
    }
    cout<<ans;
}
