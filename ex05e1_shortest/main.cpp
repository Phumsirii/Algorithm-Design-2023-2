#include <bits/stdc++.h>
using namespace std;
int r,c;
vector<vector<int>> dist;
vector<vector<bool>> path;
queue<std::pair<int,int>> q;
int main(){
    cin>>r>>c;
    dist.resize(r,vector<int> (c,-1));
    path.resize(r,vector<bool> (c));
    for(int i=0;i<r;++i){
        string tmp;
        cin>>tmp;
        for(int j=0;j<c;++j){
            if (tmp[j]=='.') path[i][j]=true;
            else path[i][j]=false;
        }
    }
    q.push(make_pair(0,0));
    dist[0][0]=0;
    while(q.size()>0){
        std::pair<int,int> current=q.front();
        q.pop();
        vector<std::pair<int,int>> candi={make_pair(current.first,current.second-1),make_pair(current.first,current.second+1),make_pair(current.first-1,current.second),make_pair(current.first+1,current.second)};
        for(std::pair<int,int> ca:candi){
            if (ca.first>=0 && ca.first<r && ca.second>=0 && ca.second<c){
                if (path[ca.first][ca.second] && dist[ca.first][ca.second]==-1){
                    dist[ca.first][ca.second]=dist[current.first][current.second]+1;
                    q.push(ca);
                }
            }
        }
    }
    cout<<dist[r-1][c-1];
}