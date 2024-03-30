#include<bits/stdc++.h>
using namespace std;
int n,e,k,tmp1,tmp2,ans=1;
vector<vector<bool>> connection;
void bfs(int start){
    int count=1;
    vector<int> dist(n,-1);
    queue<int> q;
    q.push(start);
    dist[start]=0;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        //terminating condition : dist[current]==k
        if (dist[current]==k){
            ans=max(ans,count);
            return;
        }
        for(int i=0;i<n;++i){
            if (i!=current && connection[i][current] && dist[i]==-1){
                dist[i]=dist[current]+1;
                q.push(i);
                ++count;
            }
        }
    }
}
int main(){
    cin>>n>>e>>k;
    connection.resize(n,vector<bool> (n,false));
    for(int i=0;i<e;++i){
        cin>>tmp1>>tmp2;
        connection[tmp1][tmp2]=true;
        connection[tmp2][tmp1]=true;
    }
    for(int i=0;i<n;++i) bfs(i);
    cout<<ans;
}