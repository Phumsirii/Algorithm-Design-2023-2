#include<bits/stdc++.h>
using namespace std;
//[x][y]
vector<vector<bool>> hashole(1001,vector<bool> (1001,false));
class state{
    public:
    int stepsdone,x,y;
    state(){};
    state(int steps,int cx,int cy){
        stepsdone=steps;
        x=cx;
        y=cy;
    }
    bool operator<(const state &other)const{
        return stepsdone>other.stepsdone;
    }
};
priority_queue<state> dijk;
int a,b,n,tx,ty;
vector<int> dx={1,-1,0,0},dy={0,0,-1,1};
vector<vector<int>> done(1001,vector<int> (1001,1e9));
int main(){
    cin>>n>>a>>b;
    while(n--){
        cin>>tx>>ty;
        hashole[tx][ty]=true;
    }
    dijk.push(state(0,a,b));
    while(!dijk.empty()){
        int tmpx=dijk.top().x,tmpy=dijk.top().y,tmpstp=dijk.top().stepsdone;
        if (tmpx==1 || tmpy==1 || tmpx==1000 || tmpy==1000){
            cout<<tmpstp;
            return 0;
        }
        dijk.pop();
        if (done[tmpx][tmpy]<=tmpstp) continue;
        done[tmpx][tmpy]=tmpstp;
        for(int i=0;i<4;++i){
            int newx=tmpx+dx[i];
            int newy=tmpy+dy[i];
            if (newx<=0 || newy<=0 || newx>1000 || newy>1000) continue;
            if (hashole[newx][newy] && tmpstp>=done[newx][newy]) continue;
            else if (tmpstp>=done[newx][newy]) continue;
            if (hashole[newx][newy]) dijk.push(state(tmpstp+1,newx,newy));
            else dijk.push(state(tmpstp,newx,newy));
        }
    }
}