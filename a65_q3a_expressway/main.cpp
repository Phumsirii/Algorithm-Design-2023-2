#include<bits/stdc++.h>
using namespace std;
int n,inf=1e9,k;
vector<vector<int>> path;
int main(){
    cin>>n;
    path.resize(n+1,vector<int>(n+1,inf));
    cin>>path[1][2];
    //get all new routes
    for(int i=3;i<=n;++i){
        cin>>k;
        while(k--){
            int newroute,newprice;
            cin>>newroute>>newprice;
            path[i][newroute]=path[newroute][i]=newprice;
        }
    }
    for(int k=3;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j) path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
        }
        cout<<path[1][2]<<" ";
    }
}