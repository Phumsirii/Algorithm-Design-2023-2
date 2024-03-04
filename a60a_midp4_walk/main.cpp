#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> done,forest;
int recur(int x,int y){
    if (x==0 || y==0) return -1000;
    if (x==1 && y==1) return forest[1][1];
    if (done[y][x]>0) return done[y][x];
    int newpath=max({recur(x-1,y)+forest[y][x],recur(x,y-1)+forest[y][x],recur(x-1,y-1)+2*forest[y][x]});
    done[y][x]=newpath;
    return newpath;
}
int main(){
    cin>>n>>m;
    forest.resize(n+1,vector<int> (m+1,0));
    done.resize(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) cin>>forest[i][j];
    }
    cout<<recur(m,n);
}