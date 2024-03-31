#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long ans=0;
vector<int> vec; //number of each data
vector<int> group; //show group of each nodes 
priority_queue<pair<unsigned long long,pair<int,int>>> pq; //beauty of road i to j {beauty,{i,j}}
//Kruskal's Algorithm
int getgroup(int n){
    if(group[n]==-1) return n;
    return group[n]=getgroup(group[n]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    group.resize(n,-1);
    vec.resize(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
        for(int j=0;j<i;++j){
            unsigned long long newdata=(vec[i]^vec[j]);
            pq.push(make_pair(newdata,make_pair(i,j)));
        }
    }
    while(!pq.empty()){
        unsigned long long beauty=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        pq.pop();
        int g1=getgroup(i);
        int g2=getgroup(j);
        //if the element is from the same group
        if (g1==g2) continue;
        //this edge each chosen as g1 and g2 are from different groups
        group[g1]=g2;
        ans+=beauty;
    }
    cout<<ans;
}