#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dimensions(n+1);
    for(int i=0;i<=n;++i) cin>>dimensions[i];
    vector<vector<int>> dp(n,vector<int> (n,0)); //store datas (minimum number of scalar multiplication from i to j, given i and j are row and column number respectively)
    //iterate to every starting column as the starting column
    for(int i=1;i<n;++i){
        //initialize iterator through the matrix diagonally
        int row=0,col=i;
        while(row<n &&col<n){ //diagonal iteration
            int newdata=1e+9;
            //iterate to find the minimum data for this cell
            for(int j=row;j<col;++j) newdata=min(newdata,dp[row][j]+dp[1+j][col]+dimensions[row]*dimensions[j+1]*dimensions[col+1]);
            dp[row++][col++]=newdata; //finish editing the data cell
        }
    }
    cout<<dp[0][n-1];
}