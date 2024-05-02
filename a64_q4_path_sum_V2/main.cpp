#include<bits/stdc++.h>
using namespace std;
int goals[8];
int n,m,t1,t2,tw;
// weight and neighbour
vector<vector<pair<int,int>>> adjlist;
vector<bool> visited;
int gettail(){
    int result=0;
    for(int i=0;i<n;++i){
        if (!visited[i]) result+=adjlist[i][0].first;
    }
    return result;
}
bool recur(int currentleft,int currentnode){
    if (currentleft<0) return false;
    if (currentleft==0) return true;
    if (gettail()<currentleft) return false;
    for(pair<int,int> &x:adjlist[currentnode]){
        if (!visited[x.second] && x.first<=currentleft){
            visited[x.second]=true;
            if (recur(currentleft-x.first,x.second)){
                visited[x.second]=false;
                return true;
            }
            visited[x.second]=false;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<8;++i) cin>>goals[i];
    adjlist.resize(n);
    visited.resize(n,false);
    for(int i=0;i<m;++i){
        cin>>t1>>t2>>tw;
        adjlist[t1].push_back(make_pair(tw,t2));
        adjlist[t2].push_back(make_pair(tw,t1));
    }
    for(int i=0;i<n;++i) sort(adjlist[i].rbegin(),adjlist[i].rend());
    for(int i=0;i<8;++i){
        visited=vector<bool> (n,false);
        bool success=false;
        for(int j=0;j<n;++j){
            visited[j]=true;
            if (recur(goals[i],j)){
                success=true;
                visited[j]=false;
                break;
            }
            visited[j]=false;
        }
        if (success) cout<<"YES\n";
        else cout<<"NO\n";
    }
}