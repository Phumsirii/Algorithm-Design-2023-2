#include<bits/stdc++.h>
using namespace std;
int n,m,k,tmp1,tmp2,ans=0;
vector<bool> visited;
vector<int> beauty,daily_fire;
vector<vector<int>> wind;
void recur(int x){
    if (visited[x]) return;
    visited[x]=true;
    //clear itself
    ans-=beauty[x];
    beauty[x]=0;
    //if it does not have a child, terminate the recursion
    if (wind[x].empty()) return;
    // else repeat the recursion with all its descendant
    else{
        vector<int> tmp=wind[x];
        //iterate through all its descendant
        for(int x:tmp) recur(x);
    }
}
int main(){
    cin>>n>>m>>k;
    beauty.resize(n);daily_fire.resize(k);wind.resize(n);visited.resize(n,false);
    for(int i=0;i<n;++i){
        cin>>beauty[i];
        ans+=beauty[i];
    }
    for(int i=0;i<k;++i) cin>>daily_fire[i];
    for(int i=0;i<m;++i){
        cin>>tmp1>>tmp2;
        wind[tmp1].push_back(tmp2);
    }
    for(int i=0;i<k;++i){
        int firetoday=daily_fire[i];
        recur(firetoday);
        cout<<ans<<" ";
    }
}