#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> table(501,vector<int> (501,1e9));
int n,m;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        table[a][b]=table[b][a]=w;
    }
    //Floyd-Warshall
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k) table[j][k]=table[k][j]=min(table[k][j],table[j][i]+table[i][k]);
        }
    }
    int ans=0;
    for(int i=0;i<n;++i){
        int localmax=0;
        for(int j=0;j<n;++j){
            if (i!=j) localmax=max(localmax,table[i][j]);
        } 
        ans=max(ans,localmax);
    }
    cout<<ans;
}