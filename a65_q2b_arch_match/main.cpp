#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
vector<int> datas;
vector<vector<int>> dp;
int recur(int start,int stop){
    if (start<0 || stop>=n || start>=stop) return 0;
    if (dp[start][stop]>=0) return dp[start][stop];
    if (start==stop-1) return dp[start][stop]=max(datas[start]*datas[stop],0);
    dp[start][stop]=max({0,recur(start+1,stop-1),recur(start+1,stop-1)+datas[start]*datas[stop]});
    for(int i=start;i<stop;++i){
        dp[start][stop]=max(dp[start][stop],recur(start,i)+recur(i+1,stop));
    }
    return dp[start][stop];
}
int main(){
    cin>>n;
    datas.resize(n);dp.resize(n,vector<int> (n,-1));
    for(int i=0;i<n;++i) cin>>datas[i];
    cout<<recur(0,n-1);
}