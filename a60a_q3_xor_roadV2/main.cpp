#include<bits/stdc++.h>
using namespace std;
int n;
size_t ans=0;
vector<size_t> townid;
vector<int> group;
class road{
    public:
    int town1,town2;
    size_t beauty;
    road(){};
    road(int t1,int t2,size_t b){
        town1=t1;
        town2=t2;
        beauty=b;
    }
    bool operator<(const road &other) const{
        return beauty<other.beauty;
    }
};
int getgroup(int cn){
    if (group[cn]==-1) return cn;
    return group[cn]=getgroup(group[cn]);
}
void unionn(int t1,int t2){
    group[getgroup(t1)]=getgroup(t2);
}
priority_queue<road> pq;
int main(){
    cin>>n;
    townid.resize(n);
    group.resize(n,-1);
    for(int i=0;i<n;++i){
        cin>>townid[i];
        for(int j=0;j<i;++j){
            size_t newdata=townid[i]^townid[j];
            pq.push(road(i,j,newdata));
        }
    }
    while(!pq.empty()){
        //The towns are in different connected component
        if (getgroup(pq.top().town1)!=getgroup(pq.top().town2)){
            unionn(pq.top().town1,pq.top().town2);
            ans+=pq.top().beauty;
        }
        //They are already in the same connected component, don't include this road
        pq.pop();
    }
    cout<<ans;
}