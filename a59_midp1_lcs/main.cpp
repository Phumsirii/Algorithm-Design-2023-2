#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> done;
string x,y;
vector<int> result; //indices of x (in form of 1...n)
void recur(int currentx,int currenty){
    if (currentx==0 || currenty==0 || done[currentx][currenty]==0) return;
    if (x[currentx-1]==y[currenty-1]){
        result.push_back(currentx-1);
        return recur(currentx-1,currenty-1);
    }
    if (done[currentx-1][currenty]>=done[currentx][currenty-1]) return recur(currentx-1,currenty);
    return recur(currentx,currenty-1);
}
int main(){
    string inp;
    cin>>n>>m;
    x.resize(n+1);y.resize(m+1);done.resize(n+1,vector<int> (m+1));
    cin>>x>>y;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j) cin>>done[i][j];
    }
    recur(n,m);
    reverse(result.begin(),result.end());
    for(int i:result) cout<<x[i];
}