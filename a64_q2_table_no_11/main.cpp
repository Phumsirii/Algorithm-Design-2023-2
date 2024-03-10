#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> dp(2,vector<int> (2));
    dp[1][0]=1;dp[1][1]=1;
    for(int i=2;i<=n;++i){
        dp[i%2][0]=(dp[(i-1)%2][0]+dp[(i-1)%2][1]*2)%100000007;
        dp[i%2][1]=(dp[(i-1)%2][0]+dp[(i-1)%2][1])%100000007;
    }
    cout<<(dp[n%2][0]+dp[n%2][1]*2)%100000007;
}