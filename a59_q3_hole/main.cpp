#include <bits/stdc++.h>
using namespace std;
//both are labelled with [x][y]
vector<vector<int>> dp(1001,vector<int> (1001,-1));
vector<vector<bool>> hasholes(1001,vector<bool> (1001,false));
int n,hx,hy,tmpx,tmpy;
int recur(int x,int y){
    cout<<x<<" "<<y<<"\n";
    //reaches edges of the area
    if (x==1 || x==1000 || y==1 || y==1000){
        if (hasholes[x][y]) return dp[x][y]=1;
        else return dp[x][y]=0;
    }
    if (dp[x][y]>=0) return dp[x][y];
    //try all 4 possible moves
    int c1=recur(x,y+1);
    int c2=recur(x+1,y);
    int c3=recur(x,y-1);
    int c4=recur(x-1,y);
    dp[x][y]=min({c1,c2,c3,c4});
    if (hasholes[x][y]) dp[x][y]++;
    return dp[x][y];
}
int main(){
    cin>>n>>hx>>hy;
    while(n--){
        cin>>tmpx>>tmpy;
        hasholes[tmpx][tmpy]=true;
    }
    cout<<recur(hx,hy);
}