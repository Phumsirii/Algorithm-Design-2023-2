#include <bits/stdc++.h>
using namespace std;
int n,k,on;
vector<int> dp;
vector<vector<int>> operation;
int recur(int n){
    if (n<=0) return 0;
    if (dp[n]>=0) return dp[n];
    int newdata=0,newdataoperationsize=operation[n].size();
    for(int i=0;i<newdataoperationsize;++i){
        newdata=(newdata+recur(n-operation[n][i]))%32717;
    }
    return dp[n]=newdata;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    dp.resize(n+1,-1);
    operation.resize(n+1);
    for(int i=1;i<=k;++i) cin>>dp[i];
    for(int i=k+1;i<=n;++i){
        cin>>on;
        operation[i].resize(on);
        for(int j=0;j<on;++j) cin>>operation[i][j];
    }
    for(int i=1;i<=n;++i) cout<<recur(i)<<" ";
}   