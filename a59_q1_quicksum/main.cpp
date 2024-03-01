#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,dt;
    cin>>n>>m>>k;
    vector<vector<int>> matrix(n+1);
    for(int i=0;i<=n;++i){
        vector<int> row(m+1,0);
        matrix[i]=row;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>dt;
            matrix[i][j]=matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1]+dt;
        }
    }
    while(k--){
        int lx,ly,rx,ry;
        cin>>lx>>ly>>rx>>ry;
        ++rx;++ry;
        cout<<matrix[rx][ry]-matrix[lx][ry]-matrix[rx][ly]+matrix[lx][ly]<<"\n";
    }
}