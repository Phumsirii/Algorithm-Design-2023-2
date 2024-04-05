#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> datasN,datasS; //[R][C]
//datas[R][C]=true means we can visit
//visited is visited in North pole
vector<vector<bool>> visited,svisited;
queue<pair<int,int>> bfs,q; // row , col
vector<int> dx={-1,1,0,0},dy={0,0,-1,1};
int r,c,n,ans=0,ndata,wr,wc;
int main(){
    cin>>r>>c>>n;
    visited.resize(r+1,vector<bool> (c+1,false));
    datasN.resize (r+1,vector<bool> (c+1,false));
    datasS.resize (r+1,vector<bool> (c+1,false));
    svisited.resize(r+1,vector<bool> (c+1,false));
    for(int p=0;p<2;++p){
        for(int i=1;i<=r;++i){
            for(int j=1;j<=c;++j){
                cin>>ndata;
                if (p==0 && ndata==0) datasN[i][j]=true;
                else if(ndata==0) datasS[i][j]=true;
            }
        }
    }
    //iterate through all connected component in North Pole
    bfs.push(make_pair(1,1));
    while(!bfs.empty()){
        int row=bfs.front().first;
        int col=bfs.front().second;
        bfs.pop();
        if (!visited[row][col]){
            visited[row][col]=true;
            ++ans;
            //see all neighbors, push to queue if it's valid to visit
            for(int i=0;i<4;++i){
                int targetrow=row+dy[i],targetcol=col+dx[i];
                //skip if the neighbor can't be visited or out of range or is visited
                if (targetrow<=0 || targetrow>r || targetcol<=0 || targetcol>c || visited[targetrow][targetcol] || !datasN[targetrow][targetcol]) continue;
                bfs.push(make_pair(targetrow,targetcol));
            }
        }
    } //ans is now no of connected component from (1,1) in the northpole
    
    int ansforSouth=0;
    for(int i=0;i<n;++i){
        cin>>wr>>wc;
        if (visited[wr][wc] && !svisited[wr][wc]){ //new connected component of the Southpole, can be connected from the North
            q.push(make_pair(wr,wc));
            int tmp=1; //count connected component of (wr,wc) in the south pole
            svisited[wr][wc]=true;
            while(!q.empty()){
                int tmpr=q.front().first,tmpc=q.front().second;
                q.pop();
                //all neighbors of this node
                for(int j=0;j<4;++j){
                    int tmptargetr=tmpr+dx[j],tmptargetc=tmpc+dy[j];
                    if (tmptargetr<=0 || tmptargetr>r || tmptargetc<=0 || tmptargetc>c || svisited[tmptargetr][tmptargetc] || !datasS[tmptargetr][tmptargetc]) continue;
                    svisited[tmptargetr][tmptargetc]=true;
                    q.push(make_pair(tmptargetr,tmptargetc));
                    ++tmp;
                }
            }
            ansforSouth=max(ansforSouth,tmp); //max connected component in South pole may be changed
        }
    }

    cout<<ans+ansforSouth;
}