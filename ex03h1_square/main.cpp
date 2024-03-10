#include <bits/stdc++.h>
using namespace std;
int r,c,ans=0;
vector<vector<int>> datas,dp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>r>>c;
    vector<string> tmpdata(r);
    datas.resize(r,vector<int> (c)); dp.resize(r,vector<int> (c));
    //get all datas
    for(int i=0;i<r;++i){
        cin>>tmpdata[i];
    }
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if (tmpdata[i][j]=='1') datas[i][j]=1;
            else datas[i][j]=0;
        }
    }
    //these two loops are for initializing the first row and column
    for(int i=0;i<r;++i){
        ans=max(ans,datas[i][0]);
        dp[i][0]=datas[i][0];
    }
    for(int i=0;i<c;++i){
        ans=max(ans,datas[0][i]);
        dp[0][i]=datas[0][i];
    }
    //iterate through all data cell
    for(int i=1;i<r;++i){
        for(int j=1;j<c;++j){
            if (datas[i][j]==0){ //0 found, cannot be spanned
                dp[i][j]=0; continue;
            }
            else{ //1 found see if we can span it
                if (datas[i-1][j-1]==0){
                    dp[i][j]=1; 
                    ans=max(ans,1);
                }
                else{
                    bool failed=false;
                    int prevdim=dp[i-1][j-1];
                    for(int x=1;x<=prevdim;++x){
                        //check through all horizontal and vertical elements
                        if (datas[i-x][j]==0 || datas[i][j-x]==0){
                            dp[i][j]=x; 
                            ans=max(ans,x);
                            failed=true;
                            break;
                        }
                    }
                    if (!failed){
                        dp[i][j]=prevdim+1;
                        ans=max(ans,dp[i][j]);
                    }
                }
            }
        }
    }
    cout<<ans;
}