#include <bits/stdc++.h>
using namespace std;
int n,m,q,connectedcom,a,b,w,question;
vector<int> group;
vector<int> result;
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> edges; //w,a,b
int getgroup(int n){
    if (group[n]==-1) return n;
    return group[n]=getgroup(group[n]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>q;
    result.resize(n+1);
    group.resize(n,-1);
    connectedcom=n;
    result[n]=0;
    while(m--){
        cin>>a>>b>>w;
        edges.push(make_pair(w,make_pair(a,b)));
    }
    while(!edges.empty()){
        //weight of this edge
        int cw=edges.top().first;
        //vertices of this edge
        int ca=edges.top().second.first,cb=edges.top().second.second;
        edges.pop();
        int g1=getgroup(ca),g2=getgroup(cb);
        if (g1!=g2){
            result[--connectedcom]=cw;
            group[g1]=g2; //Union
        }
    }
    while(q--){
        cin>>question;
        cout<<result[question]<<"\n";
    }
}