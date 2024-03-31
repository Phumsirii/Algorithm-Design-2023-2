#include <bits/stdc++.h>
using namespace std;
int w,n,e,s,n1,n2;
vector<vector<int>> dist;
int main(){
    cin>>n>>e>>s;
    dist.resize(n,vector<int>(n,1e9));
    while(e--){
        cin>>n1>>n2>>w;
        dist[n1][n2]=w;
    }
    for(int i=0;i<n;++i) dist[i][i]=0;
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
    for(int i=0;i<n;++i){
        if (dist[i][i]<0) {
            cout<<-1;
            return 0;
        }
    }
    for(int i=0;i<n;++i)cout<<dist[s][i]<<" ";
}