#include<bits/stdc++.h>
using namespace std;
int n,m,q,g1,g2,dis,ques;
//distance and initial and final point
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> kruskal;
vector<int> group,result;
int getgroup(int x){
    if (group[x]==-1) return x;
    return group[x]=getgroup(group[x]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>q;
    group.resize(n,-1);
    result.resize(n+1);
    while(m--){
        cin>>g1>>g2>>dis;
        kruskal.push(make_pair(dis,make_pair(g1,g2)));
    }
    int connectedcomp=n;
    result[n]=kruskal.top().first;
    while(!kruskal.empty()){
            int distanc=kruskal.top().first;
            int n1=kruskal.top().second.first;
            int n2=kruskal.top().second.second;
            int g1=getgroup(n1),g2=getgroup(n2);
            kruskal.pop();
            if (g1==g2) continue;
            group[g1]=g2;
            result[--connectedcomp]=distanc;
        }
    while(q--){
        cin>>ques;
        cout<<result[ques]<<"\n";
    }
}