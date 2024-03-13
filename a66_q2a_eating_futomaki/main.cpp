#include<bits/stdc++.h>
using namespace std;
vector<int> futo;
int n;
vector<vector<int>> dp;
int recur(int start,int stop){
    if (start==stop-1) return dp[start][stop]=max(futo[start],futo[stop]);
    if (dp[start][stop]>0) return dp[start][stop];
    int newdata=0;
    //slice two one the right
    newdata=max(newdata,recur(start,stop-2)+max(futo[stop],futo[stop-1]));
    //slice two on the left
    newdata=max(newdata,recur(start+2,stop)+max(futo[start],futo[start+1]));
    //slice 1 each side
    newdata=max(newdata,recur(start+1,stop-1)+max(futo[stop],futo[start]));
    return dp[start][stop]=newdata;
}
int main(){
    cin>>n;
    futo.resize(n);
    dp.resize(n,vector<int> (n,0));
    for(int i=0;i<n;++i) cin>>futo[i];
    cout<<recur(0,n-1);
}
