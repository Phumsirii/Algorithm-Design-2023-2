#include<bits/stdc++.h>
using namespace std;
int n,e,s,a,b,c;
class edge{
    public:
    int node1;
    int node2;
    int weight;
    edge(){};
};
vector<edge> edges;
vector<int> distances;
int main(){
    cin>>n>>e>>s;
    edges.resize(e);
    distances.resize(n,1e9);
    for(int i=0;i<e;++i){
        cin>>a>>b>>c;
        edges[i].node1=a;
        edges[i].node2=b;
        edges[i].weight=c;
    }
    distances[s]=0;
    for(int i=0;i<n-1;++i){
        for(edge &ed:edges) distances[ed.node2]=min(distances[ed.node2],distances[ed.node1]+ed.weight);
    }
    bool hasnegcy=false;
    for(edge &ed:edges){
        if (distances[ed.node2]>distances[ed.node1]+ed.weight){
            cout<<-1;
            return 0;
        }
    }
    for(int &dis:distances) cout<<dis<<" ";
}