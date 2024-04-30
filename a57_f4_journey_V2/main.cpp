#include<bits/stdc++.h>
using namespace std;
int n,ans=-1e9,tail=0;
vector<vector<int>> routes(20,vector<int> (20));
vector<bool> visited(20,false);
vector<int> maxinrow(20);
void recur(int no,int currentsum,int tailleft,int visitedcnt){
    if (visitedcnt==n-1){
        ans=max(ans,currentsum+routes[no][n-1]);
        return;
    }
    if (currentsum+tailleft<=ans) return;
    for(int i=0;i<n-1;++i){
        if (i!=no && !visited[i]){
            visited[i]=true;
            recur(i,currentsum+routes[no][i],tailleft-maxinrow[no],visitedcnt+1);
            visited[i]=false;
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        int localmax=-1e9;
        for(int j=0;j<n;++j){
            cin>>routes[i][j];
            if (i!=j && routes[i][j]>localmax) localmax=routes[i][j];
        }
        tail+=localmax;
        maxinrow[i]=localmax;
    }
    visited[0]=true;
    recur(0,0,tail-maxinrow[n-1],1);
    cout<<ans;
}