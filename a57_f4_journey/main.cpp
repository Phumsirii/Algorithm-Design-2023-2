#include<bits/stdc++.h>
using namespace std;
int n,ans=-1e9,maxtail=0;
vector<vector<int>> route;
vector<bool> colused;
vector<int> maxineachrow;
void recur(int step,int csum,int ctown,int maxleft){
    if (step<n-1){
        for(int i=1;i<n-1;++i){
            //see all next possible towns (must ignore travelling to the last town)
            if (!colused[i] && i!=ctown){
                colused[i]=true;
                //if the tail can be greater than ans
                if (maxleft-maxineachrow[ctown]+csum+route[ctown][i]>ans) recur(step+1,csum+route[ctown][i],i,maxleft-maxineachrow[ctown]);
                colused[i]=false;
            }
        }
    }else{
        ans=max(ans,csum+route[ctown][n-1]);
    }
}
int main(){
    cin>>n;
    route.resize(n,vector<int> (n));
    maxineachrow.resize(n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>route[i][j];
            maxineachrow[i]=max(maxineachrow[i],route[i][j]);
        }
        maxtail+=maxineachrow[i];
    }
    maxtail-=maxineachrow[n-1];
    colused.resize(n,false);
    recur(1,0,0,maxtail);
    cout<<ans;
}

