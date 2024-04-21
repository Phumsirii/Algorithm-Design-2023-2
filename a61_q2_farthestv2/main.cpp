#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>  chart;
vector<int> bellford;
//initial,final node
vector<pair<int,int>> edges;
int n;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    chart.resize(n,vector<int> (n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>chart[i][j];
            if (chart[i][j]==-1) chart[i][j]=1e9;
            else edges.push_back(make_pair(i,j));
        }
    }
    bellford.resize(n,1e9);
    bellford[0]=0;
    for(int i=0;i<n-1;++i){
        //for all edges
        for(auto &x:edges) bellford[x.second]=min(bellford[x.second],bellford[x.first]+chart[x.first][x.second]);
    }
    int candi=*max_element(bellford.begin(),bellford.end());
    if (candi==1e9) cout<<-1;
    else cout<<candi;
}