#include <bits/stdc++.h>
using namespace std;
int v,e,n1,n2,ans;
vector<int> node_group;
int getgroup(int x){
    if (node_group[x]==-1) return x;
    return node_group[x]=getgroup(node_group[x]);
}
int main(){
    cin>>v>>e;
    ans=v;
    node_group.resize(v+1,-1);
    for(int i=0;i<e;++i){
        cin>>n1>>n2;
        int g1=getgroup(n1),g2=getgroup(n2);
        //the elements are from different group, now joined by the edge
        if (g1!=g2){
            node_group[g2]=g1;
            ans--;
        }
    }
    cout<<ans;
}